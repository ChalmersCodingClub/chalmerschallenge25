#include "validator.h"

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

void run() {
    int room = Arg("room", (int)1e9);

    int n = Int(1, Arg("maxn", 200000));
    Space();
    int m = Int(0, Arg("maxm", 200000));
    Endl();

    unordered_set<string> names;
    for (int i = 0; i < n; i++) {
        string name = _token();
        if (names.find(name) != names.end()) {
            die("Input may not contain duplicate names: \"" + name + "\"");
        }
        names.emplace(name);
        Space();
        int pos = Int(0, room);
        if (!(3 <= name.size() && name.size() <= 10)) die("Name: \"" + name + "\" has an invalid length (" + to_string(name.size()) + " characters");
        if (!isupper(name[0])) die("Name: \"" + name + "\" does not have a capitalized first letter");
        for (int j = 1; j < name.size(); j++) if (!islower(name[j])) {
            die("Name: \"" + name + "\" has uppercase letters that is not the first letter");
        }
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

