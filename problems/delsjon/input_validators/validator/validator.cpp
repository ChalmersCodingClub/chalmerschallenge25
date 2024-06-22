#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void run() {
    int k = Int(3, 1000);
    Endl();

    int maxd = Arg("maxd");

    rep(i,0,k)
    {
        SpacedInts(k, 0, maxd);
    }

    Eof();
}

