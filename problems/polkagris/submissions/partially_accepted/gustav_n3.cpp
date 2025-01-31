#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << (#x) << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, m;
string s, t;

int dp[10000][10000];
int can_solve(int from, int to){
    if(from == 0 && to == n-1) return 1;
    if(dp[from][to] != -1) return dp[from][to];
    for(int i = 1; ; i++){
        if(from-i < 0 || from+i > to) break;
        if(s[from-i] != s[from+i]) break;
        if(can_solve(from-i, to)) return dp[from][to]=1;
    }
    for(int i = 1; ; i++){
        if(to+i >= n || to-i < from) break;
        if(s[to+i] != s[to-i]) break;
        if(can_solve(from, to+i)) return dp[from][to]=1;
    }
    return dp[from][to]=0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    cin >> s >> t;
    string u = t;
    reverse(all(u));
    for(int i = 0; i < n; i++){
        if((s.compare(i, m, t) == 0 || s.compare(i, m, u) == 0) && can_solve(i, i+m-1)){
            cout << "possible\n";
            return 0;
        }
    }
    cout << "impossible\n";
}