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

const int MAX = 202020, MAXD = 18;  // 2^MAXD = 65536

vector<int> adj[MAX], t[MAX];
int n, dep[MAX], par[MAX][MAXD + 1], label[MAX], labelCnt;

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void dfs(int now, int prv) {
	par[now][0] = prv;
	dep[now] = dep[prv] + 1;
    label[now] = labelCnt++;
	for (auto i : adj[now]) {
		if (i == prv) continue;
		dfs(i, now);
        t[now].push_back(i);
	}
}

void buildSparseTable() {
	for (int i = 1; i <= MAXD; i++) {
		for (int v = 1; v <= n; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];
	for (int i = MAXD; i >= 0; i--)
		if (diff & (1 << i)) u = par[u][i];

	if (u == v) return u;

	for (int i = MAXD; i >= 0; i--) {
		if (par[u][i] ^ par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	
	return par[u][0];
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

    input();

    dfs(1, 0);

	buildSparseTable();

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;

        vt<int> b(m);
        EACH(i, b) cin >> i;

        if (m == 1) {
            cout << "YES\n";
            continue;
        }

        sort(all(b), [&](int u, int v) {
            return dep[u] < dep[v];
        });

        int LCA = b[0];
        FOR(m - 1) {
            LCA = lca(LCA, b[i + 1]);
        }

        if (LCA ^ b[0]) b.push_back(LCA);

        sort(all(b), [&](int u, int v) {
            return label[u] < label[v];
        });

        int ans = 1, cnt = 0;
        FOR(sz(b) - 1) {
            int res = lca(b[i], b[i + 1]);
            if (res != LCA && res != b[i] && res != b[i + 1]) ans = 0;
            if (i > 0 && res == LCA) cnt++;
        }

        if (ans && cnt <= 1) cout << "YES\n";
        else cout << "NO\n";
    }

	return 0;
}