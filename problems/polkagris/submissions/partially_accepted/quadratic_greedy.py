N, T = [int(x) for x in input().split()]
initial = input()
target = input()

dp_rcut = [False]*N
dp_lcut = [False]*N

dp_rcut[0] = True
dp_lcut[0] = True

for lcut in range(N):
    i = 1
    while True:
        if lcut-i<0 or lcut+i >= N or initial[lcut-i] != initial[lcut+i]: break
        if dp_lcut[lcut-i]:
            dp_lcut[lcut] = True
            break
        i += 1
for rcut in range(N):
    i = 1
    while True:
        r = N-1-rcut
        if r-i<0 or r+i >= N or initial[r-i] != initial[r+i]: break
        if dp_rcut[rcut-i]:
            dp_rcut[rcut] = True
            break
        i += 1
for _ in range(2):
    for lcut in range(len(initial)-len(target)+1):
        if initial[lcut:lcut+len(target)] != target: continue
        rcut = len(initial) - len(target) - lcut
        if dp_rcut[rcut] and dp_lcut[lcut]:
            print("possible")
            exit()
    target = target[::-1]
print("impossible")
