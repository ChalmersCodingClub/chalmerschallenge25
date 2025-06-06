#!/bin/bash
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited
# Takes a long time to run because high precision is slow
use_solution ../partially_accepted/joshua_highp.py

compile gen_rand.py pypy

samplegroup
limits maxn=10
sample 1
sample 2

group group1 50
limits maxn=100
include_group sample
tc g1-1 gen_rand r=10 g=10 b=10
tc g1-2 gen_rand r=1 g=1 b=1
tc g1-3 gen_rand r=98 g=1 b=1
tc g1-4 gen_rand r=1 g=98 b=1
tc g1-5 gen_rand r=1 g=1 b=98
tc g1-6 gen_rand r=33 g=34 b=33
tc g1-7 gen_rand r=34 g=33 b=33
tc g1-8 gen_rand r=4 g=48 b=48
tc g1-9 gen_rand r=4 g=4 b=48
tc g1-10 gen_rand r=4 g=48 b=4
tc g1-11 gen_rand r=33 g=33 b=33 min_x=-4 max_x=5 min_y=-4 max_y=5
tc g1-12 gen_rand r=33 g=33 b=33 min_x=-1000000000 max_x=-999999991 min_y=999999991 max_y=1000000000

group group2 50
limits maxn=6000
include_group group1
tc g2-1 gen_rand r=666  g=666  b=666
tc g2-2 gen_rand r=2000 g=2000 b=2000
tc g2-3 gen_rand r=2    g=20   b=5978
tc g2-4 gen_rand r=5970 g=10   b=20
tc g2-5 gen_rand r=2    g=5997 b=1
tc g2-6 gen_rand r=1    g=3000 b=2999
tc g2-7 gen_rand r=2999 g=2    b=2999
tc g2-8 gen_rand r=2999 g=2999 b=2
tc g2-9 gen_rand r=2000 g=2000 b=2000 min_dist=100000000
tc g2-10 gen_rand r=2000 g=2000 b=2000 min_dist=1000000000
tc g2-11 gen_rand r=2    g=2999 b=2999 min_dist=1000000000
