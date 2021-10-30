# History

## 2.0.2
- Remove `bs-platform` peer dependency.

## 2.0.1
- Add support for M1 Macs through Rosetta [#28](https://github.com/shakacode/rescript-logger/pull/28).

## 2.0.0
- Package renamed to `rescript-logger` and converted to `ReScript` syntax.
- Default loggers namespaced and renamed:
  - `BrowserLogger` -> `ReScriptLogger.Browser`
  - `NodeLogger` -> `ReScriptLogger.Node`
- Environment variables renamed:
  - `BS_LOG` -> `RES_LOG`
  - `BS_LOGGER` -> `RES_LOGGER`
- Added environment variable `RES_LOG_ONLY`. It allows logging only from specific locations in code.<br />
E.g. `RES_LOG_ONLY=Module.Submodule.fn bsb ...`<br />
See [`Verbosity customization > Code location`](./README.md#code-location).
- Each log entry produced by default loggers is prefixed with full location from where it's been called.<br />
E.g. `[Module.Submodule.fn] ...`
- Logger interface changed (pay attention if you have custom loggers in your codebase):
  - Logger function `<level>WithData` renamed to `<level>1`
  - Logger function `<level>WithData<x>` renamed to `<level><x>`
  - Each logger function receives `Location.t` record instead of a `__MODULE__` string. See [`Custom loggers`](./README.md#custom-loggers).

## 1.3.0
- Add `Trace` level.
- Ensure PPX binary is available on all platforms.

## 1.2.0
- Make logging event polymorphic in `BrowserLogger` and `NodeLogger`.

## 1.1.0
- Logging in libraries.

## 1.0.0
- BuckleScript v7 support.
- Make `warn` default log level for situations when `BS_LOG` env var doesn't exist.
- Fix postinstall script for Windows.

## 0.1.1
- Fix Windows build.

## 0.1.0
- Prefix all log entries with value of a `__MODULE__` variable.
- Update PPX setup.

## 0.0.9
- Default logger renamed from `Console` to `BrowserLogger`.
- Added `NodeLogger`.

## 0.0.8
- Make `[@log]` annotation generic: it can be placed in front of any `switch` expression with constructors.
- `[@log]` can accept optional namespace: `[@log "MyNamespace"]`.

## 0.0.7
- Allow log statements inside annotated reducers.

## 0.0.6
- Use default logger when `BS_LOGGER` is empty string.

## 0.0.5
- Add `BS_LOGGER` environment variable.
- Rename default logger from `Log` to `Console`.

## 0.0.4
React logger.

## 0.0.3
Lots of changes, hope nobody used it yet.

## 0.0.2
Package renamed to `bs-log`.

## 0.0.1
Initial release.
