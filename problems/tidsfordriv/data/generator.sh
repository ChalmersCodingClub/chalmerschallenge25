#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution hugo.cpp

compile gen_random.py

group group01 100
for i in {1..25}
do
tc g1-$i gen_random max_n=10
done
