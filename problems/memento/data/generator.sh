#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution ../generate_empty.cpp

compile generate.py

group group01 100
for i in {1..100}
do
tc g1-$i generate

done