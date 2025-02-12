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
const ll MOD1 = 1e4 + 7, MOD2 = 1e4 + 9;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, d;
vt<int> a;

ll f(int l, int r) {
    int res = 1, res2 = 1;
    EACH(i, a) {
        res &= (i == 0);
        res2 &= (i == 1);
    }
    if (res || res2) return (res ? 0 : 1);

    ll ret = INF;

    if (0 < l) ret = min(ret, f(l - 1, r));
    if (r < n - 1) ret = min(ret, f(l, r + 1));

    FOR(i, l, r + 1) a[i] = (a[i] + 1) % d;

    if (0 < l) ret = min(ret, f(l - 1, r) + 1);
    if (r < n - 1) ret = min(ret, f(l, r + 1) + 1);

    FOR(i, l, r + 1) a[i] = (a[i] + 1) % d;

    return ret;

    /*FOR(i, 0, l + 1) {
        FOR(j, r, n) {
            if (i == l && j == r) continue;
            ret = min(ret, f(i, j) + 1);
        }
    }*/
}

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

    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";

        cin >> n >> d;

        a.resize(n);
        EACH(i, a) cin >> i;

        ll ans = INF;
        FOR(l, 0, n) {
            FOR(r, l, n) {
                ll res = f(l, r);
                ans = min(ans, res);
            }
        }

        cout << ans << '\n';
    }

	return 0;
}