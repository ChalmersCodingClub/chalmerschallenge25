#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, g;
    judge_in >> g >> n;

    int cups[3] = {0,1,0};
    for (int i = 0; i < n; i++) {
        int a, b;
        judge_in >> a >> b;
        swap(cups[a-1], cups[b-1]);
    }

    int a, b;
    author_out >> a >> b;
    if (a == b || a < 1 || b < 1 || a > 3 || b  > 3) {
        wrong_answer("Invalid input");
    }
    swap(cups[a-1], cups[b-1]);
    if (!cups[g-1]) wrong_answer("Ball was not under the correct cup");

    accept();
}
