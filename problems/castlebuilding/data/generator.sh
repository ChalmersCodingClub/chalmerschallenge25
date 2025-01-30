#!/bin/bash
REQUIRE_SAMPLE_REUSE=0 # Samples are not random permutations
. ../../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joshua.cpp

compile gen_rand.py

samplegroup
limits maxn=10
sample 1
sample 2
sample 3
sample 4

group group1 6
limits maxn=30
tc g1-1 gen_rand n=30 k=2
tc g1-2 gen_rand n=30 k=1
tc g1-3 gen_rand n=1 k=1
tc g1-4 gen_rand n=2 k=1
tc g1-5 gen_rand n=3 k=1
tc g1-6 gen_rand n=4 k=1
tc g1-7 gen_rand n=5 k=1
tc g1-8 gen_rand n=6 k=1
tc g1-9 gen_rand n=7 k=3

group group2 14
limits maxn=60
include_group group1
tc g2-1 gen_rand n=60 k=1
tc g2-2 gen_rand n=60 k=2
tc g2-3 gen_rand n=60 k=3
tc g2-4 gen_rand n=60 k=30

group group3 15
limits maxn=300
include_group group2
tc g3-1 gen_rand n=300 k=1
tc g3-2 gen_rand n=300 k=2
tc g3-3 gen_rand n=300 k=3
tc g3-4 gen_rand n=300 k=60
tc g3-5 gen_rand n=300 k=150

group group4 20
limits maxn=3000
include_group group3
tc g4-1 gen_rand n=3000 k=1
tc g4-2 gen_rand n=3000 k=2
tc g4-3 gen_rand n=3000 k=3
tc g4-4 gen_rand n=3000 k=150
tc g4-5 gen_rand n=3000 k=1500

group group5 25
limits maxn=20000
include_group group4
tc g5-1 gen_rand  n=20000 k=1
tc g5-2 gen_rand  n=20000 k=2
tc g5-3 gen_rand  n=20000 k=3
tc g5-4 gen_rand  n=20000 k=150
tc g5-5 gen_rand  n=20000 k=1500
tc g5-6 gen_rand  n=20000 k=10000
tc g5-7 gen_rand  n=20000 k=4
tc g5-8 gen_rand  n=20000 k=5
tc g5-9 gen_rand  n=20000 k=6
tc g5-10 gen_rand n=20000 k=50

group group6 20
limits maxn=100000
include_group group5
tc g6-1 gen_rand  n=100000 k=1
tc g6-2 gen_rand  n=100000 k=2
tc g6-3 gen_rand  n=100000 k=3
tc g6-4 gen_rand  n=100000 k=50
tc g6-5 gen_rand  n=100000 k=150
tc g6-6 gen_rand  n=100000 k=1500
tc g6-7 gen_rand  n=100000 k=10000
tc g6-8 gen_rand  n=100000 k=50000
tc g6-9 gen_rand  n=100000 k=6
tc g6-10 gen_rand n=100000 k=10
