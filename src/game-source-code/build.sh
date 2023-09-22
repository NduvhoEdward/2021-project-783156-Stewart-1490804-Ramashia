#!/bin/bash

# The name of the output executable
OUTPUT_EXECUTABLE="Centipede++"

# Compiler options (e.g., C++17 and optimizations)
CXX_FLAGS="-std=c++20 -O2"

# Source files
SOURCE_FILES="main.cpp Blaster.cpp Centipede.cpp Game.cpp Mushrooms.cpp Player.cpp"

# Compile and link the project
g++ $CXX_FLAGS $SOURCE_FILES -o $OUTPUT_EXECUTABLE -lsfml-graphics -lsfml-window -lsfml-system 

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable: $OUTPUT_EXECUTABLE"
else
    echo "Compilation failed."
fi
