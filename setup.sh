#!/bin/bash
set -e

# Install vcpkg if not already installed
if ! command -v vcpkg &> /dev/null; then
    echo "vcpkg not found, installing inside the project directory..."
    git clone https://github.com/microsoft/vcpkg.git
    ./vcpkg/bootstrap-vcpkg.sh
    export VCPKG_ROOT="$(pwd)/vcpkg"
else
    echo "vcpkg found, using existing installation..."
    export VCPKG_ROOT="$(dirname $(command -v vcpkg))"
fi

# Install dependencies
vcpkg install

cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
