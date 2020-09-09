open Ppxlib;
open Ast_helper;

module Env = {
  let level = "BS_LOG";
  let logger = "BS_LOGGER";
  let only = "BS_LOG_ONLY";
};

module Delimiter = {
  let keyVal = '=';
  let entries = ',';
};

module Level = {
  type t =
    | Trace
    | Debug
    | Info
    | Warn
    | Error;

  let fromString =
    fun
    | "*"
    | "trace" => Some(Trace)
    | "debug" => Some(Debug)
    | "info" => Some(Info)
    | "warn"
    | "warning" => Some(Warn)
    | "error" => Some(Error)
    | "off" => None
    | _ as x => failwith("Invalid log level: " ++ x);
};

module Fn = {
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
    | Error7;

  let toString =
    fun
    | Trace => "trace"
    | Trace1 => "trace1"
    | Trace2 => "trace2"
    | Trace3 => "trace3"
    | Trace4 => "trace4"
    | Trace5 => "trace5"
    | Trace6 => "trace6"
    | Trace7 => "trace7"
    | Debug => "debug"
    | Debug1 => "debug1"
    | Debug2 => "debug2"
    | Debug3 => "debug3"
    | Debug4 => "debug4"
    | Debug5 => "debug5"
    | Debug6 => "debug6"
    | Debug7 => "debug7"
    | Info => "info"
    | Info1 => "info1"
    | Info2 => "info2"
    | Info3 => "info3"
    | Info4 => "info4"
    | Info5 => "info5"
    | Info6 => "info6"
    | Info7 => "info7"
    | Warn => "warn"
    | Warn1 => "warn1"
    | Warn2 => "warn2"
    | Warn3 => "warn3"
    | Warn4 => "warn4"
    | Warn5 => "warn5"
    | Warn6 => "warn6"
    | Warn7 => "warn7"
    | Error => "error"
    | Error1 => "error1"
    | Error2 => "error2"
    | Error3 => "error3"
    | Error4 => "error4"
    | Error5 => "error5"
    | Error6 => "error6"
    | Error7 => "error7";
};

module LibArg = {
  let box: ref(option(string)) = ref(None);

  let set = x => box := Some(x);
  let reset = () => box := None;

  let key = "--lib";
  let spec = Arg.String(set);
  let doc = "<name> Library name";
};

module Lib = {
  let fromArgs = () =>
    if (Sys.argv |> Array.length > 1) {
      switch (Sys.argv[1] |> String.split_on_char(Delimiter.keyVal)) {
      | ["--lib", lib] => Some(lib)
      | _ => None
      };
    } else {
      None;
    };
};

let level = {
  let default = Level.Warn;
  let lib = Lib.fromArgs();
  switch (Env.level |> Sys.getenv) {
  | exception Not_found =>
    switch (lib) {
    | Some(_) => None
    | None => Some(default)
    }
  | _ as rawEnvEntries =>
    let entries = rawEnvEntries |> String.split_on_char(Delimiter.entries);
    switch (entries, lib) {
    | ([], _) =>
      failwith("Empty value of environment variable " ++ Env.level)
    | ([level] | [level, ..._], None) => level |> Level.fromString
    | (entries, Some(lib)) =>
      entries
      |> List.fold_left(
           (res, entry) =>
             switch (res) {
             | Some(res) => Some(res)
             | None =>
               switch (entry |> String.split_on_char(Delimiter.keyVal)) {
               | [lib', level] when lib' == lib => level |> Level.fromString
               | _ => None
               }
             },
           None,
         )
    };
  };
};

let logger = {
  let default = "BsLog.Browser";

  let rec build =
    (~lid=?, xs) =>
      switch (lid, xs) {
      | (None, [x, ...xs]) => xs |> build(~lid=Lident(x))
      | (Some(lid), [x, ...xs]) => xs |> build(~lid=Ldot(lid, x))
      | (Some(lid), []) => lid
      | (None, []) => failwith("Empty logger")
      };

  let parse = x => x |> String.split_on_char('.') |> build;

  switch (Env.logger |> Sys.getenv) {
  | "" => default |> parse
  | exception Not_found => default |> parse
  | _ as x => x |> parse
  };
};

let only: option(list(list(string))) =
  switch (Env.only |> Sys.getenv) {
  | "" => None
  | exception Not_found => None
  | _ as x =>
    Some(
      x
      |> String.split_on_char(',')
      |> List.map(x => x |> String.split_on_char('.'))
    )
  };

let rec should_log = (path, only) => {
  switch (path, only) {
  | (_, []) => true
  | ([], [_, ..._]) => false
  | ([p, ...path], [o, ...only]) =>
    if (o != p) {
      false
    } else {
      should_log(path, only)
    }
  };
};

let should_log = (~only, path) => {
  let path =
    path
    |> Code_path.fully_qualified_path
    |> String.split_on_char('.');
  let finder = path |> should_log;

  switch (only |> List.find_opt(finder)) {
  | Some(_) => true
  | None => false
  };
};

module Ast = {
  let rec list = (~expr=?, xs) =>
    switch (expr, xs) {
    | (None, []) =>
      Exp.construct(
        {txt: Lident("[]"), loc: default_loc^},
        None,
      )
    | (Some(expr), []) =>
      Exp.construct(
        {txt: Lident("::"), loc: default_loc^},
        Some(expr),
      )
    | (None, [x, ...xs]) =>
      xs |> list(
        ~expr=
          Exp.tuple([
            Exp.constant(Const.string(x)),
            Exp.construct(
              {txt: Lident("[]"), loc: default_loc^},
              None,
            )
          ])
      )
    | (Some(expr), [x, ...xs]) =>
      xs |> list(
        ~expr=
          Exp.tuple([
            Exp.constant(Const.string(x)),
            Exp.construct(
              {txt: Lident("::"), loc: default_loc^},
              Some(expr),
            )
          ])
      )

    };

  let module_arg = (cp: Code_path.t) =>
    Exp.record(
      [
        (
          {txt: Lident("rootModule"), loc: default_loc^},
          Exp.constant(Const.string(cp |> Code_path.main_module_name))
        ),
        (
          {txt: Lident("subModulePath"), loc: default_loc^},
          cp |> Code_path.submodule_path |> List.rev |> list,
        ),
        (
          {txt: Lident("value"), loc: default_loc^},
          switch (cp |> Code_path.value) {
          | Some(value) =>
            Exp.construct(
              {txt: Lident("Some"), loc: default_loc^},
              Some(Exp.constant(Const.string(value))),
            )
          | None =>
            Exp.construct({txt: Lident("None"), loc: default_loc^}, None)
          }
        ),
        (
          {txt: Lident("fullPath"), loc: default_loc^},
          Exp.constant(Const.string(cp |> Code_path.fully_qualified_path))
        ),
        (
          {txt: Lident("filePath"), loc: default_loc^},
          Exp.constant(Const.string(cp |> Code_path.file_path))
        ),
      ],
      None,
    );

  let logger = fn =>
    Exp.ident({txt: Ldot(logger, fn), loc: default_loc^});

  let log = (fn, cp, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
      ],
    );

  let log1 = (fn, cp, x1, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
      ],
    );

  let log2 = (fn, cp, x1, x2, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
      ],
    );

  let log3 = (fn, cp, x1, x2, x3, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
        (Nolabel, x3),
      ],
    );

  let log4 = (fn, cp, x1, x2, x3, x4, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
        (Nolabel, x3),
        (Nolabel, x4),
      ],
    );

  let log5 = (fn, cp, x1, x2, x3, x4, x5, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
        (Nolabel, x3),
        (Nolabel, x4),
        (Nolabel, x5),
      ],
    );

  let log6 = (fn, cp, x1, x2, x3, x4, x5, x6, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
        (Nolabel, x3),
        (Nolabel, x4),
        (Nolabel, x5),
        (Nolabel, x6),
      ],
    );

  let log7 =
      (fn, cp, x1, x2, x3, x4, x5, x6, x7, x) =>
    Exp.apply(
      fn |> Fn.toString |> logger,
      [
        (Nolabel, cp |> module_arg),
        (Nolabel, x),
        (Nolabel, x1),
        (Nolabel, x2),
        (Nolabel, x3),
        (Nolabel, x4),
        (Nolabel, x5),
        (Nolabel, x6),
        (Nolabel, x7),
      ],
    );

  let nothing = Exp.construct({txt: Lident("()"), loc: default_loc^}, None);
};

module LogExt = {
  open Ast;

  let transform =
    (
      ~ext_level: Level.t,
      ~env_level: option(Level.t),
      ~context: Expansion_context.Extension.t,
      payload: payload
    ) => {
      let cp = context |> Expansion_context.Extension.code_path;

      switch only {
      | Some(only) when !(cp |> should_log(~only)) => nothing
      | Some(_)
      | None =>
        switch (payload) {
        | PStr([{pstr_desc: Pstr_eval(x, _)}]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log(Trace, cp)
          | (Debug, Some(Trace | Debug))                       => x |> log(Debug, cp)
          | (Info,  Some(Trace | Debug | Info))                => x |> log(Info,  cp)
          | (Warn,  Some(Trace | Debug | Info | Warn))         => x |> log(Warn,  cp)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log(Error, cp)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([{pstr_desc: Pstr_eval(x, _)}, {pstr_desc: Pstr_eval(x1, _)}]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log1(Trace1, cp, x1)
          | (Debug, Some(Trace | Debug))                       => x |> log1(Debug1, cp, x1)
          | (Info,  Some(Trace | Debug | Info))                => x |> log1(Info1,  cp, x1)
          | (Warn,  Some(Trace | Debug | Info | Warn))         => x |> log1(Warn1,  cp, x1)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log1(Error1, cp, x1)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log2(Trace2, cp, x1, x2)
          | (Debug, Some(Trace | Debug))                       => x |> log2(Debug2, cp, x1, x2)
          | (Info,  Some(Trace | Debug | Info))                => x |> log2(Info2,  cp, x1, x2)
          | (Warn,  Some(Trace | Debug | Info | Warn))         => x |> log2(Warn2,  cp, x1, x2)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log2(Error2, cp, x1, x2)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
            {pstr_desc: Pstr_eval(x3, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log3(Trace3, cp, x1, x2, x3)
          | (Debug, Some(Trace | Debug))                       => x |> log3(Debug3, cp, x1, x2, x3)
          | (Info,  Some(Trace | Debug | Info))                => x |> log3(Info3,  cp, x1, x2, x3)
          | (Warn,  Some(Trace | Debug | Info | Warn))         => x |> log3(Warn3,  cp, x1, x2, x3)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log3(Error3, cp, x1, x2, x3)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
            {pstr_desc: Pstr_eval(x3, _)},
            {pstr_desc: Pstr_eval(x4, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log4(Trace4, cp, x1, x2, x3, x4)
          | (Debug, Some(Trace | Debug))                       => x |> log4(Debug4, cp, x1, x2, x3, x4)
          | (Info,  Some(Trace | Debug | Info))                => x |> log4(Info4,  cp, x1, x2, x3, x4)
          | (Warn,  Some(Trace | Debug | Info | Warn))         => x |> log4(Warn4,  cp, x1, x2, x3, x4)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log4(Error4, cp, x1, x2, x3, x4)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
            {pstr_desc: Pstr_eval(x3, _)},
            {pstr_desc: Pstr_eval(x4, _)},
            {pstr_desc: Pstr_eval(x5, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log5(Trace5, cp, x1, x2, x3, x4, x5)
          | (Debug, Some(Trace | Debug))                       => x |> log5(Debug5, cp, x1, x2, x3, x4, x5)
          | (Info, Some(Trace | Debug | Info))                 => x |> log5(Info5,  cp, x1, x2, x3, x4, x5)
          | (Warn, Some(Trace | Debug | Info | Warn))          => x |> log5(Warn5,  cp, x1, x2, x3, x4, x5)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log5(Error5, cp, x1, x2, x3, x4, x5)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
            {pstr_desc: Pstr_eval(x3, _)},
            {pstr_desc: Pstr_eval(x4, _)},
            {pstr_desc: Pstr_eval(x5, _)},
            {pstr_desc: Pstr_eval(x6, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log6(Trace6, cp, x1, x2, x3, x4, x5, x6)
          | (Debug, Some(Trace | Debug))                       => x |> log6(Debug6, cp, x1, x2, x3, x4, x5, x6)
          | (Info, Some(Trace | Debug | Info))                 => x |> log6(Info6,  cp, x1, x2, x3, x4, x5, x6)
          | (Warn, Some(Trace | Debug | Info | Warn))          => x |> log6(Warn6,  cp, x1, x2, x3, x4, x5, x6)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log6(Error6, cp, x1, x2, x3, x4, x5, x6)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | PStr([
            {pstr_desc: Pstr_eval(x, _)},
            {pstr_desc: Pstr_eval(x1, _)},
            {pstr_desc: Pstr_eval(x2, _)},
            {pstr_desc: Pstr_eval(x3, _)},
            {pstr_desc: Pstr_eval(x4, _)},
            {pstr_desc: Pstr_eval(x5, _)},
            {pstr_desc: Pstr_eval(x6, _)},
            {pstr_desc: Pstr_eval(x7, _)},
          ]) =>
          switch (ext_level, env_level) {
          | (Trace, Some(Trace))                               => x |> log7(Trace7, cp, x1, x2, x3, x4, x5, x6, x7)
          | (Debug, Some(Trace | Debug))                       => x |> log7(Debug7, cp, x1, x2, x3, x4, x5, x6, x7)
          | (Info, Some(Trace | Debug | Info))                 => x |> log7(Info7,  cp, x1, x2, x3, x4, x5, x6, x7)
          | (Warn, Some(Trace | Debug | Info | Warn))          => x |> log7(Warn7,  cp, x1, x2, x3, x4, x5, x6, x7)
          | (Error, Some(Trace | Debug | Info | Warn | Error)) => x |> log7(Error7, cp, x1, x2, x3, x4, x5, x6, x7)
          | (Trace | Debug | Info | Warn | Error, _)           => nothing
          }

        | _ =>
          Location.raise_errorf(
            ~loc=context |> Expansion_context.Extension.extension_point_loc,
            "Too many arguments",
          )
        };
    };
  };


  let trace = Context_free.Rule.extension(
    Extension.V3.declare(
      "log.trace",
      Extension.Context.expression,
      Ast_pattern.__,
      (~ctxt, payload) =>
        payload |> transform(
          ~ext_level=Trace,
          ~env_level=level,
          ~context=ctxt,
        )
    )
  );

  let debug = Context_free.Rule.extension(
    Extension.V3.declare(
      "log.debug",
      Extension.Context.expression,
      Ast_pattern.__,
      (~ctxt, payload) =>
        payload |> transform(
          ~ext_level=Debug,
          ~env_level=level,
          ~context=ctxt,
        )
    )
  );

  let info = Context_free.Rule.extension(
    Extension.V3.declare(
      "log.info",
      Extension.Context.expression,
      Ast_pattern.__,
      (~ctxt, payload) =>
        payload |> transform(
          ~ext_level=Info,
          ~env_level=level,
          ~context=ctxt,
        )
    )
  );

  let warn = Context_free.Rule.extension(
    Extension.V3.declare(
      "log.warn",
      Extension.Context.expression,
      Ast_pattern.__,
      (~ctxt, payload) =>
        payload |> transform(
          ~ext_level=Warn,
          ~env_level=level,
          ~context=ctxt,
        )
    )
  );

  let error = Context_free.Rule.extension(
    Extension.V3.declare(
      "log.error",
      Extension.Context.expression,
      Ast_pattern.__,
      (~ctxt, payload) =>
        payload |> transform(
          ~ext_level=Error,
          ~env_level=level,
          ~context=ctxt,
        )
    )
  );
};

module LogAttr = {
  open Ast;

  let attr =
    Attribute.declare(
      "log",
      Attribute.Context.expression,
      Ast_pattern.(T((ctx, loc, x, k) => {
        switch x {
        | PStr([]) =>
          ctx.matched = ctx.matched + 1;
          None |> k
        | PStr([
            {pstr_desc: Pstr_eval({pexp_desc: Pexp_constant(Pconst_string(x, None))}, _)},
          ]) =>
            ctx.matched = ctx.matched + 1;
            Some(x) |> k
        | _ => Location.raise_errorf(~loc, "Expected string")
        }
      })),
      x => x,
    );

  let format = (ns, ctx, tag) =>
    switch (ns) {
    | None =>
      switch (ctx) {
      | `WithoutPayload => Exp.constant(Pconst_string(tag, None))
      | `WithPayload =>
        Exp.constant(Pconst_string(tag ++ " with payload", None))
      | `WithNotLoggedPayload =>
        Exp.constant(Pconst_string(tag ++ " with payload (not logged)", None))
      }
    | Some(ns) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Pervasives"), "^"), loc: default_loc^}),
        [
          (Nolabel, Exp.constant(Pconst_string(ns, None))),
          (
            Nolabel,
            switch (ctx) {
            | `WithoutPayload => Exp.constant(Pconst_string("::" ++ tag, None))
            | `WithPayload =>
              Exp.constant(Pconst_string("::" ++ tag ++ " with payload", None))
            | `WithNotLoggedPayload =>
              Exp.constant(
                Pconst_string(
                  "::" ++ tag ++ " with payload (not logged)",
                  None,
                ),
              )
            },
          ),
        ],
      )
    };

  let payload = x =>
    Exp.tuple([
      Exp.constant(Pconst_string(x, None)),
      Exp.ident({txt: Lident(x), loc: default_loc^}),
    ]);

  let transform =
    (
      ~env_level: option(Level.t),
      ~namespace: option(string),
      ~context: Expansion_context.Base.t,
      expr: expression,
    ) => {
      // TODO: Use Base getters once ppxlib is updated
      let context =
        Expansion_context.Extension.make(
          ~extension_point_loc=expr.pexp_loc,
          ~base=context,
          ()
        );
      let cp = context |> Expansion_context.Extension.code_path;

      switch only {
      | Some(only) when !(cp |> should_log(~only)) => expr
      | Some(_)
      | None =>
        switch (expr, env_level) {
        |
          (
            {pexp_desc: Pexp_match(_, _)} as expr,
            Some(Info | Warn | Error) | None
          ) => expr
        |
          (
            {pexp_desc: Pexp_match(match, cases), pexp_loc, pexp_attributes},
            Some(Trace | Debug)
          ) =>
            Exp.match(
              ~loc=pexp_loc,
              ~attrs=pexp_attributes,
              match,
              cases
              |> List.map(case =>
                   switch (case) {
                   | {
                       pc_lhs:
                         {ppat_desc: Ppat_construct({txt: Lident(tag)}, None)} as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag |> format(namespace, `WithoutPayload) |> log(Debug, cp),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([{ppat_desc: Ppat_var({txt: x1})}]) // Reason
                                   | Ppat_var({txt: x1}) // ReScript
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log1(Debug1, cp, x1 |> payload),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log2(Debug2, cp, x1 |> payload, x2 |> payload),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                     {ppat_desc: Ppat_var({txt: x3})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log3(
                              Debug3,
                              cp,
                              x1 |> payload,
                              x2 |> payload,
                              x3 |> payload,
                            ),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                     {ppat_desc: Ppat_var({txt: x3})},
                                     {ppat_desc: Ppat_var({txt: x4})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log4(
                              Debug4,
                              cp,
                              x1 |> payload,
                              x2 |> payload,
                              x3 |> payload,
                              x4 |> payload,
                            ),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                     {ppat_desc: Ppat_var({txt: x3})},
                                     {ppat_desc: Ppat_var({txt: x4})},
                                     {ppat_desc: Ppat_var({txt: x5})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log5(
                              Debug5,
                              cp,
                              x1 |> payload,
                              x2 |> payload,
                              x3 |> payload,
                              x4 |> payload,
                              x5 |> payload,
                            ),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                     {ppat_desc: Ppat_var({txt: x3})},
                                     {ppat_desc: Ppat_var({txt: x4})},
                                     {ppat_desc: Ppat_var({txt: x5})},
                                     {ppat_desc: Ppat_var({txt: x6})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log6(
                              Debug6,
                              cp,
                              x1 |> payload,
                              x2 |> payload,
                              x3 |> payload,
                              x4 |> payload,
                              x5 |> payload,
                              x6 |> payload,
                            ),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {
                           ppat_desc:
                             Ppat_construct(
                               {txt: Lident(tag)},
                               Some({
                                 ppat_desc:
                                   Ppat_tuple([
                                     {ppat_desc: Ppat_var({txt: x1})},
                                     {ppat_desc: Ppat_var({txt: x2})},
                                     {ppat_desc: Ppat_var({txt: x3})},
                                     {ppat_desc: Ppat_var({txt: x4})},
                                     {ppat_desc: Ppat_var({txt: x5})},
                                     {ppat_desc: Ppat_var({txt: x6})},
                                     {ppat_desc: Ppat_var({txt: x7})},
                                   ]),
                               }),
                             ),
                         } as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithPayload)
                         |> log7(
                              Debug7,
                              cp,
                              x1 |> payload,
                              x2 |> payload,
                              x3 |> payload,
                              x4 |> payload,
                              x5 |> payload,
                              x6 |> payload,
                              x7 |> payload,
                            ),
                         branch,
                       ),
                     )
                   | {
                       pc_lhs:
                         {ppat_desc: Ppat_construct({txt: Lident(tag)}, Some(_))} as pattern,
                       pc_rhs: branch,
                     } =>
                     Exp.case(
                       pattern,
                       Exp.sequence(
                         tag
                         |> format(namespace, `WithNotLoggedPayload)
                         |> log(Debug, cp),
                         branch,
                       ),
                     )
                   | {pc_lhs: pattern, pc_rhs: branch} =>
                     Exp.case(
                       pattern,
                       branch,
                     )
                   }
                 ),
            );
        | ({pexp_loc}, _) => Location.raise_errorf(~loc=pexp_loc, "Expected pattern matching")
        };
      };
    };

  let impl =
    {
      inherit class Ast_traverse.map_with_expansion_context as super;
      pub! expression = (ctx, expr) => {
        let expr = super#expression(ctx, expr);
        switch (Attribute.get(attr, expr)) {
        | None => expr
        | Some(namespace) =>
          expr |> transform(~env_level=level, ~namespace, ~context=ctx)
        };
      };
      pub! structure = str => {
        let str = super#structure(str);
        Attribute.check_all_seen();
        str;
      }
    }#structure;
};

"bs-log-ppx" |> Driver.register_transformation(
  ~rules=LogExt.[trace, debug, info, warn, error],
  ~impl=str => {
    let ctx =
      Expansion_context.Base.top_level(
        ~tool_name=Ocaml_common.Ast_mapper.tool_name(),
        ~file_path=str |> File_path.get_default_path_str,
      );
    str |> LogAttr.impl(ctx);
  },
);

Driver.add_arg(LibArg.key, LibArg.spec, ~doc=LibArg.doc);
