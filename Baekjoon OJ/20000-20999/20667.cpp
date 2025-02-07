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

int n, m, k;
int cpu[101], mem[101], pri[101];
ll dp[101][505][1010];

void init() {
    FOR(101) {
        FOR(j, 505) {
            FOR(k, 1010) {
                dp[i][j][k] = -INF;
            }
        }
    }
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> cpu[i] >> mem[i] >> pri[i];
    }
}

ll f(int idx, int psum, int csum) {
    ll& ret = dp[idx][psum][csum];
    if (ret != -INF) return ret;
    if (idx == n) {
        if (csum > 0) return ret = -INF + 1;
        else return ret = 0;
    }

    ret = f(idx + 1, psum, csum);
    if (psum >= pri[idx]) 
        ret = max(ret, mem[idx] + f(idx + 1, psum - pri[idx], max(0, csum - cpu[idx])));

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();

    input();

    for (int i = 0; i <= 5 * n; i++) {
        if (f(0, i, m) >= k) {
            cout << i;
            return 0;
        }
    }

    cout << -1;

	return 0;
}