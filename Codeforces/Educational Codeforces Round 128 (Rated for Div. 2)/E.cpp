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
        int n; cin >> n;

        vt<string> s(2);
        EACH(i, s) cin >> i;

        vt<vt<int>> a(2);
        int bit = 0;
        FOR(n) {
            if (s[0][i] == '*' || s[1][i] == '*') bit = 1;

            if (bit) {
                a[0].push_back((s[0][i] == '.' ? 0 : 1));
                a[1].push_back((s[1][i] == '.' ? 0 : 1));
            }
        }

        while (1) {
            if (a[0].back() == 1 || a[1].back() == 1) break;
            a[0].pop_back();
            a[1].pop_back();
        }

        n = sz(a[0]);

        vt<vt<int>> dp(2, vt<int>(n));

        dp[0][0] = a[1][0], dp[1][0] = a[0][0];
        FOR(i, 0, n - 1) {
            dp[0][i + 1] = dp[0][i] + 1 + a[1][i + 1];
            dp[1][i + 1] = dp[1][i] + 1 + a[0][i + 1];
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + 2);
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + 2);
        }

        cout << min(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

	return 0;
}