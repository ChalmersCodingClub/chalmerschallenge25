N, M = map(int, input().split())
ppl_pos = [input().split() for _ in range(N)]
curtains = [input().split() for _ in range(M)]
wakes = [True] * 100001
woken = 0
for i in range(M):
    a, b = map(int, curtains[i])

    for j in range(a,b+1):
        wakes[j] = False

for i in range(N):
    y = int(ppl_pos[i][1])

    if wakes[y]:
        woken += 1 if ppl_pos[i][0] not in {"Joshua", "Gustav"} else 2

print(woken)