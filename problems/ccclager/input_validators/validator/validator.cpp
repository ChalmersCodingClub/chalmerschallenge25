#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

void run() {
    int room = Arg("room", (int)1e9);

    int n = Int(1, Arg("maxn", 100000));
    Space();
    int m = Int(0, Arg("maxm", 100000));
    Endl();

    for (int i = 0; i < n; i++) {
        string name = _token();
        Space();
        int pos = Int(0, room);
        assert(3 <= name.size() && name.size() <= 10);
        assert(isupper(name[0]));
        for (int j = 1; j < name.size(); j++) assert(islower(name[j]));
        Endl();
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        a = Int(0, room);
        Space();
        b = Int(a, room);
        Endl();
    }

    Eof();
}

