open Ppxlib
open Ast_helper

module Env = struct
  let level = "RES_LOG"
  let logger = "RES_LOGGER"
  let only = "RES_LOG_ONLY"
end

module Delimiter = struct
  let key_val = '='
  let entries = ','
end

module Level = struct
  type t =
    | Trace
    | Debug
    | Info
    | Warn
    | Error

  let from_string =
    function
    | "*"
    | "trace" -> Some(Trace)
    | "debug" -> Some(Debug)
    | "info" -> Some(Info)
    | "warn"
    | "warning" -> Some(Warn)
    | "error" -> Some(Error)
    | "off" -> None
    | _ as x -> failwith ("Invalid log level: " ^ x);
end

module Fn = struct
  type t =
    | Trace
    | Trace1
    | Trace2
    | Trace3
    | Trace4
    | Trace5
    | Trace6
    | Trace7
    | Debug
    | Debug1
    | Debug2
    | Debug3
    | Debug4
    | Debug5
    | Debug6
    | Debug7
    | Info
    | Info1
    | Info2
    | Info3
    | Info4
    | Info5
    | Info6
    | Info7
    | Warn
    | Warn1
    | Warn2
    | Warn3
    | Warn4
    | Warn5
    | Warn6
    | Warn7
    | Error
    | Error1
    | Error2
    | Error3
    | Error4
    | Error5
    | Error6
    | Error7

  let to_string =
    function
    | Trace  -> "trace"
    | Trace1 -> "trace1"
    | Trace2 -> "trace2"
    | Trace3 -> "trace3"
    | Trace4 -> "trace4"
    | Trace5 -> "trace5"
    | Trace6 -> "trace6"
    | Trace7 -> "trace7"
    | Debug  -> "debug"
    | Debug1 -> "debug1"
    | Debug2 -> "debug2"
    | Debug3 -> "debug3"
    | Debug4 -> "debug4"
    | Debug5 -> "debug5"
    | Debug6 -> "debug6"
    | Debug7 -> "debug7"
    | Info   -> "info"
    | Info1  -> "info1"
    | Info2  -> "info2"
    | Info3  -> "info3"
    | Info4  -> "info4"
    | Info5  -> "info5"
    | Info6  -> "info6"
    | Info7  -> "info7"
    | Warn   -> "warn"
    | Warn1  -> "warn1"
    | Warn2  -> "warn2"
    | Warn3  -> "warn3"
    | Warn4  -> "warn4"
    | Warn5  -> "warn5"
    | Warn6  -> "warn6"
    | Warn7  -> "warn7"
    | Error  -> "error"
    | Error1 -> "error1"
    | Error2 -> "error2"
    | Error3 -> "error3"
    | Error4 -> "error4"
    | Error5 -> "error5"
    | Error6 -> "error6"
    | Error7 -> "error7"
end

module LibArg = struct
  let box: string option ref = ref None

  let set x = box := Some x
  let reset () = box := None

  let key = "--lib"
  let spec = Arg.String set
  let doc = "<name> Library name"
end

module Lib = struct
  let from_args () =
    if Sys.argv |> Array.length > 1
    then
      match Sys.argv.(1) |> String.split_on_char Delimiter.key_val with
      | "--lib"::lib::[] -> Some lib
      | _ -> None
    else
      None
end

let level =
  let default = Level.Warn in
  let lib = Lib.from_args () in

  match Env.level |> Sys.getenv with
  | exception Not_found ->
    (
      match lib with
      | Some _ -> None
      | None -> Some default
    )
  | _ as raw_env_entries ->
    let entries = raw_env_entries |> String.split_on_char Delimiter.entries in
    match (entries, lib) with
    | ([], _) -> failwith ("Empty value of environment variable " ^ Env.level)
    | ((level::[] | level::_), None) -> level |> Level.from_string
    | (entries, Some lib) ->
      entries |>
        (
          List.fold_left
            (
              fun res entry ->
                match res with
                | Some res -> Some res
                | None ->
                 match entry |> String.split_on_char Delimiter.key_val with
                 | lib'::level::[] when lib' = lib -> level |> Level.from_string
                 | _ -> None
            )
            None
        )

let logger =
  let default = "ReScriptLogger.Browser" in

  let rec build ?lid xs =
    match (lid, xs) with
    | (None, x::xs) -> xs |> build ~lid: (Lident x)
    | (Some lid, x::xs) -> xs |> build ~lid: (Ldot (lid, x))
    | (Some lid, []) -> lid
    | (None, []) -> failwith "Empty logger" in

  let parse x = x |> String.split_on_char '.' |> build in

  match Env.logger |> Sys.getenv with
  | "" -> default |> parse
  | exception Not_found -> default |> parse
  | _ as x -> x |> parse

let only: string list list option =
  match Env.only |> Sys.getenv with
  | "" -> None
  | exception Not_found -> None
  | _ as x ->
    Some (
      x
      |> String.split_on_char ','
      |> List.map (String.split_on_char '.')
    )

let rec should_log path only =
  match (path, only) with
  | (_, []) -> true
  | ([], _::_) -> false
  | (p::path, o::only) ->
    if o <> p
    then false
    else should_log path only

let should_log ~only path =
  let path =
    path
    |> Code_path.fully_qualified_path
    |> String.split_on_char '.' in
  let finder = path |> should_log in
  match only |> List.find_opt finder with
  | Some _ -> true
  | None -> false

module Ast = struct
  let rec list ?expr xs =
    match (expr, xs) with
    | (None, []) ->
      Exp.construct
        {txt = Lident "[]"; loc = !default_loc}
        None
    | (Some expr, []) ->
      Exp.construct
        {txt = Lident "::"; loc = !default_loc}
        (Some expr)
    | (None, x::xs) ->
      xs |> (
        list
          ~expr:
            (Exp.tuple [
              Exp.constant (Const.string x);
              Exp.construct
                {txt = Lident "[]"; loc = !default_loc}
                None
            ])
      )
    | (Some expr, x::xs) ->
      xs |> (
        list
          ~expr:
            (Exp.tuple [
              Exp.constant (Const.string x);
              Exp.construct
                {txt = Lident "::"; loc = !default_loc}
                (Some expr)
            ])
      )

  let module_arg cp =
    Exp.record
      [
        (
          {txt = Lident "rootModule"; loc = !default_loc},
          Exp.constant (Const.string (cp |> Code_path.main_module_name))
        );
        (
          {txt = Lident "subModulePath"; loc = !default_loc},
          cp |> Code_path.submodule_path |> List.rev |> list
        );
        (
          {txt = Lident "value"; loc = !default_loc},
          match cp |> Code_path.value with
          | Some value ->
            Exp.construct
              {txt = Lident "Some"; loc = !default_loc}
              (Some (Exp.constant (Const.string value)))
          | None ->
            Exp.construct
              {txt = Lident "None"; loc = !default_loc}
              None
        );
        (
          {txt = Lident "fullPath"; loc = !default_loc},
          Exp.constant (Const.string (cp |> Code_path.fully_qualified_path))
        );
      ]
      None

  let logger fn =
    Exp.ident {txt = Ldot (logger, fn |> Fn.to_string); loc = !default_loc}

  let log fn cp x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
      ]

  let log1 fn cp x1 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
      ]

  let log2 fn cp x1 x2 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
      ]

  let log3 fn cp x1 x2 x3 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
        (Nolabel, x3);
      ]

  let log4 fn cp x1 x2 x3 x4 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
        (Nolabel, x3);
        (Nolabel, x4);
      ]

  let log5 fn cp x1 x2 x3 x4 x5 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
        (Nolabel, x3);
        (Nolabel, x4);
        (Nolabel, x5);
      ]

  let log6 fn cp x1 x2 x3 x4 x5 x6 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
        (Nolabel, x3);
        (Nolabel, x4);
        (Nolabel, x5);
        (Nolabel, x6);
      ]

  let log7 fn cp x1 x2 x3 x4 x5 x6 x7 x =
    Exp.apply
      (fn |> logger)
      [
        (Nolabel, cp |> module_arg);
        (Nolabel, x);
        (Nolabel, x1);
        (Nolabel, x2);
        (Nolabel, x3);
        (Nolabel, x4);
        (Nolabel, x5);
        (Nolabel, x6);
        (Nolabel, x7);
      ]

  let nothing =
    Exp.construct
      {txt = Lident "()"; loc = !default_loc}
      None
end

module LogExt = struct
  open Ast

  let transform
    ~ext_level: (ext_level: Level.t)
    ~env_level: (env_level: Level.t option)
    ~context: (context: Expansion_context.Extension.t)
    (payload: payload)
    =
      let cp = context |> Expansion_context.Extension.code_path in
      match only with
      | Some only when not (cp |> should_log ~only) -> nothing
      | Some _
      | None ->
        match payload with
        | PStr({pstr_desc = Pstr_eval (x, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log Trace cp
            | (Debug, Some (Trace | Debug))                       -> x |> log Debug cp
            | (Info,  Some (Trace | Debug | Info))                -> x |> log Info  cp
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log Warn  cp
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log Error cp
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log1 Trace1 cp x1
            | (Debug, Some (Trace | Debug))                       -> x |> log1 Debug1 cp x1
            | (Info,  Some (Trace | Debug | Info))                -> x |> log1 Info1  cp x1
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log1 Warn1  cp x1
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log1 Error1 cp x1
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log2 Trace2 cp x1 x2
            | (Debug, Some (Trace | Debug))                       -> x |> log2 Debug2 cp x1 x2
            | (Info,  Some (Trace | Debug | Info))                -> x |> log2 Info2  cp x1 x2
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log2 Warn2  cp x1 x2
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log2 Error2 cp x1 x2
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::
            {pstr_desc = Pstr_eval (x3, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log3 Trace3 cp x1 x2 x3
            | (Debug, Some (Trace | Debug))                       -> x |> log3 Debug3 cp x1 x2 x3
            | (Info,  Some (Trace | Debug | Info))                -> x |> log3 Info3  cp x1 x2 x3
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log3 Warn3  cp x1 x2 x3
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log3 Error3 cp x1 x2 x3
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::
            {pstr_desc = Pstr_eval (x3, _)}::
            {pstr_desc = Pstr_eval (x4, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log4 Trace4 cp x1 x2 x3 x4
            | (Debug, Some (Trace | Debug))                       -> x |> log4 Debug4 cp x1 x2 x3 x4
            | (Info,  Some (Trace | Debug | Info))                -> x |> log4 Info4  cp x1 x2 x3 x4
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log4 Warn4  cp x1 x2 x3 x4
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log4 Error4 cp x1 x2 x3 x4
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::
            {pstr_desc = Pstr_eval (x3, _)}::
            {pstr_desc = Pstr_eval (x4, _)}::
            {pstr_desc = Pstr_eval (x5, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log5 Trace5 cp x1 x2 x3 x4 x5
            | (Debug, Some (Trace | Debug))                       -> x |> log5 Debug5 cp x1 x2 x3 x4 x5
            | (Info,  Some (Trace | Debug | Info))                -> x |> log5 Info5  cp x1 x2 x3 x4 x5
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log5 Warn5  cp x1 x2 x3 x4 x5
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log5 Error5 cp x1 x2 x3 x4 x5
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::
            {pstr_desc = Pstr_eval (x3, _)}::
            {pstr_desc = Pstr_eval (x4, _)}::
            {pstr_desc = Pstr_eval (x5, _)}::
            {pstr_desc = Pstr_eval (x6, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log6 Trace6 cp x1 x2 x3 x4 x5 x6
            | (Debug, Some (Trace | Debug))                       -> x |> log6 Debug6 cp x1 x2 x3 x4 x5 x6
            | (Info,  Some (Trace | Debug | Info))                -> x |> log6 Info6  cp x1 x2 x3 x4 x5 x6
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log6 Warn6  cp x1 x2 x3 x4 x5 x6
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log6 Error6 cp x1 x2 x3 x4 x5 x6
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | PStr(
            {pstr_desc = Pstr_eval (x,  _)}::
            {pstr_desc = Pstr_eval (x1, _)}::
            {pstr_desc = Pstr_eval (x2, _)}::
            {pstr_desc = Pstr_eval (x3, _)}::
            {pstr_desc = Pstr_eval (x4, _)}::
            {pstr_desc = Pstr_eval (x5, _)}::
            {pstr_desc = Pstr_eval (x6, _)}::
            {pstr_desc = Pstr_eval (x7, _)}::[]) ->
          (
            match (ext_level, env_level) with
            | (Trace, Some (Trace))                               -> x |> log7 Trace7 cp x1 x2 x3 x4 x5 x6 x7
            | (Debug, Some (Trace | Debug))                       -> x |> log7 Debug7 cp x1 x2 x3 x4 x5 x6 x7
            | (Info,  Some (Trace | Debug | Info))                -> x |> log7 Info7  cp x1 x2 x3 x4 x5 x6 x7
            | (Warn,  Some (Trace | Debug | Info | Warn))         -> x |> log7 Warn7  cp x1 x2 x3 x4 x5 x6 x7
            | (Error, Some (Trace | Debug | Info | Warn | Error)) -> x |> log7 Error7 cp x1 x2 x3 x4 x5 x6 x7
            | ((Trace | Debug | Info | Warn | Error), _)          -> nothing
          )

        | _ ->
          Location.raise_errorf
            ~loc: (context |> Expansion_context.Extension.extension_point_loc)
            "Too many arguments"

  let trace =
    Context_free.Rule.extension
      (
        Extension.V3.declare
        "log.trace"
        Extension.Context.expression
        Ast_pattern.__
        (
          fun ~ctxt ->
            transform
              ~ext_level: Trace
              ~env_level: level
              ~context: ctxt
        )
      )

  let debug =
    Context_free.Rule.extension
      (
        Extension.V3.declare
        "log.debug"
        Extension.Context.expression
        Ast_pattern.__
        (
          fun ~ctxt ->
            transform
              ~ext_level: Debug
              ~env_level: level
              ~context: ctxt
        )
      )

  let info =
    Context_free.Rule.extension
      (
        Extension.V3.declare
        "log.info"
        Extension.Context.expression
        Ast_pattern.__
        (
          fun ~ctxt ->
            transform
              ~ext_level: Info
              ~env_level: level
              ~context: ctxt
        )
      )

  let warn =
    Context_free.Rule.extension
      (
        Extension.V3.declare
        "log.warn"
        Extension.Context.expression
        Ast_pattern.__
        (
          fun ~ctxt ->
            transform
              ~ext_level: Warn
              ~env_level: level
              ~context: ctxt
        )
      )

  let error =
    Context_free.Rule.extension
      (
        Extension.V3.declare
        "log.error"
        Extension.Context.expression
        Ast_pattern.__
        (
          fun ~ctxt ->
            transform
              ~ext_level: Error
              ~env_level: level
              ~context: ctxt
        )
      )
end

module LogAttr = struct
  open Ast

  let attr =
    Attribute.declare
      "log"
      Attribute.Context.expression
      (
        T
          (
            fun ctx loc x k ->
              match x with
              | PStr [] ->
                ctx.matched <- ctx.matched + 1;
                None |> k
              | PStr(
                  {
                    pstr_desc =
                      Pstr_eval(
                        {pexp_desc = Pexp_constant (Pconst_string (x, _loc, _))},
                        _
                      )
                  }::[]) ->
                ctx.matched <- ctx.matched + 1;
                Some x |> k
              | _ -> Location.raise_errorf ~loc "Expected string"
          )
      )
      (fun x -> x)

  let format ns ctx tag =
    match ns with
    | None ->
      (
        match ctx with
        | `WithoutPayload -> Exp.constant (Pconst_string (tag, !default_loc, None))
        | `WithPayload -> Exp.constant (Pconst_string (tag ^ " with payload", !default_loc, None))
        | `WithNotLoggedPayload -> Exp.constant (Pconst_string (tag ^ " with payload (not logged)", !default_loc, None))
      )
    | Some ns ->
      let __ = "::" in
      match ctx with
      | `WithoutPayload -> Exp.constant (Pconst_string (ns ^ __ ^ tag, !default_loc, None))
      | `WithPayload -> Exp.constant (Pconst_string (ns ^ __ ^ tag ^ " with payload", !default_loc, None))
      | `WithNotLoggedPayload -> Exp.constant (Pconst_string (ns ^ __ ^ tag ^ " with payload (not logged)", !default_loc, None))

  let payload x =
    Exp.tuple
      [
        Exp.constant (Pconst_string (x, !default_loc, None));
        Exp.ident {txt = Lident x; loc = !default_loc};
      ]

  let transform
    ~env_level: (env_level: Level.t option)
    ~namespace: (namespace: string option)
    ~context: (context: Expansion_context.Base.t)
    (expr: expression)
    =
      (* TODO: Use Base getters once ppxlib is updated *)
      let context =
        Expansion_context.Extension.make
          ~extension_point_loc: expr.pexp_loc
          ~base: context
          () in
      let cp = context |> Expansion_context.Extension.code_path in

      match only with
      | Some only when not (cp |> should_log ~only) -> expr
      | Some _
      | None ->
        match (expr, env_level) with
        |
          (
            {pexp_desc = Pexp_match (_, _)} as expr,
            (Some (Info | Warn | Error) | None)
          ) -> expr
        |
          (
            {pexp_desc = Pexp_match (match_, cases); pexp_loc; pexp_attributes},
            Some(Trace | Debug)
          ) ->
            Exp.match_
              ~loc: pexp_loc
              ~attrs: pexp_attributes
              match_
              (
                cases
                |> List.map
                  (
                    function
                    |
                      {
                        pc_lhs = {ppat_desc = Ppat_construct ({txt = Lident tag}, None)} as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (tag |> format namespace `WithoutPayload |> log Debug cp)
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      (
                                        (Ppat_tuple ({ppat_desc = Ppat_var {txt = x1}}::[]))(* Reason *)
                                        | (Ppat_var {txt = x1}) (* ReScript *)
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |> log1 Debug1 cp (x1 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |> log2 Debug2 cp (x1 |> payload) (x2 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::
                                        {ppat_desc = Ppat_var {txt = x3}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |>
                                  log3
                                    Debug3
                                    cp
                                    (x1 |> payload)
                                    (x2 |> payload)
                                    (x3 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::
                                        {ppat_desc = Ppat_var {txt = x3}}::
                                        {ppat_desc = Ppat_var {txt = x4}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |>
                                  log4
                                    Debug4
                                    cp
                                    (x1 |> payload)
                                    (x2 |> payload)
                                    (x3 |> payload)
                                    (x4 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::
                                        {ppat_desc = Ppat_var {txt = x3}}::
                                        {ppat_desc = Ppat_var {txt = x4}}::
                                        {ppat_desc = Ppat_var {txt = x5}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |>
                                  log5
                                    Debug5
                                    cp
                                    (x1 |> payload)
                                    (x2 |> payload)
                                    (x3 |> payload)
                                    (x4 |> payload)
                                    (x5 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::
                                        {ppat_desc = Ppat_var {txt = x3}}::
                                        {ppat_desc = Ppat_var {txt = x4}}::
                                        {ppat_desc = Ppat_var {txt = x5}}::
                                        {ppat_desc = Ppat_var {txt = x6}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |>
                                  log6
                                    Debug6
                                    cp
                                    (x1 |> payload)
                                    (x2 |> payload)
                                    (x3 |> payload)
                                    (x4 |> payload)
                                    (x5 |> payload)
                                    (x6 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs =
                          {
                            ppat_desc =
                              Ppat_construct (
                                {txt = Lident tag},
                                Some(
                                  _,
                                  {
                                    ppat_desc =
                                      Ppat_tuple (
                                        {ppat_desc = Ppat_var {txt = x1}}::
                                        {ppat_desc = Ppat_var {txt = x2}}::
                                        {ppat_desc = Ppat_var {txt = x3}}::
                                        {ppat_desc = Ppat_var {txt = x4}}::
                                        {ppat_desc = Ppat_var {txt = x5}}::
                                        {ppat_desc = Ppat_var {txt = x6}}::
                                        {ppat_desc = Ppat_var {txt = x7}}::[]
                                      )
                                  }
                                )
                              )
                          } as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithPayload
                                |>
                                  log7
                                    Debug7
                                    cp
                                    (x1 |> payload)
                                    (x2 |> payload)
                                    (x3 |> payload)
                                    (x4 |> payload)
                                    (x5 |> payload)
                                    (x6 |> payload)
                                    (x7 |> payload)
                              )
                              branch
                          )
                    |
                      {
                        pc_lhs = {ppat_desc = Ppat_construct({txt = Lident tag}, Some _)} as pattern;
                        pc_rhs = branch;
                      } ->
                        Exp.case
                          pattern
                          (
                            Exp.sequence
                              (
                                tag
                                |> format namespace `WithNotLoggedPayload
                                |> log Debug cp
                              )
                              branch
                          )
                    | {pc_lhs = pattern; pc_rhs = branch} -> Exp.case pattern branch
                  )
              )

        | ({pexp_loc}, _) -> Location.raise_errorf ~loc: pexp_loc "Expected pattern matching"

  let impl =
    (
      object (_this)
        inherit Ast_traverse.map_with_expansion_context as super

        method! expression ctx expr =
          let expr = super#expression ctx expr in
          match expr |> Attribute.get attr with
          | None -> expr
          | Some namespace ->
            expr |> transform ~env_level: level ~namespace ~context: ctx

        method! structure str =
          let str = super#structure str in
          Attribute.check_all_seen ();
          str
      end
    )#structure;
end

let _ =
  "rescript-logger-ppx"
  |>
    Driver.register_transformation
      ~rules: (let open LogExt in [trace; debug; info; warn; error])
      ~impl: (
        fun str ->
          let path = str |> File_path.get_default_path_str in
          let ctx =
            Expansion_context.Base.top_level
              ~tool_name: (Ocaml_common.Ast_mapper.tool_name ())
              ~file_path: path 
              ~input_name: (
                (* I'm not sure if it's what meant by `input_name` *)
                match path |> Filename.basename |> Filename.chop_extension with 
                | x -> x
                | exception _ -> ""
              )
          in
          str |> LogAttr.impl ctx
      )

let _ = Driver.add_arg LibArg.key LibArg.spec ~doc:LibArg.doc
