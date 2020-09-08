[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external group: ('a, 'b, 'c) => unit = "group";
[@bs.val] [@bs.scope "console"] external groupCollapsed: ('a, 'b, 'c) => unit = "groupCollapsed";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

// Level: Trace
let traceLabel = {js|\u001B[48;2;99;99;99m\u001B[38;2;255;255;255m TRACE \u001B[39m\u001B[49m|js};

let trace =
  (
    m: string,
    x: 'x,
  ) => {
    traceLabel->groupCollapsed(m->Module.format, x);
    groupEnd();
  };

let trace1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
    traceLabel->group(m->Module.format, x);
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
let debugLabel = {js|\u001B[48;2;130;101;140m\u001B[38;2;255;255;255m DEBUG \u001B[39m\u001B[49m|js};

let debug =
  (
    m: string,
    x: 'x,
  ) => {
    debugLabel->groupCollapsed(m->Module.format, x);
    groupEnd();
  };

let debug1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
    debugLabel->group(m->Module.format, x);
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
let infoLabel = {js|\u001B[48;2;34;153;221m\u001B[38;2;255;255;255m INFO \u001B[39m\u001B[49m|js};

let info =
  (
    m: string,
    x: 'x,
  ) => {
    infoLabel->groupCollapsed(m->Module.format, x);
    groupEnd();
  };

let info1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
    infoLabel->group(m->Module.format, x);
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
let warnLabel = {js|\u001B[48;2;252;228;115m\u001B[38;2;87;58;8m WARNING \u001B[39m\u001B[49m|js};

let warn =
  (
    m: string,
    x: 'x,
  ) => {
    warnLabel->groupCollapsed(m->Module.format, x);
    groupEnd();
  };

let warn1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
    warnLabel->group(m->Module.format, x);
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
let errorLabel = {js|\u001B[48;2;209;26;26m\u001B[38;2;255;255;255m ERROR \u001B[39m\u001B[49m|js};

let error =
  (
    m: string,
    x: 'x,
  ) => {
    errorLabel->groupCollapsed(m->Module.format, x);
    groupEnd();
  };

let error1 =
  (
    m: string,
    x: 'x,
    (l1, x1): (string, 'x1),
  ) => {
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
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
    errorLabel->group(m->Module.format, x);
    log2(l1 ++ ":", x1);
    log2(l2 ++ ":", x2);
    log2(l3 ++ ":", x3);
    log2(l4 ++ ":", x4);
    log2(l5 ++ ":", x5);
    log2(l6 ++ ":", x6);
    log2(l7 ++ ":", x7);
    groupEnd();
  };
