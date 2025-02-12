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

int n, k, par[101010];
vt<int> adj[101010], chd[101010];

struct dcnt { int d, cnt; };
dcnt dp[101010];

void init() {
    FOR(101010) dp[i] = { -1, -1 };
}

void input() {
    cin >> n >> k;
    FOR(n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int v, int prv) {
    par[v] = prv;
    EACH(i, adj[v]) {
        if (i == prv) continue;
        dfs(i, v);
        chd[v].push_back(i);
    }
}

dcnt f(int v) {
    auto& ret = dp[v];
    if (ret.d != -1) return ret;
    if (chd[v].empty()) return ret = { 0, 0, };

    ret = { 0, 0 };
    vt<int> arr;
    EACH(i, chd[v]) {
        dcnt res = f(i);
        arr.push_back(res.d + 1);
        ret.cnt += res.cnt;
    }

    sort(arr.rbegin(), arr.rend());

    int st = 0;
    for (; st < sz(arr); st++) {
        if (arr[st] <= 2 * k && (st == sz(arr) - 1 || arr[st] + arr[st + 1] <= 2 * k)) break;
        else if (arr[st] > 2 * k) ret.cnt++;
        else if (st < sz(arr) - 1 && arr[st] + arr[st + 1] > 2 * k) ret.cnt++;
    }

    if (st < sz(arr)) ret.d = arr[st];

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

    dfs(1, 0);

    cout << f(1).cnt + 1;

	return 0;
}