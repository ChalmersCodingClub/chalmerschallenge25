#!/usr/bin/python3
n = int(input());
h = int(input());

assert n == 2;

x_1, y_1 = [int(d) for d in input().split()]
x_2, y_2 = [int(d) for d in input().split()]

if x_2 < x_1:
    temp = x_2
    x_2 = x_1
    x_1 = temp

    temp = y_2
    y_2 = y_1
    y_1 = temp

y_1 -= h
y_2 -= h

r_1 = y_1 / x_1
r_2 = y_2 / x_2

if(r_1 >= r_2):
    print(1)
else:
    print(2)

