#!/bin/bash

echo "compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1
bison -d --debug $1.y -Wcounterexamples
lex $1.l
g++ lex.yy.c symbol_table.cpp $1.tab.c -std=c++11 -o $1
