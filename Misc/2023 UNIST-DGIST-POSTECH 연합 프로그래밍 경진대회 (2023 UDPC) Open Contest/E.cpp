//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, k;
vector<ll> a1, a2, a3;

ll f(vector<ll> x, vector<ll> y) {
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = x[i] + y[i];
    }

    sort(a.rbegin(), a.rend());
    ll ret = 0;
    for (int i = 0; i < k; i++) ret += a[i];
    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
    a1.resize(n);
    a2.resize(n);
    a3.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> a1[i] >> a2[i] >> a3[i];

    ll ans = f(a1, a2);
    ans = max(ans, f(a1, a3));
    ans = max(ans, f(a2, a3));

    cout << ans;

	return 0;
}