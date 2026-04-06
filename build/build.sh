#!/usr/bin/env bash
set -e

SOURCE="main.cpp"
OUTPUT="hvlcs"

echo "Compiling $SOURCE..."

g++ -std=c++17 -Wall -Wextra -O2 "$SOURCE" -o "$OUTPUT"

echo "Compilation successful. Executable: $OUTPUT"