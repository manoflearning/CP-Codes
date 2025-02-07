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

int n;
vector<ll> p, q, r, s;

ll f(vector<ll> a) {
    sort(all(a));

    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ret += 2 * (2 * (i + 1) - 1 - n) * a[i];
    }

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
    p.resize(n);
    q.resize(n);
    for (auto& i : p) cin >> i;
    for (auto& i : q) cin >> i;

    for (int i = 0; i < n; i++) {
        r.push_back(p[i] + q[i]);
        s.push_back(p[i] - q[i]);
    }

    cout << f(p) + f(q) - f(r) / 2 - f(s) / 2;

	return 0;
}