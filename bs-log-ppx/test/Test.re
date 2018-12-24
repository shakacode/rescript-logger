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
