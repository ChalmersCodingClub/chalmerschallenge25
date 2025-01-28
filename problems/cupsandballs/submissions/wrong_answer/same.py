ball = 2
hugo_guess = int(input())
for i in range(int(input())):
    swap1, swap2 = map(int, input().split())
    if ball == swap1:
        ball = swap2
    elif ball == swap2:
        ball = swap1

if ball == hugo_guess:
    print(ball, ball)
else:
    print(hugo_guess, ball)
