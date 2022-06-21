@val external window: Dom.window = "window"

// NOTE: Unfortunately, it pulls in currying.
// Not sure if it's possible to uncurry without changing the interface, which would be a breaking change.
include unpack(
  window->Js.typeof == "undefined"
    ? module(Node: Interface.Logger)
    : module(Browser: Interface.Logger)
)
