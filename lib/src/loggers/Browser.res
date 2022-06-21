@val @scope("console") external log: ('a, 'b) => unit = "log"
@val @scope("console") external groupEnd: unit => unit = "groupEnd"

// Level: Trace
@val @scope("console")
external traceGroup: (
  @as("%c TRACE ") _,
  @as("background: #636363; color: #fff;") _,
  'a,
  'b,
) => unit = "group"

@val @scope("console")
external traceGroupCollapsed: (
  @as("%c TRACE ") _,
  @as("background: #636363; color: #fff;") _,
  'a,
  'b,
) => unit = "groupCollapsed"

let trace = (loc: Location.t, x: 'x) => {
  loc->Location.format->traceGroupCollapsed(x)
  groupEnd()
}

let trace1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  groupEnd()
}

let trace2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  groupEnd()
}

let trace3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  groupEnd()
}

let trace4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  groupEnd()
}

let trace5 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  groupEnd()
}

let trace6 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  groupEnd()
}

let trace7 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
  (l7, x7): (string, 'x7),
) => {
  loc->Location.format->traceGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
  groupEnd()
}

// Level: Debug
@val @scope("console")
external debugGroup: (
  @as("%c DEBUG ") _,
  @as("background: #82658c; color: #fff;") _,
  'a,
  'b,
) => unit = "group"

@val @scope("console")
external debugGroupCollapsed: (
  @as("%c DEBUG ") _,
  @as("background: #82658c; color: #fff;") _,
  'a,
  'b,
) => unit = "groupCollapsed"

let debug = (loc: Location.t, x: 'x) => {
  loc->Location.format->debugGroupCollapsed(x)
  groupEnd()
}

let debug1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  groupEnd()
}

let debug2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  groupEnd()
}

let debug3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  groupEnd()
}

let debug4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  groupEnd()
}

let debug5 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  groupEnd()
}

let debug6 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  groupEnd()
}

let debug7 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
  (l7, x7): (string, 'x7),
) => {
  loc->Location.format->debugGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
  groupEnd()
}

// Level: Info
@val @scope("console")
external infoGroup: (@as("%c INFO ") _, @as("background: #29d; color: #fff;") _, 'a, 'b) => unit =
  "group"

@val @scope("console")
external infoGroupCollapsed: (
  @as("%c INFO ") _,
  @as("background: #29d; color: #fff;") _,
  'a,
  'b,
) => unit = "groupCollapsed"

let info = (loc: Location.t, x: 'x) => {
  loc->Location.format->infoGroupCollapsed(x)
  groupEnd()
}

let info1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  groupEnd()
}

let info2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  groupEnd()
}

let info3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  groupEnd()
}

let info4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  groupEnd()
}

let info5 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  groupEnd()
}

let info6 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  groupEnd()
}

let info7 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
  (l7, x7): (string, 'x7),
) => {
  loc->Location.format->infoGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
  groupEnd()
}

// Level: Warn
@val @scope("console")
external warnGroup: (
  @as("%c WARNING ") _,
  @as("background: #fce473; color: #573a08;") _,
  'a,
  'b,
) => unit = "group"

@val @scope("console")
external warnGroupCollapsed: (
  @as("%c WARNING ") _,
  @as("background: #fce473; color: #573a08;") _,
  'a,
  'b,
) => unit = "groupCollapsed"

let warn = (loc: Location.t, x: 'x) => {
  loc->Location.format->warnGroupCollapsed(x)
  groupEnd()
}

let warn1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  groupEnd()
}

let warn2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  groupEnd()
}

let warn3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  groupEnd()
}

let warn4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  groupEnd()
}

let warn5 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x5),
  (l5, x5): (string, 'x6),
) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  groupEnd()
}

let warn6 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  groupEnd()
}

let warn7 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
  (l7, x7): (string, 'x7),
) => {
  loc->Location.format->warnGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
  groupEnd()
}

// Level: Error
@val @scope("console")
external errorGroup: (
  @as("%c ERROR ") _,
  @as("background: #d11a1a; color: #fff;") _,
  'a,
  'b,
) => unit = "group"

@val @scope("console")
external errorGroupCollapsed: (
  @as("%c ERROR ") _,
  @as("background: #d11a1a; color: #fff;") _,
  'a,
  'b,
) => unit = "groupCollapsed"

let error = (loc: Location.t, x: 'x) => {
  loc->Location.format->errorGroupCollapsed(x)
  groupEnd()
}

let error1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  groupEnd()
}

let error2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  groupEnd()
}

let error3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  groupEnd()
}

let error4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  groupEnd()
}

let error5 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  groupEnd()
}

let error6 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  groupEnd()
}

let error7 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
  (l5, x5): (string, 'x5),
  (l6, x6): (string, 'x6),
  (l7, x7): (string, 'x7),
) => {
  loc->Location.format->errorGroup(x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
  groupEnd()
}
