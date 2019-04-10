const fs = require("fs");
const path = require("path");

const mainPackageJson = require("../../package.json");
const packageJson = JSON.stringify(
  {
    name: mainPackageJson.name,
    version: mainPackageJson.version,
    description: mainPackageJson.description,
    author: mainPackageJson.author,
    license: mainPackageJson.license,
    repository: mainPackageJson.repository,
    files: mainPackageJson.files,
    peerDependencies: mainPackageJson.peerDependencies,
    keywords: mainPackageJson.keywords,
    scripts: {
      postinstall: "node ./postinstall.js"
    }
  },
  null,
  2
);

fs.writeFileSync(
  path.join(__dirname, "..", "..", "_release", "package.json"),
  packageJson,
  {encoding: "utf8"},
);
