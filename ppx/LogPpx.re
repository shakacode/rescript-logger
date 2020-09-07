open Migrate_parsetree;
open Ast_406;
open Ast_mapper;
open Ast_helper;
open Parsetree;

module Env = {
  let level = "BS_LOG";
  let logger = "BS_LOGGER";
};

module Delimiter = {
  let keyVal = '=';
  let entries = ',';
};

module Args = {
  let args: ref(option(string)) = ref(None);

  let set = x => args := Some(x);
  let reset = () => args := None;

  let list = [("--lib", Arg.String(set), "<name> Library name")];
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
    | Trace1 => "traceWithData"
    | Trace2 => "traceWithData2"
    | Trace3 => "traceWithData3"
    | Trace4 => "traceWithData4"
    | Trace5 => "traceWithData5"
    | Trace6 => "traceWithData6"
    | Trace7 => "traceWithData7"
    | Debug => "debug"
    | Debug1 => "debugWithData"
    | Debug2 => "debugWithData2"
    | Debug3 => "debugWithData3"
    | Debug4 => "debugWithData4"
    | Debug5 => "debugWithData5"
    | Debug6 => "debugWithData6"
    | Debug7 => "debugWithData7"
    | Info => "info"
    | Info1 => "infoWithData"
    | Info2 => "infoWithData2"
    | Info3 => "infoWithData3"
    | Info4 => "infoWithData4"
    | Info5 => "infoWithData5"
    | Info6 => "infoWithData6"
    | Info7 => "infoWithData7"
    | Warn => "warn"
    | Warn1 => "warnWithData"
    | Warn2 => "warnWithData2"
    | Warn3 => "warnWithData3"
    | Warn4 => "warnWithData4"
    | Warn5 => "warnWithData5"
    | Warn6 => "warnWithData6"
    | Warn7 => "warnWithData7"
    | Error => "error"
    | Error1 => "errorWithData"
    | Error2 => "errorWithData2"
    | Error3 => "errorWithData3"
    | Error4 => "errorWithData4"
    | Error5 => "errorWithData5"
    | Error6 => "errorWithData6"
    | Error7 => "errorWithData7";
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
  let default = "BrowserLogger";
  switch (Env.logger |> Sys.getenv) {
  | "" => default
  | exception Not_found => default
  | _ as x => x
  };
};

let __module__ =
  Exp.ident({
    txt: Ldot(Lident("Pervasives"), "__MODULE__"),
    loc: default_loc^,
  });

let logger = name =>
  Exp.ident({txt: Ldot(Lident(logger), name), loc: default_loc^});

let log = (fn, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [(Nolabel, __module__), (Nolabel, event)],
  );

let logWithData = (fn, data1, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [(Nolabel, __module__), (Nolabel, event), (Nolabel, data1)],
  );

let logWithData2 = (fn, data1, data2, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
    ],
  );

let logWithData3 = (fn, data1, data2, data3, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
      (Nolabel, data3),
    ],
  );

let logWithData4 = (fn, data1, data2, data3, data4, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
      (Nolabel, data3),
      (Nolabel, data4),
    ],
  );

let logWithData5 = (fn, data1, data2, data3, data4, data5, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
      (Nolabel, data3),
      (Nolabel, data4),
      (Nolabel, data5),
    ],
  );

let logWithData6 = (fn, data1, data2, data3, data4, data5, data6, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
      (Nolabel, data3),
      (Nolabel, data4),
      (Nolabel, data5),
      (Nolabel, data6),
    ],
  );

let logWithData7 =
    (fn, data1, data2, data3, data4, data5, data6, data7, event) =>
  Exp.apply(
    fn |> Fn.toString |> logger,
    [
      (Nolabel, __module__),
      (Nolabel, event),
      (Nolabel, data1),
      (Nolabel, data2),
      (Nolabel, data3),
      (Nolabel, data4),
      (Nolabel, data5),
      (Nolabel, data6),
      (Nolabel, data7),
    ],
  );

let nothing = Exp.construct({txt: Lident("()"), loc: default_loc^}, None);

let matchedLogEntry = (ns, ctx, tag) =>
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

let toData = arg =>
  Exp.tuple([
    Exp.constant(Pconst_string(arg, None)),
    Exp.ident({txt: Lident(arg), loc: default_loc^}),
  ]);

let baseMapper = (_config, _cookies) => {
  ...default_mapper,
  expr: (mapper, expr) =>
    switch (expr, level) {
    /* Level: Trace */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([{pstr_desc: Pstr_eval(event, _)}]),
            )),
        },
        Some(Trace),
      ) =>
      event |> log(Trace)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData(Trace1, data1)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData2(Trace2, data1, data2)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData3(Trace3, data1, data2, data3)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData4(Trace4, data1, data2, data3, data4)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData5(Trace5, data1, data2, data3, data4, data5)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event |> logWithData6(Trace6, data1, data2, data3, data4, data5, data6)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.trace"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
                {pstr_desc: Pstr_eval(data7, _)},
              ]),
            )),
        },
        Some(Trace),
      ) =>
      event
      |> logWithData7(Trace7, data1, data2, data3, data4, data5, data6, data7)

    | (
        {pexp_desc: Pexp_extension(({txt: "log.trace"}, _))},
        Some(Debug | Info | Warn | Error) | None,
      ) => nothing

    /* Level: Debug */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([{pstr_desc: Pstr_eval(event, _)}]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> log(Debug)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData(Debug1, data1)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData2(Debug2, data1, data2)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData3(Debug3, data1, data2, data3)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData4(Debug4, data1, data2, data3, data4)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData5(Debug5, data1, data2, data3, data4, data5)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event |> logWithData6(Debug6, data1, data2, data3, data4, data5, data6)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
                {pstr_desc: Pstr_eval(data7, _)},
              ]),
            )),
        },
        Some(Trace | Debug),
      ) =>
      event
      |> logWithData7(Debug7, data1, data2, data3, data4, data5, data6, data7)

    | (
        {pexp_desc: Pexp_extension(({txt: "log.debug"}, _))},
        Some(Info | Warn | Error) | None,
      ) => nothing

    /* Level: Info */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([{pstr_desc: Pstr_eval(event, _)}]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> log(Info)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData(Info1, data1)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData2(Info2, data1, data2)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData3(Info3, data1, data2, data3)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData4(Info4, data1, data2, data3, data4)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData5(Info5, data1, data2, data3, data4, data5)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event |> logWithData6(Info6, data1, data2, data3, data4, data5, data6)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
                {pstr_desc: Pstr_eval(data7, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info),
      ) =>
      event
      |> logWithData7(Info7, data1, data2, data3, data4, data5, data6, data7)

    | (
        {pexp_desc: Pexp_extension(({txt: "log.info"}, _))},
        Some(Warn | Error) | None,
      ) => nothing

    /* Level: Warn */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([{pstr_desc: Pstr_eval(event, _)}]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> log(Warn)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData(Warn1, data1)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData2(Warn2, data1, data2)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData3(Warn3, data1, data2, data3)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData4(Warn4, data1, data2, data3, data4)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData5(Warn5, data1, data2, data3, data4, data5)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event |> logWithData6(Warn6, data1, data2, data3, data4, data5, data6)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
                {pstr_desc: Pstr_eval(data7, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn),
      ) =>
      event
      |> logWithData7(Warn7, data1, data2, data3, data4, data5, data6, data7)

    | (
        {pexp_desc: Pexp_extension(({txt: "log.warn"}, _))},
        Some(Error) | None,
      ) => nothing

    /* Level: Error */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([{pstr_desc: Pstr_eval(event, _)}]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> log(Error)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData(Error1, data1)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData2(Error2, data1, data2)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData3(Error3, data1, data2, data3)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData4(Error4, data1, data2, data3, data4)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData5(Error5, data1, data2, data3, data4, data5)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event |> logWithData6(Error6, data1, data2, data3, data4, data5, data6)

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(event, _)},
                {pstr_desc: Pstr_eval(data1, _)},
                {pstr_desc: Pstr_eval(data2, _)},
                {pstr_desc: Pstr_eval(data3, _)},
                {pstr_desc: Pstr_eval(data4, _)},
                {pstr_desc: Pstr_eval(data5, _)},
                {pstr_desc: Pstr_eval(data6, _)},
                {pstr_desc: Pstr_eval(data7, _)},
              ]),
            )),
        },
        Some(Trace | Debug | Info | Warn | Error),
      ) =>
      event
      |> logWithData7(Error7, data1, data2, data3, data4, data5, data6, data7)

    | ({pexp_desc: Pexp_extension(({txt: "log.error"}, _))}, None) => nothing

    | _ => default_mapper.expr(mapper, expr)
    },
};

let resultMapper = (config, cookies) => {
  ...default_mapper,
  expr: (mapper, expr) =>
    switch (expr, level) {
    | (
        {
          pexp_attributes: [({txt: "log"}, payload)],
          pexp_desc: Pexp_match(match, cases),
        },
        Some(Trace | Debug),
      ) =>
      let ns =
        switch (payload) {
        | PStr([
            {
              pstr_desc:
                Pstr_eval(
                  {pexp_desc: Pexp_constant(Pconst_string(x, None))},
                  _,
                ),
            },
          ]) =>
          Some(x)
        | _ => None
        };
      Exp.match(
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
                   tag |> matchedLogEntry(ns, `WithoutPayload) |> log(Debug),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData(Debug1, arg1 |> toData),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData2(Debug2, arg1 |> toData, arg2 |> toData),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
                               {ppat_desc: Ppat_var({txt: arg3})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData3(
                        Debug3,
                        arg1 |> toData,
                        arg2 |> toData,
                        arg3 |> toData,
                      ),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
                               {ppat_desc: Ppat_var({txt: arg3})},
                               {ppat_desc: Ppat_var({txt: arg4})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData4(
                        Debug4,
                        arg1 |> toData,
                        arg2 |> toData,
                        arg3 |> toData,
                        arg4 |> toData,
                      ),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
                               {ppat_desc: Ppat_var({txt: arg3})},
                               {ppat_desc: Ppat_var({txt: arg4})},
                               {ppat_desc: Ppat_var({txt: arg5})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData5(
                        Debug5,
                        arg1 |> toData,
                        arg2 |> toData,
                        arg3 |> toData,
                        arg4 |> toData,
                        arg5 |> toData,
                      ),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
                               {ppat_desc: Ppat_var({txt: arg3})},
                               {ppat_desc: Ppat_var({txt: arg4})},
                               {ppat_desc: Ppat_var({txt: arg5})},
                               {ppat_desc: Ppat_var({txt: arg6})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData6(
                        Debug6,
                        arg1 |> toData,
                        arg2 |> toData,
                        arg3 |> toData,
                        arg4 |> toData,
                        arg5 |> toData,
                        arg6 |> toData,
                      ),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                               {ppat_desc: Ppat_var({txt: arg1})},
                               {ppat_desc: Ppat_var({txt: arg2})},
                               {ppat_desc: Ppat_var({txt: arg3})},
                               {ppat_desc: Ppat_var({txt: arg4})},
                               {ppat_desc: Ppat_var({txt: arg5})},
                               {ppat_desc: Ppat_var({txt: arg6})},
                               {ppat_desc: Ppat_var({txt: arg7})},
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
                   |> matchedLogEntry(ns, `WithPayload)
                   |> logWithData7(
                        Debug7,
                        arg1 |> toData,
                        arg2 |> toData,
                        arg3 |> toData,
                        arg4 |> toData,
                        arg5 |> toData,
                        arg6 |> toData,
                        arg7 |> toData,
                      ),
                   baseMapper(config, cookies).expr(mapper, branch),
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
                   |> matchedLogEntry(ns, `WithNotLoggedPayload)
                   |> log(Debug),
                   baseMapper(config, cookies).expr(mapper, branch),
                 ),
               )
             | {pc_lhs: pattern, pc_rhs: branch} =>
               Exp.case(
                 pattern,
                 baseMapper(config, cookies).expr(mapper, branch),
               )
             }
           ),
      );

    | _ => baseMapper(config, cookies).expr(mapper, expr)
    },
};

let () =
  Driver.register(
    ~name="bs-log-ppx",
    ~args=Args.list,
    ~reset_args=Args.reset,
    Versions.ocaml_406,
    resultMapper,
  );
