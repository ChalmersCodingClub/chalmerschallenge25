#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution julia.py

compile generate.py

samplegroup
sample 1
sample 2

group group01 100
include_group sample
for i in {1..20}
do
tc g1y-$i generate p=0.1 x=$i g=0
tc g1n-$i generate p=0.1 x=$i g=1
tc g2y-$i generate p=0.5 x=$i g=0
tc g2n-$i generate p=0.5 x=$i g=1
tc g3y-$i generate p=2 x=$i g=0
tc g3n-$i generate p=2 x=$i g=1
done
