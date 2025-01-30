#!/usr/bin/python3
N, M = map(int, input().split())
ppl_pos = [input().split() for _ in range(N)]
curtains = [input().split() for _ in range(M)]
woken = 0


for i in range(N):
    woken_pers = True
    for j in range(M):
        a, b = map(int, curtains[j])
        y = int(ppl_pos[i][1])

        if a <= y <= b:
            woken_pers = False
            break
    if woken_pers:
        woken += 1 if ppl_pos[i][0] not in {"Joshua", "Gustav"} else 2

print(woken)