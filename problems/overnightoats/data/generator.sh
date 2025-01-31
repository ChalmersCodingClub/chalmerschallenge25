#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../../testdata_tools/gen.sh

use_solution julia.py

compile generate.py

samplegroup
limits maxn=10
sample 1
sample 2

group group01 41
limits maxn=1000
include_group sample
tc g1-1 generate maxn=1000 kind=1
tc g1-2 generate maxn=1000 kind=1
tc g1-3 generate maxn=1000 kind=1
tc g1-4 generate maxn=1000 kind=2
tc g1-5 generate maxn=1000 kind=2
tc g1-6 generate maxn=1000 kind=2
tc g1-7 generate maxn=1000 kind=3
tc g1-8 generate maxn=1000 kind=3
tc g1-9 generate maxn=1000 kind=3
tc g1-10 generate maxn=1000 kind=4

group group02 59
limits maxn=300000
include_group group01
tc g2-1 generate maxn=300000 kind=1
tc g2-2 generate maxn=300000 kind=1
tc g2-3 generate maxn=300000 kind=1
tc g2-4 generate maxn=300000 kind=2
tc g2-5 generate maxn=300000 kind=2
tc g2-6 generate maxn=300000 kind=2
tc g2-7 generate maxn=300000 kind=3
tc g2-8 generate maxn=300000 kind=3
tc g2-9 generate maxn=300000 kind=3
tc g2-10 generate maxn=300000 kind=4
