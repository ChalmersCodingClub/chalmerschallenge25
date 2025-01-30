#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <array>
#include <deque>
#include <bitset>
#include <immintrin.h>

using namespace std;


#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define nl "\n"
#define nf endl
#define ll long long
#define dl double long
#define uint unsigned int
#define pb push_back
#define _ << " " <<
#define mod 1'000'000'007
#define mp make_pair
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef multiset<ll> mll;
typedef pair<double, double> pdd;
typedef array<ll, 3> tripple;
double INF = 1e15;
ll n, t, s, m, sum, c;
vector<vector<ll>> grid;
map<pair<ll,pll>, double> fdist;

double dist(pll p1, pll p2) {
    return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> n;
    vector<vector<pll>> coords;
    coords.assign(3, vector<pll>());

    for (ll i = 0; i < n; i++)
    {
        char c;
        ll x, y, f = 0;
        cin >> x >> y >> c;      
        if (c == 'R') f = 0;
        else if (c == 'G') f = 1;
        else if (c == 'B') f = 2;
        fdist[{(f + 1) % 3, {x,y}}] = {INF};
        fdist[{(f + 2) % 3, {x,y}}] = {INF};
        coords[f].push_back({x,y});
    }

    for (ll col = 0; col < 3; col++)
    {
        for (ll next = col+1; next < 3; next++)
        {
            for (ll i = 0; i < coords[col].size(); i++)
            {
                for (ll j = 0; j < coords[next].size(); j++)
                {
                    pll p1 = coords[col][i];
                    pll p2 = coords[next][j];
                    double d1 = dist(p1, p2) + dist({ 0,0 }, p1);
                    double d2 = dist(p1, p2) + dist({ 0,0 }, p2);
                    fdist[{col, p2}] = min(fdist[{col, p2}],d1);
                    fdist[{next, p1}] = min(fdist[{next, p1}], d2);
                }
            }
        }
    }
    double ans = INF;
    for (ll col = 0; col < 3; col++)
    {
        for (pll p : coords[col]) {
            ll fl1 = (col + 1) % 3;
            ll fl2 = (col + 2) % 3;
            double d = fdist[{fl1, p}] + fdist[{fl2, p}];
            ans = min(ans, d);
        }
    }
    cout << fixed << setprecision(6) << ans << nl;



    
}
