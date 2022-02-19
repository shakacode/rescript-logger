with import <nixpkgs> {};
with pkgs.ocaml-ng.ocamlPackages_4_12;

mkShell {
  buildInputs = [
    ocaml
    dune_2
    findlib
    ppxlib
    merlin
    ocaml-lsp
    nodejs
    yarn
  ];
}
