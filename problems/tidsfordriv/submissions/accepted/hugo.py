from itertools import chain
ranks = [*chain(map(str,range(2, 11)), "AJQK")]
cnt = {r:4 for r in ranks}
n = int(input())

for _ in range(n):
    r = input()[:-1]
    cnt[r] -= 1

print(f"{100*max(cnt.values()) / (52-n):.0f}%")
