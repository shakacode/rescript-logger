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
let x = {
  reducer:
    [@log]
    (
      (action, _state) =>
        switch (action) {
        | A => "a"
        | B(data) => data
        | C(_data1, data2) => data2
        | D(_data1, _data2, data3) => data3
        | E(_data1, _data2, _data3, data4) => data4
        | F(_data1, _data2, _data3, _data4, data5) => data5
        | G(_data1, _data2, _data3, _data4, _data5, data6) => data6
        | H(_data1, _data2, _data3, _data4, _data5, _data6, data7) => data7
        }
    ),
};

let something = Some("thing");

[%log.debug "Debug level message"];
[%log.debug "Debug level message"; ("Foo", 42)];
[%log.debug "Debug level message"; ("Foo", 42); ("Bar", {"x": 42})];
[%log.debug
  "Debug level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something)
];
[%log.debug
  "Debug level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4])
];
[%log.debug
  "Debug level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|])
];
[%log.debug
  "Debug level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true)
];
[%log.debug
  "Debug level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true);
  ("Whatever", `Eh)
];

[%log.info "Info level message"];
[%log.info "Info level message"; ("Foo", 42)];
[%log.info "Info level message"; ("Foo", 42); ("Bar", {"x": 42})];
[%log.info
  "Info level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something)
];
[%log.info
  "Info level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4])
];
[%log.info
  "Info level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|])
];
[%log.info
  "Info level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true)
];
[%log.info
  "Info level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true);
  ("Whatever", `Eh)
];

[%log.warn "Warn level message"];
[%log.warn "Warn level message"; ("Foo", 42)];
[%log.warn "Warn level message"; ("Foo", 42); ("Bar", {"x": 42})];
[%log.warn
  "Warn level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something)
];
[%log.warn
  "Warn level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4])
];
[%log.warn
  "Warn level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|])
];
[%log.warn
  "Warn level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true)
];
[%log.warn
  "Warn level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true);
  ("Whatever", `Eh)
];

[%log.error "Error level message"];
[%log.error "Error level message"; ("Foo", 42)];
[%log.error "Error level message"; ("Foo", 42); ("Bar", {"x": 42})];
[%log.error
  "Error level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something)
];
[%log.error
  "Error level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4])
];
[%log.error
  "Error level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|])
];
[%log.error
  "Error level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true)
];
[%log.error
  "Error level message";
  ("Foo", 42);
  ("Bar", {"x": 42});
  ("Baz", something);
  ("List", [1, 2, 4]);
  ("Array", [|1, 2, 4|]);
  ("Bool", true);
  ("Whatever", `Eh)
];
