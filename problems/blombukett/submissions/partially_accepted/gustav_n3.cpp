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
    for(flower f1 : a){
        for(flower f2 : a){
            if(f1.c == f2.c) continue;
            for(flower f3 : a){
                if(f3.c == f1.c || f3.c == f2.c) continue;
                ans = min(ans, dist(0,0,f1.x,f1.y) + dist(f1.x,f1.y,f2.x,f2.y) + dist(f2.x,f2.y,f3.x,f3.y) + dist(f3.x,f3.y,0,0));
            }
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
