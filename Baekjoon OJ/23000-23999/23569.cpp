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

int n, m;
int adj[1010][1010], bit[1010];
int cnt0, cnt1, imp;
vt<ll> res;

int dp[1010][2020];

void init() {
    memset(bit, -1, sizeof(bit));
    FOR(1010) FOR(j, 2020) dp[i][j] = -INF;
}

void input() {
    cin >> n >> m;
    FOR(i, 1, n + 1) {
        FOR(j, i + 1, n + 1) {
            adj[i][j] = adj[j][i] = 1;
        }
    }

    FOR(m) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 0;
    }
}

void dfs(int v, int b) {
    bit[v] = b;
    if (b) cnt1++;
    else cnt0++;

    for (int i = 1; i <= n; i++) {
        if (!adj[v][i]) continue;

        if (bit[i] == -1) dfs(i, !b);
        else if (bit[i] == b) imp = 1;
    }
}

int f(int v, int sum) {
    int& ret = dp[v][sum + 1010];
    if (ret != -INF) return ret;
    if (v == sz(res)) return ret = abs(sum);

    ret = INF;
    ret = min(ret, f(v + 1, sum + res[v]));
    ret = min(ret, f(v + 1, sum - res[v]));

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

    FOR(i, 1, n + 1) {
        if (bit[i] == -1) {
            cnt0 = 0, cnt1 = 0;
            dfs(i, 0);
            res.push_back(abs(cnt0 - cnt1));
        }
    }

    if (imp) {
        cout << -1;
        return 0;
    }

    cout << f(0, 0);

	return 0;
}