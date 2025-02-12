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
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

ll n, dn, ans, p10[17];

void f(ll x, int d, int bit) {
    if (x > n || d > dn) return;

    if (bit && n % x == 0) ans++;

    FOR(i, 10) {
        f(x * 10 + (p10[d + 1] + 1) * i, d + 2, i > 0);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    // freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    // freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    p10[0] = 1;
    FOR(i, 1, 17) p10[i] = 10 * p10[i - 1];

	int tc; cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";

        cin >> n;
        
        for (dn = 0; p10[dn] <= n; dn++);

        ans = 0;

        for (int i = 0; i < 10; i++) {
            f(i, 1, i > 0);
            f(11 * i, 2, i > 0);
        }

        cout << ans << '\n';
    }

	return 0;
}