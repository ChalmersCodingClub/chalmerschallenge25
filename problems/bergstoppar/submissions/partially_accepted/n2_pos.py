import math

n = int(input())
h = int(input())

tops = []

for i in range(n):
    line = input()
    coord = tuple(int(v) for v in line.split())

    tops.append((coord[0], coord[1] - h))

def in_vision(top, tops):
    angle_to_top = top[1] / abs(top[0])
    top_x = top[0]
    is_visible = True

    for other_top in tops:
        if top == other_top:
            continue
        if abs(top_x) < abs(other_top[0]): #Peak further away can't block sight
            continue

        angle_to_other_top = other_top[1] / abs(other_top[0])

        
        if angle_to_other_top >= angle_to_top:
            is_visible = False
            break

    return is_visible

tops_visible = 0
for top in tops:
    if in_vision(top, tops):
        tops_visible += 1

print(tops_visible)


