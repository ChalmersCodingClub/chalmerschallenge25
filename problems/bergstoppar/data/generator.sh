#!/bin/bash
. ../../../testdata_tools/gen.sh

#ulimit -s unlimited
use_solution joel.py

MAX_X=50000
MAX_H=8848

compile gen_rand.py
compile gen_evil.py
compile gen_eviler.py

samplegroup
limits maxn=10 maxh=100 minx=-100 maxx=100
sample 1
sample 2
sample 3
sample 4

group group1 10
limits maxn=2 maxh=$MAX_H minx=1 maxx=$MAX_X
tc 1
tc g1-1 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g1-2 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g1-3 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g1-4 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g1-5 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g1-6 gen_rand n=2 max_h=$MAX_H min_x=1 max_x=$MAX_X

group group2 30
limits maxn=1000 maxh=$MAX_H minx=1 maxx=$MAX_X
include_group group1
tc 2
tc g2-1 gen_rand n=100 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g2-2 gen_rand n=1000 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g2-3 gen_evil n=1000 max_h=$MAX_H min_x=1 max_x=$MAX_X
tc g2-4 gen_eviler n=1000 max_h=$MAX_H min_x=1 max_x=$MAX_X

group group3 10
limits maxn=1000 maxh=$MAX_H minx=-$MAX_X maxx=$MAX_X
include_group group2
tc 2
tc g3-1 gen_rand n=100 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g3-2 gen_rand n=1000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g3-3 gen_evil n=1000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g3-4 gen_eviler n=1000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X

group group4 50
limits maxn=20000 maxh=$MAX_H minx=-$MAX_X maxx=$MAX_X
include_group group3
tc 3
tc 4
tc g4-1 gen_rand n=10000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g4-2 gen_rand n=20000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g4-3 gen_evil n=20000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X
tc g4-4 gen_eviler n=20000 max_h=$MAX_H min_x=-50000 max_x=$MAX_X

