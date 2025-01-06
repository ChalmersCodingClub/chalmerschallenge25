#!/bin/bash
. ../../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joel.cpp

compile gen_rand.py

samplegroup
limits maxn=10 maxh=100 minx=-100 maxx=100
sample 1
sample 2
sample 3

group group1 10
limits maxn=2 maxh=10000 minx=1 maxx=10000
tc 1
tc 2
tc 3
tc g1-1 gen_rand n=1 max_h=10000 min_x=1 max_x=10000
tc g1-2 gen_rand n=1 max_h=10000 min_x=1 max_x=10000
tc g1-3 gen_rand n=2 max_h=10000 min_x=1 max_x=10000
tc g1-4 gen_rand n=2 max_h=10000 min_x=1 max_x=10000
tc g1-5 gen_rand n=2 max_h=10000 min_x=1 max_x=10000
tc g1-6 gen_rand n=2 max_h=10000 min_x=1 max_x=10000
tc g1-7 gen_rand n=2 max_h=10000 min_x=1 max_x=10000
tc g1-8 gen_rand n=2 max_h=10000 min_x=1 max_x=10000

group group2 60
limits maxn=10000 maxn=2 maxh=10000 minx=1 maxx=10000
include_group group1
tc g2-1 gen_rand n=10 max_h=10000 min_x=1 max_x=10000
tc g2-2 gen_rand n=100 max_h=10000 min_x=1 max_x=10000
tc g2-3 gen_rand n=1000 max_h=10000 min_x=1 max_x=10000
tc g2-4 gen_rand n=10000 max_h=10000 min_x=1 max_x=10000

group group3 30
limits maxn=10000 maxn=2 maxh=10000 minx=-10000 maxx=10000
include_group group2
tc g3-1 gen_rand n=10 max_h=10000 min_x=-10000 max_x=10000
tc g3-2 gen_rand n=100 max_h=10000 min_x=-10000 max_x=10000
tc g3-3 gen_rand n=1000 max_h=10000 min_x=-10000 max_x=10000
tc g3-4 gen_rand n=10000 max_h=10000 min_x=-10000 max_x=10000

