#!/usr/bin/env bash
. ../../../testdata_tools/gen.sh

use_solution loke.cpp

compile gen.py

samplegroup
limits maxn=20
sample 1
sample 2
sample 3
sample 4
sample 5
sample 6

group group1 27
limits maxn=100
include_group sample
tc g1-01 gen kind=1 maxn=10 alph=3
tc g1-02 gen kind=2 maxn=10 alph=3
tc g1-03 gen kind=3 maxn=10 alph=3
tc g1-04 gen kind=4 maxn=10 alph=3
tc g1-05 gen kind=5 maxn=10 alph=3
tc g1-06 gen kind=4 maxn=10 alph=5
tc g1-07 gen kind=5 maxn=10 alph=5
tc g1-08 gen kind=4 maxn=100 alph=3
tc g1-09 gen kind=4 maxn=100 alph=5
tc g1-10 gen kind=4 maxn=100 alph=26
tc g1-11 gen kind=5 maxn=100 alph=3
tc g1-12 gen kind=5 maxn=100 alph=5
tc g1-13 gen kind=5 maxn=100 alph=26
tc g1-14 gen kind=6 maxn=100 alph=3
tc g1-15 gen kind=6 maxn=100 alph=3
tc g1-16 gen kind=6 maxn=100 alph=4
tc g1-17 gen kind=7 maxn=100 alph=3
tc g1-18 gen kind=7 maxn=100 alph=3

group group2 31
limits maxn=10000
include_group group1
tc g2-01 gen kind=2 maxn=10000 alph=3
tc g2-02 gen kind=3 maxn=10000 alph=3
tc g2-03 gen kind=4 maxn=10000 alph=3
tc g2-04 gen kind=4 maxn=10000 alph=3
tc g2-05 gen kind=4 maxn=10000 alph=5
tc g2-06 gen kind=4 maxn=10000 alph=26
tc g2-07 gen kind=5 maxn=10000 alph=3
tc g2-08 gen kind=5 maxn=10000 alph=3
tc g2-09 gen kind=5 maxn=10000 alph=5
tc g2-10 gen kind=5 maxn=10000 alph=26
tc g2-11 gen kind=6 maxn=10000 alph=3
tc g2-12 gen kind=6 maxn=10000 alph=3
tc g2-13 gen kind=6 maxn=10000 alph=5
tc g2-14 gen kind=6 maxn=10000 alph=26
tc g2-15 gen kind=7 maxn=10000 alph=3
tc g2-16 gen kind=7 maxn=10000 alph=3

group group3 42
limits maxn=10000000
include_group group2
tc g3-01 gen kind=2 maxn=10000000 alph=3
tc g3-02 gen kind=3 maxn=10000000 alph=3
tc g3-03 gen kind=4 maxn=10000000 alph=3
tc g3-04 gen kind=4 maxn=10000000 alph=3
tc g3-05 gen kind=4 maxn=10000000 alph=3
tc g3-06 gen kind=4 maxn=10000000 alph=5
tc g3-07 gen kind=4 maxn=10000000 alph=26
tc g3-08 gen kind=5 maxn=10000000 alph=3
tc g3-09 gen kind=5 maxn=10000000 alph=3
tc g3-10 gen kind=5 maxn=10000000 alph=3
tc g3-11 gen kind=5 maxn=10000000 alph=5
tc g3-12 gen kind=5 maxn=10000000 alph=26
tc g3-13 gen kind=6 maxn=10000000 alph=3
tc g3-14 gen kind=6 maxn=10000000 alph=3
tc g3-15 gen kind=6 maxn=10000000 alph=3
tc g3-16 gen kind=6 maxn=10000000 alph=5
tc g3-17 gen kind=6 maxn=10000000 alph=26
tc g3-18 gen kind=7 maxn=10000000 alph=3
tc g3-19 gen kind=7 maxn=10000000 alph=3
