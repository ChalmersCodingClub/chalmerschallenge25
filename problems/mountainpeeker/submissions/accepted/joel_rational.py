#!/usr/bin/python3
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
    max_angle_seen_y = -math.inf
    max_angle_seen_x = 1
    for top in tops:
        angle_y = top[1]
        angle_x = top[0]
        if angle_y * max_angle_seen_x > max_angle_seen_y * angle_x: #Same as angle > max_angle_seen, but using integers
            tops_in_vision += 1
            max_angle_seen_y = angle_y
            max_angle_seen_x = angle_x
    
    return tops_in_vision

print(check_num(tops_before) + check_num(tops_after))

