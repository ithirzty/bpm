# BPM
BahPackageManager enables you to install and remove package without worrying about dependencies.
> This is still pulsing in beta!

## Installation

Make sure you have lib sqlite3 installed.

1. Compile BPM `bah ./main.bah -d`
2. Install it! `./main -install itself`

## Usage
You can get more informations about its usage by running `bpm -h`.

- `-wrap` to generate the `bpm.mod` file that will be needed when installing your package.
- `-list` to list every package installed.
- `-install <package>` to install a package.
- `-remove <package>` to remove a package.
- `-deps <package>` to list every depenedencies of a program.

## Adding sources
1. Locate your BPM folder (in the home folder).
2. Edit sources.json to add an origin.