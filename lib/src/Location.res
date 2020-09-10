type t = {
  rootModule: string,
  subModulePath: list<string>,
  value: option<string>,
  fullPath: string,
  filePath: string,
}

let format = x => `[${x.fullPath}]`
