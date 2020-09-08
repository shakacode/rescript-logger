let something = Some("thing");

[%log.trace "Trace message"];
[%log.trace "Trace message"; ("1", 42)];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42})];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42}); ("3", something)];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4])];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|])];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true)];
[%log.trace "Trace message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true); ("7", `X)];

[%log.debug "Debug message"];
[%log.debug "Debug message"; ("1", 42)];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42})];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42}); ("3", something)];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4])];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|])];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true)];
[%log.debug "Debug message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true); ("7", `X)];

[%log.info "Info message"];
[%log.info "Info message"; ("1", 42)];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42})];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42}); ("3", something)];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4])];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|])];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true)];
[%log.info "Info message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true); ("7", `X)];

[%log.warn "Warn message"];
[%log.warn "Warn message"; ("1", 42)];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42})];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42}); ("3", something)];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4])];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|])];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true)];
[%log.warn "Warn message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true); ("7", `X)];

[%log.error "Error message"];
[%log.error "Error message"; ("1", 42)];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42})];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42}); ("3", something)];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4])];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|])];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true)];
[%log.error "Error message"; ("1", 42); ("2", {"x": 42}); ("3", something); ("4", [1, 2, 4]); ("5", [|1, 2, 4|]); ("6", true); ("7", `X)];

type state;
type action =
  | A
  | B(string)
  | C(string, string)
  | D(string, string, string)
  | E(string, string, string, string)
  | F(string, string, string, string, string)
  | G(string, string, string, string, string, string)
  | H(string, string, string, string, string, string, string);
type component = {reducer: (action, state) => string};
let make = {
  reducer: (action, _state) =>
    [@log]
    (
      switch (action) {
      | A => "a"
      | B(x) =>
        [%log.trace "Ext"; ("within", "@log")];
        x;
      | C(_x1, x2) => x2
      | D(_x1, _x2, x3) => x3
      | E(_x1, _x2, _x3, x4) => x4
      | F(_x1, _x2, _x3, _x4, x5) => x5
      | G(_x1, _x2, _x3, _x4, _x5, x6) => x6
      | H(_x1, _x2, _x3, _x4, _x5, _x6, x7) => x7
      }
    ),
};

type ns =
  | A
  | B(string)
  | C(int);
let ns = x =>
  [@log "Namespace"]
  (
    switch (x) {
    | A => "A"
    | B(x) => x
    | C(_) => "C"
    }
  );

let noop = x =>
  [@log]
  (
    switch (x) {
    | "" => "a"
    | _ => "b"
    }
  );
