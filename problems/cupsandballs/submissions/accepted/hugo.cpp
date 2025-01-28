#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, g;
    cin >> g >> n;

    int cups[3] = {0,1,0};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        swap(cups[a-1], cups[b-1]);
    }
    
    for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) if (a != b) {
        swap(cups[a], cups[b]);
        if (cups[g-1]) {
            cout << a+1 << " " << b+1 << "\n";
        }
        swap(cups[a], cups[b]);
    }
}
