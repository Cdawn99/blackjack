#!/bin/bash

set -xe

CFLAGS="-Wall -Werror -Wextra -pedantic -pedantic-errors -std=c17 -ggdb"
INCLUDES="-I./raylib-5.0_linux_amd64/include"
LIBS="-L./raylib-5.0_linux_amd64/lib -lraylib -lm"

OUTPUT="-o ./build/blackjack"
INPUT="main.c blackjack.c"

mkdir -p build

gcc ${OUTPUT} ${INPUT} ${CFLAGS} ${INCLUDES} ${LIBS}
