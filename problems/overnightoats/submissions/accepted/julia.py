from collections import deque

def solve():

    N = int(input())
    X = int(input())
    actions = []
    for i in range(N):
        actions.append(input())

    queue = deque()

    for day in range(N):
        action = actions[day]

        while queue and queue[0] + X <= day:
            queue.popleft()
            print("ono..")
            return

        if action == "ADD":
            queue.append(day)
        elif action == "EAT":
            if queue:
                queue.popleft()

    print("yay!")

solve()
