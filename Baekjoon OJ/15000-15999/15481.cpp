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

const int D = 17;

vector<int> p(202020, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[A] += p[B];
	p[B] = A;
}

struct Edge {
    int v, u, idx;
    ll w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

int n, m;
vt<Edge> adj[202020], t[202020];
vt<Edge> edge;
int vi[202020], par[202020][D + 1], mx[202020][D + 1], dep[202020];
Edge edge2[202020];

void input() {
    cin >> n >> m;
    FOR(m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, u, i, w });
        adj[v].push_back({ u, v, i, w });
        edge.push_back({ u, v, i, w });
        edge2[i] = { u, v, i, w };
    }
}

void dfs(int v, int prv) {
    par[v][0] = prv;
    dep[v] = dep[prv] + 1;
    EACH(i, t[v]) {
        if (i.v == prv) continue;
        mx[i.v][0] = i.w;
        dfs(i.v, v);
    }
}

void buildSparseTable() {
    for (int i = 1; i <= D; i++) {
		for (int v = 1; v <= n; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
            mx[v][i] = max(mx[v][i - 1], mx[par[v][i - 1]][i - 1]);
		}
	}
}

int lca(int u, int v) {
    int ret = 0;

    if (dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];
	for (int i = D; i >= 0; i--)
		if (diff & (1 << i)) {
            ret = max(ret, mx[u][i]);
            u = par[u][i];
        }

	if (u == v) return ret;

	for (int i = D; i >= 0; i--) {
		if (par[u][i] ^ par[v][i]) {
            ret = max(ret, mx[u][i]);
			u = par[u][i];
            ret = max(ret, mx[v][i]);
			v = par[v][i];
		}
	}
	
	return max({ ret, mx[u][0], mx[v][0] });
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

    sort(all(edge));

    ll mstCost = 0;
    EACH(i, edge) {
        if (find(i.u) == find(i.v)) continue;
        vi[i.idx] = 1;
        mstCost += i.w;
        merge(i.u, i.v);
        t[i.u].push_back({ i.v, i.u, i.idx, i.w });
        t[i.v].push_back({ i.u, i.v, i.idx, i.w });
    }

    dfs(1, 0);

    buildSparseTable();

    FOR(m) {
        if (vi[i]) {
            cout << mstCost << '\n';
            continue;
        }

        cout << mstCost + edge2[i].w - lca(edge2[i].u, edge2[i].v) << '\n';
    }

	return 0;
}