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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> n >> k;
    vector<ll> v;
    ll p = 0;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "ADD") v.push_back(i);
        if (p < v.size() && i - v[p] > k) {
            cout << "ono.." << nl;
            exit(0);
        }
        else if (s == "EAT") p++;
    }
    cout << "yay!" << nl;
    
}
