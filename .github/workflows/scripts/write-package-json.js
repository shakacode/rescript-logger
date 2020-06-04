const fs = require("fs");
const path = require("path");

const {
  name,
  version,
  description,
  author,
  license,
  repository,
  files,
  peerDependencies,
  keywords
} = require("../../../package.json");

const packageJson = JSON.stringify(
  {
    name,
    version,
    description,
    author,
    license,
    repository,
    files,
    peerDependencies,
    keywords,
    scripts: {
      postinstall: "node ./postinstall.js"
    }
  },
  null,
  2
);

fs.writeFileSync(
  path.join(__dirname, "..", "..", "..", "_release", "package.json"),
  packageJson,
  { encoding: "utf8" }
);
