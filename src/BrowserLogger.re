[@bs.val] [@bs.scope "console"] external log: 'a => unit = "log";
[@bs.val] [@bs.scope "console"] external log2: ('a, 'b) => unit = "log";
[@bs.val] [@bs.scope "console"] external groupEnd: unit => unit = "groupEnd";

/* Level: Debug */
[@bs.val] [@bs.scope "console"]
external debugGroup:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external debugGroupCollapsed:
  (
    [@bs.as "%c DEBUG "] _,
    [@bs.as "background: #82658c; color: #fff;"] _,
    'a
  ) =>
  unit =
  "groupCollapsed";

let debug = (event: string) => {
  event->debugGroupCollapsed;
  groupEnd();
};

let debugWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->debugGroup;
  log2(label1 ++ ":", data1);
  groupEnd();
};

let debugWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->debugGroup;
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
  event->debugGroup;
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
  event->debugGroup;
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
  event->debugGroup;
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
  event->debugGroup;
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
  event->debugGroup;
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
  ([@bs.as "%c INFO "] _, [@bs.as "background: #29d; color: #fff;"] _, 'a) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external infoGroupCollapsed:
  ([@bs.as "%c INFO "] _, [@bs.as "background: #29d; color: #fff;"] _, 'a) =>
  unit =
  "groupCollapsed";

let info = (event: string) => {
  event->infoGroupCollapsed;
  groupEnd();
};

let infoWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->infoGroup;
  log2(label1 ++ ":", data1);
  groupEnd();
};

let infoWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->infoGroup;
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
  event->infoGroup;
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
  event->infoGroup;
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
  event->infoGroup;
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
  event->infoGroup;
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
  event->infoGroup;
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
    'a
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external warnGroupCollapsed:
  (
    [@bs.as "%c WARNING "] _,
    [@bs.as "background: #fce473; color: #573a08;"] _,
    'a
  ) =>
  unit =
  "groupCollapsed";

let warn = (event: string) => {
  event->warnGroupCollapsed;
  groupEnd();
};

let warnWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->warnGroup;
  log2(label1 ++ ":", data1);
  groupEnd();
};

let warnWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->warnGroup;
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
  event->warnGroup;
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
  event->warnGroup;
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
  event->warnGroup;
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
  event->warnGroup;
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
  event->warnGroup;
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
    'a
  ) =>
  unit =
  "group";

[@bs.val] [@bs.scope "console"]
external errorGroupCollapsed:
  (
    [@bs.as "%c ERROR "] _,
    [@bs.as "background: #d11a1a; color: #fff;"] _,
    'a
  ) =>
  unit =
  "groupCollapsed";

let error = (event: string) => {
  event->errorGroupCollapsed;
  groupEnd();
};

let errorWithData = (event: string, (label1, data1): (string, 'data1)) => {
  event->errorGroup;
  log2(label1 ++ ":", data1);
  groupEnd();
};

let errorWithData2 =
    (
      event: string,
      (label1, data1): (string, 'data1),
      (label2, data2): (string, 'data2),
    ) => {
  event->errorGroup;
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
  event->errorGroup;
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
  event->errorGroup;
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
  event->errorGroup;
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
  event->errorGroup;
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
  event->errorGroup;
  log2(label1 ++ ":", data1);
  log2(label2 ++ ":", data2);
  log2(label3 ++ ":", data3);
  log2(label4 ++ ":", data4);
  log2(label5 ++ ":", data5);
  log2(label6 ++ ":", data6);
  log2(label7 ++ ":", data7);
  groupEnd();
};
