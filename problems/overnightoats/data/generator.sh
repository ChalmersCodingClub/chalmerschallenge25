#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution ac_rasmus.py

compile generate.py

samplegroup
sample 1
sample 2

group group01 100
include_group sample
for i in {1..20}
do
tc g1-$i generate
done