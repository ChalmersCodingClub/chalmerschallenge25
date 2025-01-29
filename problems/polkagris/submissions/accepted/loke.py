#!/usr/bin/python3

# Translated from kactl c++ :)
def pi(s):
    p = [0]*len(s)
    for i in range(1,len(s)):
        g = p[i-1]
        while (g > 0 and s[i] != s[g]): g = p[g-1]
        p[i] = g + (s[i] == s[g])
    return p
def match(s, pat):
    p = pi(pat + "\0" + s)
    res = []
    for i in range(len(p)-len(s), len(p)):
        if p[i] == len(pat): res.append(i - 2 * len(pat))
    return res
def manacher(s):
    n = len(s)
    p = [0]*n
    l = 0
    r = 0
    for i in range(n):
        t = r-i
        if i<r: p[i] = min(t, p[l+t])
        L = i-p[i]
        R = i+p[i]
        while L>=1 and R+1<n and s[L-1] == s[R+1]:
            p[i] += 1
            L -= 1
            R += 1
        if R>r:
            l=L
            r=R
    return p

N, T = [int(x) for x in input().split()]
initial = input()
target = input()

palindrome_width = manacher(initial); # todo

dp_rcut_prefix_sum = [0]*(N+1)
dp_lcut_prefix_sum = [0]*(N+1)
for lcut in range(N):
    if lcut == 0 or dp_lcut_prefix_sum[lcut] > dp_lcut_prefix_sum[lcut - palindrome_width[lcut]]:
        dp_lcut_prefix_sum[lcut+1] = dp_lcut_prefix_sum[lcut] + 1
    else:
        dp_lcut_prefix_sum[lcut+1] = dp_lcut_prefix_sum[lcut]

for rcut in range(N):
    if rcut == 0 or dp_rcut_prefix_sum[rcut] > dp_rcut_prefix_sum[rcut - palindrome_width[N-1 - rcut]]:
        dp_rcut_prefix_sum[rcut+1] = dp_rcut_prefix_sum[rcut] + 1
    else:
        dp_rcut_prefix_sum[rcut+1] = dp_rcut_prefix_sum[rcut]

for lcut in match(initial, target) + match(initial, target[::-1]):
    rcut = len(initial) - len(target) - lcut
    if (dp_rcut_prefix_sum[rcut+1] > dp_rcut_prefix_sum[rcut] and
        dp_lcut_prefix_sum[lcut+1] > dp_lcut_prefix_sum[lcut]):
        print("possible")
        exit()
print("impossible")
