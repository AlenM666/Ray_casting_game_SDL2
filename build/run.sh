#!/bin/bash

g++ -std=c++17 \
    ./../src/main.cpp \
    ./../src/map/*.cpp \
    ./../src/render/*.cpp \
    ./../src/ray/*.cpp \
    ./../src/player/*.cpp \
    -I./../src \
    -o raycaster \
    -lSDL2 -lSDL2_ttf

./raycaster
