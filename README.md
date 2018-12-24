# bs-log

[![npm version](https://img.shields.io/npm/v/bs-log.svg?style=flat-square)](https://www.npmjs.com/package/bs-log)
[![license](https://img.shields.io/npm/l/bs-log.svg?style=flat-square)](https://www.npmjs.com/package/bs-log)

Logging implementation for [ReasonML](https://reasonml.github.io) / [BuckleScript](https://bucklescript.github.io).

![bs-log](./.assets/all.png)

## Features
- Zero runtime in production builds.
- Multiple logging levels.
- Customizable verbosity via environment variable.

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

PPX is recommended but totally optional (read details below).

## Usage
There are 5 log levels:
- `debug`
- `info`
- `ok`
- `warn`
- `error`

You can print message of specific level either using PPX or using common functions:

```reason
/* ppx */
[%log.info "Info level message"];

/* non-ppx */
Log.info("Info level message");
```

It will result in the following output:

![output](./.assets/info.png)

### Additional argument
You can add second argument to logger like this:

```reason
/* ppx */
[%log.info "Info level message"; 42];

/* non-ppx */
Log.info2("Info level message", 42);
```

Currently, 2 arguments per line is a max.

### Additional lines
Sometimes it's useful to print N entities per event. You can use `line` api for this:

```reason
/* ppx */
[%log.info "Info level message"];
[%log.info.line "Foo:"; {"x": 42}];

/* non-ppx */
Log.info("Info level message");
Log.infoLine2("Foo:", {"x": 42});
```

Here is how it looks like in console:

![output](./.assets/info-line.png)

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
- `ok`: log `ok`, `warn` & `error` messages
- `warn`: log `warn` & `error` messages
- `error`: log `error` messages only
- `off`: don't log anything (i.e. production mode)

If `BS_LOG` is not defined or set to `off`, nothing will be logged and none of the log entries will appear in your JS assets.

### PPX vs non-PPX
PPX gives you ability to customize maximum log level of your build. If for some reason you want to use non-PPX api, then you have to handle elimination of log entries yourself on post-compilation stage.

Log entries are compiled directly to `console.log` calls so those are discardable via [UglifyJS](https://github.com/mishoo/UglifyJS2#compress-options)/[TerserJS](https://github.com/terser-js/terser#compress-options) or [Babel plugin](https://babeljs.io/docs/en/babel-plugin-transform-remove-console).

## Caveats
**All logging is disabled after file save**<br />
If you run `bsb` via editor integration, make sure editor picked up `BS_LOG` variable. E.g. if you run Atom:

```shell
BS_LOG=info atom .
```

**Changing value of BS_LOG doesn't make any effect**<br />
When you change a value of `BS_LOG`, `-clean-world` before the next build.
