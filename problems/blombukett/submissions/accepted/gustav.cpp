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

struct flower{
    ll x, y;
    int c;
};

double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<flower> a;
    for(int i = 0; i < n; i++){
        ll x, y;
        char c;
        cin >> x >> y >> c;
        a.push_back({x, y, c=='R'?0:c=='G'?1:2});
    }
    double ans = linf;
    for(flower m : a){
        vector<double> c(3, linf);
        for(flower f : a){
            c[f.c] = min(c[f.c], dist(0,0,f.x,f.y) + dist(f.x,f.y,m.x,m.y));
        }
        c[m.c] = 0;
        ans = min(ans, c[0]+c[1]+c[2]);
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
