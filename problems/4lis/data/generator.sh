#!/bin/bash
. ../../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joshua.cpp

compile gen_rand.py
compile gen_almostsorted.py

samplegroup
limits maxn=10
sample 1
sample 2
sample 3

group group1 6
limits maxn=30
tc 1
tc 2
tc 3
tc g1-1 gen_rand n=30
tc g1-2 gen_rand n=30
tc g1-3 gen_rand n=1
tc g1-4 gen_rand n=2
tc g1-5 gen_rand n=3
tc g1-6 gen_rand n=4
tc g1-7 gen_rand n=5

group group2 14
limits maxn=60
include_group group1
tc g2-1 gen_rand n=60
tc g2-2 gen_rand n=60

group group3 15
limits maxn=300
include_group group2
tc g3-1 gen_rand n=300
tc g3-2 gen_rand n=300

group group4 20
limits maxn=3000
include_group group3
tc g4-1 gen_rand n=3000
tc g4-2 gen_rand n=3000

group group5 25
limits maxn=20000
include_group group4
tc g5-1 gen_rand n=20000
tc g5-2 gen_rand n=20000
tc g5-3 gen_rand n=20000
tc g5-4 gen_rand n=20000
tc g5-5 gen_rand n=20000
tc g5-6 gen_rand n=20000
tc g5-7 gen_rand n=20000
tc g5-8 gen_rand n=20000
tc g5-9 gen_rand n=20000
tc g5-10 gen_rand n=20000

group group6 20
limits maxn=100000
include_group group5
tc g6-1 gen_rand n=100000
tc g6-2 gen_rand n=100000
tc g6-3 gen_rand n=100000
tc g6-4 gen_rand n=100000
tc g6-5 gen_rand n=100000
tc g6-6 gen_rand n=100000
tc g6-7 gen_rand n=100000
tc g6-8 gen_rand n=100000
tc g6-9 gen_rand n=100000
tc g6-10 gen_rand n=100000
