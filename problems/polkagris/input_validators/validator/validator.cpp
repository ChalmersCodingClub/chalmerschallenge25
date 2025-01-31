#include <bits/stdc++.h>
#include "validator.h"


using namespace std;

void run() {
    int MAXN = Arg("maxn");

    int n = Int(1, MAXN);
    Space();

    int t = Int(1, n);
    Endl();

    string initial = Line();
    string target = Line();

    Eof();

    assert(initial.size() == n);
    assert(target.size() == t);
    for(char c : initial) assert('A' <= c && c <= 'Z');
    for(char c : target) assert('A' <= c && c <= 'Z');
    for (int i = 1; i < initial.size(); i++) {
        assert(initial[i-1] != initial[i]);
    }
    for (int i = 1; i < target.size(); i++) {
        assert(target[i-1] != target[i]);
    }
}
