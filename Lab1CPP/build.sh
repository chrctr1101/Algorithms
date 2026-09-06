#!/bin/fish

rm -r build/

mkdir build

cd build

cmake ..

make

