# game-demo

Demo of a 2D game using Flecs, SDL2 and Tiled

## Requirements

- CMake
- vcpkg (installed automatically by setup.sh if not found)
- VCPKG_ROOT as environment variable containing the path to vcpkg (set automatically by setup.sh if not found)

## Setup

Run `setup.sh` to setup CMake with vcpkg and install dependencies.
```bash
./setup.sh
```

## Build

```bash
cmake --build build
```

## Run

```bash
./build/<executable_name>
```