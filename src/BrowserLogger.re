[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

module Module = {
  let format = x => {j|[$x]|j};
};

/* Level: Trace */
[@bs.val] [@bs.scope "console"]
external traceGroup:
  (
    [@bs.as "%c TRACE "] _,
    [@bs.as "background: #636363; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external traceGroupCollapsed:
  (
    [@bs.as "%c TRACE "] _,
    [@bs.as "background: #636363; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "groupCollapsed";

let trace = (__module__: string, event: 'a) => {
  __module__->Module.format->traceGroupCollapsed(event);
  groupEnd();
};

let traceWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let traceWithData2 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let traceWithData3 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let traceWithData4 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let traceWithData5 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let traceWithData6 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  groupEnd();
};

let traceWithData7 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  __module__->Module.format->traceGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};

/* Level: Debug */
[@bs.val] [@bs.scope "console"]
external debugGroup:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external debugJs:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "debug";

let debug = (__module__: string, event: 'a) => {
  __module__->Module.format->debugJs(event);
};

let debugWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let debugWithData2 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let debugWithData3 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let debugWithData4 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let debugWithData5 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let debugWithData6 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  groupEnd();
};

let debugWithData7 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  __module__->Module.format->debugGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};

/* Level: Info */
[@bs.val] [@bs.scope "console"]
external infoGroup:
  (
    [@bs.as "%c INFO "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external infoJs:
  (
    [@bs.as "%c INFO "] _,
    [@bs.as "background: #29d; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "info";

let info = (__module__: string, event: 'a) => {
  __module__->Module.format->infoJs(event);
};

let infoWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let infoWithData2 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let infoWithData3 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let infoWithData4 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let infoWithData5 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let infoWithData6 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  groupEnd();
};

let infoWithData7 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  __module__->Module.format->infoGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};

/* Level: Warn */
[@bs.val] [@bs.scope "console"]
external warnGroup:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external warnJs:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a,
    'b
  ) =>
  unit =
  "warn";

let warn = (__module__: string, event: 'a) => {
  __module__->Module.format->warnJs(event);
};

let warnWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let warnWithData2 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let warnWithData3 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let warnWithData4 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let warnWithData5 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data5),
      (label5, data5): (string, 'data6),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let warnWithData6 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  groupEnd();
};

let warnWithData7 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  __module__->Module.format->warnGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};

/* Level: Error */
[@bs.val] [@bs.scope "console"]
external errorGroup:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external errorJs:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a,
    'b
  ) =>
  unit =
  "error";

let error = (__module__: string, event: 'a) => {
  __module__->Module.format->errorJs(event);
};

let errorWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let errorWithData2 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let errorWithData3 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let errorWithData4 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let errorWithData5 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let errorWithData6 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  groupEnd();
};

let errorWithData7 =
    (
      __module__: string,
      event: 'a,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  __module__->Module.format->errorGroup(event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};
