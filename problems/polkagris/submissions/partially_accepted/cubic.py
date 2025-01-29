N, T = [int(x) for x in input().split()]
initial = input()
target = input()

# whether initial can be folded into initial[l:r+1]
memo = {}
def dp(l,r):
    if l == 0 and r == len(initial)-1: return True
    if (l,r) in memo: return memo[l,r]
    k = r-l+1
    for i in range(1,k):
        assert l+i <= r
        if (l-i < 0) or initial[l+i] != initial[l-i]: break
        if dp(l-i,r):
            memo[l,r] = True
            return True
    for i in range(1,k):
        assert r-i >= l
        if (r+i >= len(initial)) or initial[r-i] != initial[r+i]: break
        if dp(l,r+i):
            memo[l,r] = True
            return True
    memo[l,r] = False
    return False

def possible(target):
    for l in range(len(initial)-len(target)+1):
        r = l+len(target)-1
        if initial[l:r+1] == target and dp(l,l+len(target)-1):
            return True
    return False

if possible(target) or possible(target[::-1]):
    print("possible")
else:
    print("impossible")
