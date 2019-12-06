# bs-log

[![npm version](https://img.shields.io/npm/v/bs-log.svg?style=flat-square)](https://www.npmjs.com/package/bs-log)
[![license](https://img.shields.io/npm/l/bs-log.svg?style=flat-square)](https://www.npmjs.com/package/bs-log)

Logging implementation for [ReasonML](https://reasonml.github.io) / [BuckleScript](https://bucklescript.github.io).

![bs-log](./.assets/example.png)

## Features
- Zero runtime in production builds.
- Multiple logging levels.
- Customizable verbosity via environment variable.
- `[@log]` helper.
- `ReasonReact` integration.
- Custom loggers.

## Installation
Get the package:

```shell
# yarn
yarn add bs-log
# or npm
npm install --save bs-log
```

Then add it to `bsconfig.json`:

```json
"bs-dependencies": [
  "bs-log"
],
"ppx-flags": ["bs-log/ppx"]
```

PPX is highly recommended but optional (read details below).

## Usage
There are 4 log levels:
- `debug`
- `info`
- `warn`
- `error`

You can log message of specific level using either PPX or common functions:

```reason
/* ppx */
[%log.info "Info level message"];

/* non-ppx */
BrowserLogger.info(__MODULE__, "Info level message");
```

If you use PPX, value of `__MODULE__` variable will be injected automatically.

### Additional data
You can add data to log entry like this:

```reason
/* ppx */
[%log.info "Info level message"; ("Foo", 42)];
[%log.info
  "Info level message";
  ("Foo", {"x": 42});
  ("Bar", [1, 2, 3]);
];

/* non-ppx */
BrowserLogger.infoWithData(__MODULE__, "Info level message", ("Foo", 42));
BrowserLogger.infoWithData2(
  __MODULE__,
  "Info level message",
  ("Foo", {"x": 42}),
  ("Bar", [1, 2, 3]),
);
```

Currently, logger can accept up to 7 additional entries.

### Verbosity customization
You can set maximum log level via environment variable `BS_LOG`. This feature is available only when you use PPX.

Let's say you want to log only warnings and errors. To make it happen, run your build like this:

```shell
BS_LOG=warn bsb -clean-world -make-world
```

Available `BS_LOG` values:
- `*`: log everything
- `debug`: basically, the same as `*`
- `info`: log everything except `debug` level messages
- `warn`: log `warn` & `error` messages
- `error`: log `error` messages only
- `off`: don't log anything

If `BS_LOG` is set to `off`, nothing will be logged and none of the log entries will appear in your JS assets.

In case if `BS_LOG` environment variable is not set, log level `warn` will be set.

### PPX vs non-PPX
PPX gives you ability to customize maximum log level of your build and eliminates unwanted log entries from production builds. Also, it enables `ReasonReact` integration. If for some reason you want to use non-PPX api, then you have to handle elimination of log entries yourself on post-compilation stage.

Default logger compiles log entries to `console.*` method calls so those are discardable via [UglifyJS](https://github.com/mishoo/UglifyJS2#compress-options)/[TerserJS](https://github.com/terser-js/terser#compress-options) or [Babel plugin](https://babeljs.io/docs/en/babel-plugin-transform-remove-console).

### `[@log]` helper
This helper can be placed in front of any `switch` expression with constructor patterns and it will inject debug expressions into each branch.

```reason
let _ = x => [@log] switch (x) {
  | A => "A"
  | B(b) => b
}
```

It will be rewritten into:

```reason
let _ = x => switch (x) {
  | A =>
    [%log.debug "A"];
    "A";
  | B(b) =>
    [%log.debug "B with payload"; ("b", b)];
    b;
}
```

You can pass optional custom namespace to helper like this: `[@log "MyNamespace"]`.

`[@log]` helper works only for `switch` expressions with constructor patterns, for now. In the future, it will be extended to handle more cases.

### `ReasonReact` integration
Using `[@log]` helper, you can log dispatched actions in your components.

Annotate `reducer` function like this:

```reason
reducer: (action, state) => [@log] switch (action) {
  ...
}
```

These entries are logged on the `debug` level so none of those will appear in production builds.

### Custom loggers
`bs-log` ships with 2 loggers:
- `BrowserLogger` (default)
- `NodeLogger`

And you can easily plug your own.

For example, in development, you want to log everything to console using default logger, but in production, you want to disable console logging and send `error` level events to bug tracker.

To implement your own logger, you need to create a module (e.g. `BugTracker.re`) and set the following environment variables for production build.

```
BS_LOG=error
BS_LOGGER=BugTracker
```

Considering that you want to log only `error` level messages, you need to create functions only for errors logging.

```reason
/* BugTracker.re */

let error = (__module__, event) =>
  RemoteBugTracker.notify(event ++ " in " ++ __module__);

let errorWithData = (__module__, event, (label, data)) =>
  RemoteBugTracker.notify(
    event ++ " in " ++ __module__,
    [|(label, data)|], /* dummy example of passing additional data */
  );

let errorWithData2 = (
  __module__,
  event,
  (label1, data1),
  (label2, data2),
) =>
  RemoteBugTracker.notify(
    event ++ " in " ++ __module__,
    [|
      (label1, data1),
      (label2, data2),
    |],
  );

/* Up to 7 */
```

You don't have to re-implement all functions from default logger, only the ones you actually use. Don't worry to forget to implement something. If later on, you will attempt to use unimplemented method it will be compile time error.

## Caveats
**All logging is disabled after file save**<br />
If you run `bsb` via editor integration, make sure editor picked up `BS_LOG` variable. E.g. if you use Atom run it like this:

```shell
BS_LOG=info atom .
```

If your editor is telling you, variables used in ppx are unused, opening editor with `BS_LOG` variable also helps.

**Changing value of `BS_LOG`/`BS_LOGGER` doesn't make any effect**<br />
When you change a value of `BS_LOG` and/or `BS_LOGGER`, `-clean-world` before the next build.

## Developing
Repo consists of 2 parts:
- BuckleScript loggers: dependencies are managed by `yarn`
- Dune ppx: dependencies are managed by `esy`

Clone repo and install deps:

```shell
esy @ppx
yarn install
```

Build loggers and ppx:

```shell
yarn run build
esy @ppx build
```

To explore generated output, extend `bsconfig.json`:

```json
"sources": [
  "src",
  {
    "dir": "test",
    "type" : "dev"
  }
],
"ppx-flags": [
  "./_build/default/bin/bin.exe"
]
```

And rebuild BuckleScript project:

```shell
BS_LOG=* yarn run build
```
