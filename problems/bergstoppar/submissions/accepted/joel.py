import math

n = int(input())
h = int(input())

tops_after = []
tops_before = []

for i in range(n):
    line = input()
    x, y = [int(v) for v in line.split()]

    if x < 0:
        tops_before.append((-x, y - h))
    else:
        tops_after.append((x, y - h))

tops_after.sort()
tops_before.sort()

def check_num(tops):
    tops_in_vision = 0
    max_angle_seen = -math.inf
    for top in tops:
        angle = top[1] / top[0]
        if angle > max_angle_seen:
            tops_in_vision += 1
            max_angle_seen = angle
    
    return tops_in_vision

print(check_num(tops_before) + check_num(tops_after))

