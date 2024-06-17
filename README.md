# BPM
BahPackageManager enables you to install and remove package without worrying about dependencies.
> This is still a work in progress!

## Installation
Make sure you have lib sqlite3 installed.

1. Compile BPM `bah ./main.bah -d`
2. Install it! `./main -install itself`
    **Warning:** do not use `sudo` as it will not install bpm or any package for the current user.

## Usage
You can get more informations about its usage by running `bpm -h`.

- `-wrap` to generate the `bpm.mod` file that will be needed when installing your package.
- `-list` to list every package installed.
- `-install <package>` to install a package.
- `-update` to update all packages.
- `-remove <package>` to remove a package.
- `-deps <package>` to list every depenedencies of a program.

## Making a package
1. The name of **the main file of your package should be the name of your package's git** (or main.bah).
    That way, for the package `ithirzty/javel2`, the entry point is `javel2.bah`.
2. System libraries that you want to ship with your package should be in a folder named `libs` at the root of the package inside subfolders `linux`, `darwin` (macos) and `windows` depending on the libraries platform.
3. After initializing a git repository inside your package's folder and setting its url, type `bpm -wrap` to create the `bpm.mod` file.

## Adding sources
1. Locate your BPM folder (in the home folder).
2. Edit sources.json to add an origin.