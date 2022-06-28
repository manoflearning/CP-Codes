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

ll fac[202020];

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    fac[0] = 1;
    FOR(i, 1, 202020) fac[i] = i * fac[i - 1] % MOD;

	int tc; cin >> tc;
    while (tc--) {
        int n, s;
        cin >> n >> s;

        vt<ll> a(n), b(n), d, e;
        EACH(i, a) cin >> i;
        EACH(i, b) cin >> i;

        vt<pll> c(n + 1, { -1, -1 });
        FOR(n) c[a[i]].fr = i;
        FOR(n) {
            if (b[i] != -1) c[b[i]].sc = i; 
            else e.push_back(a[i]);
        }

        FOR(i, 1, n + 1) {
            if (c[i].sc == -1) d.push_back(i);
        }

        sort(all(d));
        sort(all(e));

        int bit = 0;
        FOR(i, 1, n + 1) {
            if (c[i].sc == -1) continue;
            if (c[i].sc - c[i].fr > s) bit = 1;
        }
        
        if (bit) {
            cout << 0 << '\n';
            continue;
        }

        vt<pll> res;
        FOR(sz(d)) {
            int r = upper_bound(all(e), d[i] + s) - e.begin() - 1;
            int l = lower_bound(all(e), d[i] - s) - e.begin();
            res.push_back({ l, r });
        }

        ll ans = 1, cnt = 0;
        EACH(i, res) ans = (ans * fac[i.sc - i.fr + 1]) % MOD;
        cout << ans << '\n';
    }

	return 0;
}