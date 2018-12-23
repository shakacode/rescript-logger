[@bs.val] [@bs.scope "console"]
external debug:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external debug2:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external debugLine:
  (
    [@bs.as "%c     > "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external debugLine2:
  (
    [@bs.as "%c     > "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external info:
  ([@bs.as "%c INFO "] _, [@bs.as "background: #29d; color: #fff;"] _, 'a) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external info2:
  (
    [@bs.as "%c INFO "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external infoLine:
  ([@bs.as "%c    > "] _, [@bs.as "background: #29d; color: #fff;"] _, 'a) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external infoLine2:
  (
    [@bs.as "%c    > "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external ok:
  ([@bs.as "%c OK "] _, [@bs.as "background: #72b935; color: #fff;"] _, 'a) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external ok2:
  (
    [@bs.as "%c OK "] _,
    [@bs.as "background: #72b935; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external okLine:
  ([@bs.as "%c  > "] _, [@bs.as "background: #72b935; color: #fff;"] _, 'a) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external okLine2:
  (
    [@bs.as "%c  > "] _,
    [@bs.as "background: #72b935; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external warn:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external warn2:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";
[@bs.val] [@bs.scope "console"]
external warnLine:
  (
    [@bs.as "%c       > "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external warnLine2:
  (
    [@bs.as "%c       > "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external error:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external error2:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external errorLine:
  (
    [@bs.as "%c     > "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a
  ) =>
  unit =
  "log";

[@bs.val] [@bs.scope "console"]
external errorLine2:
  (
    [@bs.as "%c     > "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "log";
