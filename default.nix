{ pkgs ? import <nixpkgs> { } }:

with pkgs; stdenv.mkDerivation {
  name = "build-cpp-by-nix";
  src = ./.;

  buildInputs = [ boost poco ];
  buildPhase = "c++ -o main main.cpp -l PocoFoundation -l boost_system";
  installPhase = ''
    mkdir $out/bin -p
    cp ./main $out/bin/
  '';
}
