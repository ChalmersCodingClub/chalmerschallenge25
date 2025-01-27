#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution hugo.cpp

compile gen_random.py
compile gen_weird.py

samplegroup
sample 1
sample 2

group group01
limits maxn=100 maxm=100 room=1000
tc 1
tc 2
include_group sample

tc g1-1  gen_random n=10 m=10 room_size=100
tc g1-2  gen_random n=50 m=10 room_size=200
tc g1-3  gen_random n=100 m=100 room_size=1000
tc g1-4  gen_random n=50 m=30 room_size=150
tc g1-5  gen_random n=10 m=10 room_size=100
tc g1-6  gen_random n=50 m=10 room_size=200
tc g1-7  gen_weird n=99 spacing=1
tc g1-8  gen_random n=50 m=30 room_size=150
tc g1-9  gen_random n=10 m=10 room_size=100
tc g1-10  gen_random n=50 m=10 room_size=200

group group02
limits maxm=100 room=100000
include_group group01
tc g2-1  gen_random  n=100000 m=10 room_size=10000
tc g2-2  gen_random  n=100000 m=10 room_size=50000
tc g2-3  gen_random  n=100000 m=100 room_size=100000
tc g2-4  gen_random  n=100000 m=30 room_size=5000
tc g2-5  gen_random  n=100000 m=10 room_size=13000
tc g2-6  gen_random  n=100000 m=10 room_size=100000
tc g2-7  gen_weird n=99 spacing=100
tc g2-8  gen_random  n=100000 m=30 room_size=50000
tc g2-9  gen_random  n=100000 m=10 room_size=75000
tc g2-10  gen_random n=100000 m=10 room_size=97000

group group03
limits room=100000
include_group group02
tc g3-1  gen_random  n=100000 m=100000 room_size=100000
tc g3-2  gen_random  n=100000 m=50000 room_size=100000
tc g3-3  gen_random  n=100000 m=25000 room_size=100000
tc g3-4  gen_random  n=100000 m=50000 room_size=100000
tc g3-5  gen_weird n=49999 spacing=1

group group04
include_group group03
tc g4-1  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-2  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-3  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-4  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-5  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-6  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-7  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-8  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-9  gen_random  n=100000 m=100000 room_size=1000000000
tc g4-10 gen_random  n=100000 m=100000 room_size=1000000000
tc g4-11  gen_weird n=49999 spacing=100
