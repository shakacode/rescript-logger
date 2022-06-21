module type Logger = {
  let trace: (Location.t, 'x) => unit
  let trace1: (Location.t, 'x, (string, 'x1)) => unit
  let trace2: (Location.t, 'x, (string, 'x1), (string, 'x2)) => unit
  let trace3: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3)) => unit
  let trace4: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3), (string, 'x4)) => unit
  let trace5: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
  ) => unit
  let trace6: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
  ) => unit
  let trace7: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
    (string, 'x7),
  ) => unit

  let debug: (Location.t, 'x) => unit
  let debug1: (Location.t, 'x, (string, 'x1)) => unit
  let debug2: (Location.t, 'x, (string, 'x1), (string, 'x2)) => unit
  let debug3: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3)) => unit
  let debug4: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3), (string, 'x4)) => unit
  let debug5: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
  ) => unit
  let debug6: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
  ) => unit
  let debug7: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
    (string, 'x7),
  ) => unit

  let info: (Location.t, 'x) => unit
  let info1: (Location.t, 'x, (string, 'x1)) => unit
  let info2: (Location.t, 'x, (string, 'x1), (string, 'x2)) => unit
  let info3: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3)) => unit
  let info4: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3), (string, 'x4)) => unit
  let info5: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
  ) => unit
  let info6: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
  ) => unit
  let info7: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
    (string, 'x7),
  ) => unit

  let warn: (Location.t, 'x) => unit
  let warn1: (Location.t, 'x, (string, 'x1)) => unit
  let warn2: (Location.t, 'x, (string, 'x1), (string, 'x2)) => unit
  let warn3: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3)) => unit
  let warn4: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3), (string, 'x4)) => unit
  let warn5: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
  ) => unit
  let warn6: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
  ) => unit
  let warn7: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
    (string, 'x7),
  ) => unit

  let error: (Location.t, 'x) => unit
  let error1: (Location.t, 'x, (string, 'x1)) => unit
  let error2: (Location.t, 'x, (string, 'x1), (string, 'x2)) => unit
  let error3: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3)) => unit
  let error4: (Location.t, 'x, (string, 'x1), (string, 'x2), (string, 'x3), (string, 'x4)) => unit
  let error5: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
  ) => unit
  let error6: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
  ) => unit
  let error7: (
    Location.t,
    'x,
    (string, 'x1),
    (string, 'x2),
    (string, 'x3),
    (string, 'x4),
    (string, 'x5),
    (string, 'x6),
    (string, 'x7),
  ) => unit
}
