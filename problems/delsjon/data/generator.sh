#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution joshua.cpp

compile gen_dumbbell.py
compile gen_path.py
compile gen_rand.py
compile gen_starry.py
compile gen_errichto.py

samplegroup
limits maxdist=10
sample 1
sample 2

group group1 50
limits maxdist=100
include_group sample
tc g1-1 gen_rand n=100
tc g1-2 gen_rand n=100
tc g1-3 gen_dumbbell n=100
tc g1-4 gen_starry n=100 k=1
tc g1-5 gen_starry n=100 k=0.5
tc g1-6 gen_starry n=100 k=0.1
tc g1-7 gen_errichto n=100 lo=0.3 hi=0.5
tc g1-8 gen_errichto n=100 lo=0.7 hi=0.9
tc g1-9 gen_errichto n=100 lo=0.45 hi=0.5
tc g1-10 gen_errichto n=100 lo=0.999999 hi=1
tc g1-11 gen_path n=100 l=1
tc g1-12 gen_path n=100 l=5
tc g1-13 gen_path n=100 l=25
tc g1-14 gen_rand n=5
tc g1-15 gen_rand n=10
tc g1-16 gen_rand n=20

group group2 50
limits maxdist=1000
include_group group1
tc g2-1 gen_rand n=1000
tc g2-2 gen_rand n=1000
tc g2-3 gen_dumbbell n=1000
tc g2-4 gen_starry n=1000 k=1
tc g2-5 gen_starry n=1000 k=0.5
tc g2-6 gen_starry n=1000 k=0.1
tc g2-7 gen_errichto n=1000 lo=0.3 hi=0.5
tc g2-8 gen_errichto n=1000 lo=0.7 hi=0.9
tc g2-9 gen_errichto n=1000 lo=0.45 hi=0.5
tc g2-10 gen_errichto n=1000 lo=0.999999 hi=1
tc g2-11 gen_path n=1000 l=1
tc g2-12 gen_path n=1000 l=20
tc g2-13 gen_path n=1000 l=200
