#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution joshua_highp.py

compile gen_random.py

samplegroup
sample 1
sample 2
sample 3

group group01 20
tc 1
tc 2
for i in {1..9}
do
tc g1-$i gen_random n=$i
done

group group02 80
tc 3
tc g2-1  gen_random n=32
tc g2-2  gen_random n=28
tc g2-3  gen_random n=31
tc g2-4  gen_random n=29
tc g2-5  gen_random n=33
tc g2-6  gen_random n=51
tc g2-7  gen_random n=42
tc g2-8  gen_random n=18
tc g2-9  gen_random n=35
tc g2-10 gen_random n=48
tc g2-11 gen_random n=12
