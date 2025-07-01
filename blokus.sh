#!/bin/bash

exeName="blokus"

gcc -Wall -Wextra -Werror -Wvla -pedantic -std=c99 ./src/*.c -o $exeName -lm

if [ $? -eq 0 ]; then
    echo "Successful compilation. Executable launched..."
    sleep 1
    ./$exeName
else
    echo "Compilation error."
fi
