def solve():

    actions = []
    N = int(input())
    X = int(input())
    for _ in range(N):
        actions.append(input())

    fridge = []

    for day in range(N):
        action = actions[day]

        if action == "ADD":
            fridge.append(day)
        elif action == "EAT":
            if fridge[0] + X < day:
                print("ono..")
                return
            fridge = fridge[1:]

    print("yay!")

solve()
