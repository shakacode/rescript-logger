[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

// Level: Trace
[@bs.val] [@bs.scope "console"]
external traceGroup:
  (
    [@bs.as "%c TRACE "] _,
    [@bs.as "background: #636363; color: #fff;"] _,
    'a,
    'b
  ) => unit = "group";

[@bs.val] [@bs.scope "console"]
external traceGroupCollapsed:
  (
    [@bs.as "%c TRACE "] _,
    [@bs.as "background: #636363; color: #fff;"] _,
    'a,
    'b
  ) => unit = "groupCollapsed";

let trace =
  (
    m: string,
    x: 'x,
  ) => {
    m->Module.format->traceGroupCollapsed(x);
    groupEnd();
  };

let trace1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    groupEnd();
  };

let trace2 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    groupEnd();
  };

let trace3 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    groupEnd();
  };

let trace4 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    groupEnd();
  };

let trace5 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    groupEnd();
  };

let trace6 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    groupEnd();
  };

let trace7 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
    (l7, x7): (string, 'x7),
  ) => {
    m->Module.format->traceGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };

// Level: Debug
[@bs.val] [@bs.scope "console"]
external debugGroup:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) => unit = "group";

[@bs.val] [@bs.scope "console"]
external debugGroupCollapsed:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) => unit = "groupCollapsed";

let debug =
  (
    m: string,
    x: 'x,
  ) => {
    m->Module.format->debugGroupCollapsed(x);
    groupEnd();
  };

let debug1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    groupEnd();
  };

let debug2 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    groupEnd();
  };

let debug3 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    groupEnd();
  };

let debug4 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    groupEnd();
  };

let debug5 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    groupEnd();
  };

let debug6 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    groupEnd();
  };

let debug7 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
    (l7, x7): (string, 'x7),
  ) => {
    m->Module.format->debugGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };

// Level: Info
[@bs.val] [@bs.scope "console"]
external infoGroup:
  (
    [@bs.as "%c INFO "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) => unit = "group";

[@bs.val] [@bs.scope "console"]
external infoGroupCollapsed:
  (
    [@bs.as "%c INFO "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) => unit = "groupCollapsed";

let info =
  (
    m: string,
    x: 'x,
  ) => {
    m->Module.format->infoGroupCollapsed(x);
    groupEnd();
  };

let info1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    groupEnd();
  };

let info2 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    groupEnd();
  };

let info3 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    groupEnd();
  };

let info4 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    groupEnd();
  };

let info5 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    groupEnd();
  };

let info6 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    groupEnd();
  };

let info7 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
    (l7, x7): (string, 'x7),
  ) => {
    m->Module.format->infoGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };

// Level: Warn
[@bs.val] [@bs.scope "console"]
external warnGroup:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) => unit = "group";

[@bs.val] [@bs.scope "console"]
external warnGroupCollapsed:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) => unit = "groupCollapsed";

let warn = (
  m: string,
  x: 'x,
) => {
  m->Module.format->warnGroupCollapsed(x);
  groupEnd();
};

let warn1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    groupEnd();
  };

let warn2 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    groupEnd();
  };

let warn3 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    groupEnd();
  };

let warn4 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    groupEnd();
  };

let warn5 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x5),
    (l5, x5): (string, 'x6),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    groupEnd();
  };

let warn6 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    groupEnd();
  };

let warn7 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
    (l7, x7): (string, 'x7),
  ) => {
    m->Module.format->warnGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };

// Level: Error
[@bs.val] [@bs.scope "console"]
external errorGroup:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) => unit = "group";

[@bs.val] [@bs.scope "console"]
external errorGroupCollapsed:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) => unit = "groupCollapsed";

let error =
  (
    m: string,
    x: 'x,
  ) => {
    m->Module.format->errorGroupCollapsed(x);
    groupEnd();
  };

let error1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    groupEnd();
  };

let error2 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    groupEnd();
  };

let error3 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    groupEnd();
  };

let error4 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    groupEnd();
  };

let error5 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    groupEnd();
  };

let error6 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    groupEnd();
  };

let error7 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
    (l2, x2): (string, 'x2),
    (l3, x3): (string, 'x3),
    (l4, x4): (string, 'x4),
    (l5, x5): (string, 'x5),
    (l6, x6): (string, 'x6),
    (l7, x7): (string, 'x7),
  ) => {
    m->Module.format->errorGroup(x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };
