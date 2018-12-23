open Ast_mapper;
open Ast_helper;
open Asttypes;
open Parsetree;
open Longident;

type level =
  | Debug
  | Info
  | Ok
  | Warn
  | Error;

exception InvalidLogLevel(string);

let level =
  switch (Sys.getenv("RE_LOG")) {
  | "*" => Debug->Some
  | "debug" => Debug->Some
  | "info" => Info->Some
  | "ok" => Ok->Some
  | "warn" => Warn->Some
  | "error" => Error->Some
  | "off" => None
  | exception Not_found => None
  | _ as x => x->InvalidLogLevel->raise
  };

let logMapper = _ => {
  ...default_mapper,
  expr: (mapper, expr) =>
    switch (expr, level) {
    /* Level: Debug */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "debug"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "debug2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug.line"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "debugLine"),
          loc: default_loc^,
        }),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.debug.line"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "debugLine2"),
          loc: default_loc^,
        }),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension(({txt: "log.debug" | "log.debug.line"}, _)),
        },
        Some(Info | Ok | Warn | Error) | None,
      ) =>
      Exp.construct({txt: Lident("()"), loc: default_loc^}, None)

    /* Level: Info */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "info"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "info2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info.line"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "infoLine"),
          loc: default_loc^,
        }),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.info.line"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "infoLine2"),
          loc: default_loc^,
        }),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc: Pexp_extension(({txt: "log.info" | "log.info.line"}, _)),
        },
        Some(Ok | Warn | Error) | None,
      ) =>
      Exp.construct({txt: Lident("()"), loc: default_loc^}, None)

    /* Level: Ok */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.ok"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "ok"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.ok"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "ok2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.ok.line"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "okLine"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.ok.line"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "okLine2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {pexp_desc: Pexp_extension(({txt: "log.ok" | "log.ok.line"}, _))},
        Some(Warn | Error) | None,
      ) =>
      Exp.construct({txt: Lident("()"), loc: default_loc^}, None)

    /* Level: Warn */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok | Warn),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "warn"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok | Warn),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "warn2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn.line"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok | Warn),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "warnLine"),
          loc: default_loc^,
        }),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.warn.line"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok | Warn),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "warnLine2"),
          loc: default_loc^,
        }),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc: Pexp_extension(({txt: "log.warn" | "log.warn.line"}, _)),
        },
        Some(Error) | None,
      ) =>
      Exp.construct({txt: Lident("()"), loc: default_loc^}, None)

    /* Level: Error */
    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok | Warn | Error),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "error"), loc: default_loc^}),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok | Warn | Error),
      ) =>
      Exp.apply(
        Exp.ident({txt: Ldot(Lident("Log"), "error2"), loc: default_loc^}),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error.line"},
              PStr([{pstr_desc: Pstr_eval(expr1, _)}]),
            )),
        },
        Some(Debug | Info | Ok | Warn | Error),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "errorLine"),
          loc: default_loc^,
        }),
        [("", expr1)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension((
              {txt: "log.error.line"},
              PStr([
                {pstr_desc: Pstr_eval(expr1, _)},
                {pstr_desc: Pstr_eval(expr2, _)},
              ]),
            )),
        },
        Some(Debug | Info | Ok | Warn | Error),
      ) =>
      Exp.apply(
        Exp.ident({
          txt: Ldot(Lident("Log"), "errorLine2"),
          loc: default_loc^,
        }),
        [("", expr1), ("", expr2)],
      )

    | (
        {
          pexp_desc:
            Pexp_extension(({txt: "log.error" | "log.error.line"}, _)),
        },
        None,
      ) =>
      Exp.construct({txt: Lident("()"), loc: default_loc^}, None)

    | _ => default_mapper.expr(mapper, expr)
    },
};

let () = Ast_mapper.register("re-log", logMapper);
