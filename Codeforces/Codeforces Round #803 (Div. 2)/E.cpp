#define _USE_MATH_DEFINES
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
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 998244353;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
    while (tc--) {
        int n, s;
        cin >> n >> s;

        vt<pii> a(n + 1);
        vt<int> vi(n + 1);

        FOR(i, 1, n + 1) cin >> a[i].fr;
        FOR(i, 1, n + 1) {
            cin >> a[i].sc;
            if (a[i].sc != -1) vi[a[i].sc] = 1;
        }

        vt<int> missing;
        FOR(i, 1, n + 1) {
            if (!vi[i]) missing.push_back(i);
        }

        sort(a.begin() + 1, a.end(), [&](const pii& a, const pii& b) {
            return a.sc < b.sc;
        });

        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].sc != -1) {
                mx = max(mx, a[i].fr - a[i].sc);
            }
        }

        if (mx > s) {
            cout << 0 << '\n';
            continue;
        }

        vt<int> cnts;
        for (int i = 1; i <= n; i++) {
            if (a[i].sc == -1) {
                cnts.push_back(missing.end() - lower_bound(all(missing), a[i].fr - s));
            }
        }

        sort(all(cnts));
        ll res = 1;
        FOR(sz(cnts)) {
            res = (res * (cnts[i] - i)) % MOD;
        }
        cout << res << '\n';
    }

	return 0;
}