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
ll INF = 1e15;
ll n, k, s, m, sum, c;
vector<ll> blocks;
vector<vector<vector<vector<vector<ll>>>>> dp;

ll rek(ll a, ll b, ll c, ll d, ll i) {
    if (i == n+1) return 0;
    if (dp[a][b][c][d][i] != -INF) return dp[a][b][c][d][i];

    ll ans = 0;
    if (blocks[i] >= blocks[a] + k) ans = max(ans, 1 + rek(i, b, c, d, i + 1));
    if (blocks[i] >= blocks[b] + k) ans = max(ans, 1 + rek(a, i, c, d, i + 1));
    if (blocks[i] >= blocks[c] + k) ans = max(ans, 1 + rek(a, b, i, d, i + 1));
    if (blocks[i] >= blocks[d] + k) ans = max(ans, 1 + rek(a, b, c, i, i + 1));
    dp[a][b][c][d][i] = max(ans, rek(a, b, c, d, i + 1));
    return dp[a][b][c][d][i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> n >> k;
    blocks.assign(n+1, -INF);
    dp.assign(n+1, vector<vector<vector<vector<ll>>>>(n + 1, vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -INF)))));
    for (ll i = 0; i < n; i++) cin >> blocks[i+1];
    cout << rek(0, 0, 0, 0,1) << nl;

    
}
