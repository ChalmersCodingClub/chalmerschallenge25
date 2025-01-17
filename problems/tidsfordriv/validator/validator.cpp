#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

void run() {
    int max_n = Arg("max_n");

    int n = Int(0, max_n);
    Endl();
    set<string> seen;
    set<string> ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    set<char> suites = {'C', 'S', 'H', 'D'};
    for (int i = 0; i < n; i++) {
        string s = Line();
        assert(!seen.count(s) && "All cards in input should be unique!");
        assert(ranks.count(s.substr(0, s.size() - 1)) && "Card has invalid rank!");
        assert(suites.count(s[s.size()-1]) && "Card has invalid suite!");
        seen.emplace(s);
    }

    Eof();
}

