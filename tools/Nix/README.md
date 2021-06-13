ww# Page For Nix pacakge manager learnings

Nix is imo the best way to manage pacakges

## nix-env allows you to install stuff into the user's environment

## nix-shell allows you to test out packages

example nix config:

```nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    name="My-env";
    buildInputs = [
        pkgs.neovim
        pkgs.python3
    ];
}
```