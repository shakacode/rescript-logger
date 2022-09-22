type t = {
  rootModule: string,
  subModulePath: list<string>,
  value: option<string>,
  fullPath: string,
}

let format = x => `[${x.fullPath}]`
