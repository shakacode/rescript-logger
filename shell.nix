with import <nixpkgs> {};
with pkgs.ocaml-ng.ocamlPackages_4_12;

let
  ppxlib-rescript = ppxlib.overrideAttrs (_: {
    version = "git";
    src = fetchFromGitHub {
      owner = "zth";
      repo = "ppxlib";
      rev = "32f83395fb89693a873541298b6367449f23bc4a";
      sha256 = "sha256-8bkmeFh5Unda8n3F2MQWi81QPt2NdkwFcy4wZTJ0STo=";
    };
    patches = [];
  });
in

mkShell {
  buildInputs = [
    ocaml
    dune_2
    findlib
    ppxlib-rescript
    merlin
    ocaml-lsp
    nodejs
    yarn
  ];
}
