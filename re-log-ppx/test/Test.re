let something = Some("thing");

[%log.debug "Debug level message"];
[%log.debug.line "Foo:"; {"x": 42}];
[%log.debug.line "Bar:"; something];
[%log.debug "Debug level message"; 2];
[%log.debug.line "Foo"];
[%log.debug.line [|1, 2, 3|]];

[%log.info "Info level message"];
[%log.info.line "Foo:"; {"x": 42}];
[%log.info.line "Bar:"; something];
[%log.info "Info level message"; 2];
[%log.info.line "Foo"];
[%log.info.line [|1, 2, 3|]];

[%log.ok "Ok level message"];
[%log.ok.line "Foo:"; {"x": 42}];
[%log.ok.line "Bar:"; something];
[%log.ok "Ok level message"; 2];
[%log.ok.line "Foo"];
[%log.ok.line [|1, 2, 3|]];

[%log.warn "Warn level message"];
[%log.warn.line "Foo:"; {"x": 42}];
[%log.warn.line "Bar:"; something];
[%log.warn "Warn level message"; 2];
[%log.warn.line "Foo"];
[%log.warn.line [|1, 2, 3|]];

[%log.error "Error level message"];
[%log.error.line "Foo:"; {"x": 42}];
[%log.error.line "Bar:"; something];
[%log.error "Error level message"; 2];
[%log.error.line "Foo"];
[%log.error.line [|1, 2, 3|]];
