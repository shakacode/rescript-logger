@val @scope("console") external log: ('a, 'b) => unit = "log"
@val @scope("console") external group: ('a, 'b, 'c) => unit = "log"
@val @scope("console") external groupCollapsed: ('a, 'b, 'c) => unit = "log"

// Level: Trace
let traceLabel = `\u001B[48;2;99;99;99m\u001B[38;2;255;255;255m TRACE \u001B[39m\u001B[49m`

let trace = (loc: Location.t, x: 'x) => {
  traceLabel->groupCollapsed(loc->Location.format, x)
}

let trace1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
}

let trace2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
}

let trace3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
}

let trace4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
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
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
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
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
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
  traceLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
}

// Level: Debug
let debugLabel = `\u001B[48;2;130;101;140m\u001B[38;2;255;255;255m DEBUG \u001B[39m\u001B[49m`

let debug = (loc: Location.t, x: 'x) => {
  debugLabel->groupCollapsed(loc->Location.format, x)
}

let debug1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
}

let debug2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
}

let debug3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
}

let debug4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
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
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
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
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
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
  debugLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
}

// Level: Info
let infoLabel = `\u001B[48;2;34;153;221m\u001B[38;2;255;255;255m INFO \u001B[39m\u001B[49m`

let info = (loc: Location.t, x: 'x) => {
  infoLabel->groupCollapsed(loc->Location.format, x)
}

let info1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
}

let info2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
}

let info3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
}

let info4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
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
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
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
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
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
  infoLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
}

// Level: Warn
let warnLabel = `\u001B[48;2;252;228;115m\u001B[38;2;87;58;8m WARNING \u001B[39m\u001B[49m`

let warn = (loc: Location.t, x: 'x) => {
  warnLabel->groupCollapsed(loc->Location.format, x)
}

let warn1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
}

let warn2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
}

let warn3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
}

let warn4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
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
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
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
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
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
  warnLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
}

// Level: Error
let errorLabel = `\u001B[48;2;209;26;26m\u001B[38;2;255;255;255m ERROR \u001B[39m\u001B[49m`

let error = (loc: Location.t, x: 'x) => {
  errorLabel->groupCollapsed(loc->Location.format, x)
}

let error1 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1)) => {
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
}

let error2 = (loc: Location.t, x: 'x, (l1, x1): (string, 'x1), (l2, x2): (string, 'x2)) => {
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
}

let error3 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
) => {
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
}

let error4 = (
  loc: Location.t,
  x: 'x,
  (l1, x1): (string, 'x1),
  (l2, x2): (string, 'x2),
  (l3, x3): (string, 'x3),
  (l4, x4): (string, 'x4),
) => {
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
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
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
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
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
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
  errorLabel->group(loc->Location.format, x)
  log(l1 ++ ":", x1)
  log(l2 ++ ":", x2)
  log(l3 ++ ":", x3)
  log(l4 ++ ":", x4)
  log(l5 ++ ":", x5)
  log(l6 ++ ":", x6)
  log(l7 ++ ":", x7)
}
