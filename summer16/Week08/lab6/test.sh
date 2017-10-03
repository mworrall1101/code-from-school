#!/bin/bash

gcc -Wall -std=c99 -o StrStack_test str_stack.c str_stack_tester.c
rc=$?; if [[ $rc != 0 ]]; then exit $rc; fi

for n in {1..8}; do
    ./StrStack_test $n
done
