from collections import deque

def solve():

    N = int(input())
    X = int(input())
    actions = []
    for _ in range(N):
        actions.append(input())

    queue = deque()

    for day in range(N):
        action = actions[day]


        if action == "ADD":
            queue.append(day)
        elif action == "EAT":
            if queue.popleft() + X + 1 < day:
                print("ono..")
                return

    print("yay!")

solve()
