#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution ac_rasmus.py

compile generate.py

samplegroup
sample 1

group group01 100
tc 1
for i in {1..20}
do
tc g1-$i generate
done