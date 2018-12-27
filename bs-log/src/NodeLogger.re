[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external group: ('a, 'b) => unit = "group";
[@bs.val] [@bs.scope "console"]
external groupCollapsed: ('a, 'b) => unit = "groupCollapsed";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

/* Level: Debug */
let debugLabel = {js|\u001B[48;2;130;101;140m\u001B[38;2;255;255;255m DEBUG \u001B[39m\u001B[49m|js};

let debug = (event: string) => {
  event->groupCollapsed(debugLabel, _);
  groupEnd();
};

let debugWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->group(debugLabel, _);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let debugWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->group(debugLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let debugWithData3 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  event->group(debugLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let debugWithData4 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  event->group(debugLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let debugWithData5 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  event->group(debugLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let debugWithData6 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  event->group(debugLabel, _);
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
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  event->group(debugLabel, _);
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

let info = (event: string) => {
  event->groupCollapsed(infoLabel, _);
  groupEnd();
};

let infoWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->group(infoLabel, _);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let infoWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->group(infoLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let infoWithData3 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  event->group(infoLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let infoWithData4 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  event->group(infoLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let infoWithData5 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  event->group(infoLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let infoWithData6 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  event->group(infoLabel, _);
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
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  event->group(infoLabel, _);
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

let warn = (event: string) => {
  event->groupCollapsed(warnLabel, _);
  groupEnd();
};

let warnWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->group(warnLabel, _);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let warnWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->group(warnLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let warnWithData3 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  event->group(warnLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let warnWithData4 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  event->group(warnLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let warnWithData5 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data5),
      (label5, data5): (string, 'data6),
    ) => {
  event->group(warnLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let warnWithData6 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  event->group(warnLabel, _);
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
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  event->group(warnLabel, _);
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

let error = (event: string) => {
  event->groupCollapsed(errorLabel, _);
  groupEnd();
};

let errorWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  groupEnd();
};

let errorWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  groupEnd();
};

let errorWithData3 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
    ) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  groupEnd();
};

let errorWithData4 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
    ) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  groupEnd();
};

let errorWithData5 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
    ) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  groupEnd();
};

let errorWithData6 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
    ) => {
  event->group(errorLabel, _);
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
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
      (label3, data3): (string, 'data3),
      (label4, data4): (string, 'data4),
      (label5, data5): (string, 'data5),
      (label6, data6): (string, 'data6),
      (label7, data7): (string, 'data7),
    ) => {
  event->group(errorLabel, _);
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};
