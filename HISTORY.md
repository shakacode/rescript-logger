# History

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
