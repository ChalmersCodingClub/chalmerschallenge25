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

int n,k;
vi a;
int dp[61][61][61][61];

int solve(int p, array<int,4>& x){
    if(p == n) return 0;
    int *m = &dp[x[0]][x[1]][x[2]][x[3]];
    if(*m != -1) return *m;
    int ans = solve(p+1, x);
    for(int i = 0; i < 4; i++){
        if(x[i] == 0 || x[i] <= a[p]-k){
            array<int,4> y = x;
            y[i] = a[p];
            sort(all(y));
            ans = max(ans, 1+solve(p+1, y));
        }
    }
    *m = ans;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    a = vi(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    array<int,4> x{0,0,0,0};
    cout << solve(0, x) << "\n";
}
