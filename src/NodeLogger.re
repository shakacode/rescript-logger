[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external group: ('a, 'b, 'c) => unit = "group";
[@bs.val] [@bs.scope "console"]
external groupCollapsed: ('a, 'b, 'c) => unit = "groupCollapsed";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

module Module = {
  let format = x => {j|[$x]|j};
};

/* Level: Trace */
let traceLabel = {js|\u001B[48;2;99;99;99m\u001B[38;2;255;255;255m TRACE \u001B[39m\u001B[49m|js};

let trace = (__module__: string, event: 'a) => {
  traceLabel->groupCollapsed(__module__->Module.format, event);
  groupEnd();
};

let traceWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
  traceLabel->group(__module__->Module.format, event);
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
let debugLabel = {js|\u001B[48;2;130;101;140m\u001B[38;2;255;255;255m DEBUG \u001B[39m\u001B[49m|js};

let debug = (__module__: string, event: 'a) => {
  debugLabel->groupCollapsed(__module__->Module.format, event);
  groupEnd();
};

let debugWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
  debugLabel->group(__module__->Module.format, event);
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
let infoLabel = {js|\u001B[48;2;34;153;221m\u001B[38;2;255;255;255m INFO \u001B[39m\u001B[49m|js};

let info = (__module__: string, event: 'a) => {
  infoLabel->groupCollapsed(__module__->Module.format, event);
  groupEnd();
};

let infoWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
  infoLabel->group(__module__->Module.format, event);
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
let warnLabel = {js|\u001B[48;2;252;228;115m\u001B[38;2;87;58;8m WARNING \u001B[39m\u001B[49m|js};

let warn = (__module__: string, event: 'a) => {
  warnLabel->groupCollapsed(__module__->Module.format, event);
  groupEnd();
};

let warnWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
  warnLabel->group(__module__->Module.format, event);
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
let errorLabel = {js|\u001B[48;2;209;26;26m\u001B[38;2;255;255;255m ERROR \u001B[39m\u001B[49m|js};

let error = (__module__: string, event: 'a) => {
  errorLabel->groupCollapsed(__module__->Module.format, event);
  groupEnd();
};

let errorWithData =
    (__module__: string, event: 'a, (label1, data1): (string, 'data1)) => {
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
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
  errorLabel->group(__module__->Module.format, event);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};
