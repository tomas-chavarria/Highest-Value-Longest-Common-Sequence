#!/bin/bash

SOURCE="../src/longest-common-subsequence.cpp"
OUTPUT="../bin/hvlcs.exe"

echo "Compiling $SOURCE..."
g++ -std=c++17 -Wall -Wextra -O2 "$SOURCE" -o "$OUTPUT"

# $? captures the exit status of the previous command
if [ $? -eq 0 ]; then
    echo "Compilation successful."
else
    echo "Compilation failed."
fi