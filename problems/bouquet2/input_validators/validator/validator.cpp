#include <bits/stdc++.h>
#include "validator.h"


using namespace std;

void run() {
    int MAXN = Arg("maxn");

    int n = Int(3, MAXN);
    Endl();
    
	set<char> seen;
	set<pair<int,int>> pos;
    for (int i = 0; i < n; i++)
    {
        int x = Int(-1000000000, 1000000000);
        Space();
        int y = Int(-1000000000, 1000000000);
		assert(!pos.count({x,y}));
		pos.emplace(x, y);
		Space();
		char c = Char();
		assert(c == 'R' || c == 'G' || c == 'B');
		seen.insert(c);
        Endl();
    }
	assert(seen.size() == 3);

    Eof();
}
