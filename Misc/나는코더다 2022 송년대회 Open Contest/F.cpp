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

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m, q, ind[303030];
vector<int> adj[303030];

inline int Hash(int v, int x) {
    return x * (n + 1) + v; 
}

void input() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (c == 'x') {
            adj[Hash(v, 1)].push_back(Hash(u, 0));
            ind[Hash(u, 0)]++;
        }
        if (c == 'y') {
            adj[Hash(v, 2)].push_back(Hash(u, 1));
            ind[Hash(u, 1)]++;
        }
        if (c == 'z') {
            adj[Hash(v, 0)].push_back(Hash(u, 2));
            ind[Hash(u, 2)]++;
        }
    }
}

int isCycle;
int vi[303030], out[303030], num[303030], cnt;

const int MAX = 303030, MAXD = 20;
int dep[MAX], par[MAX][MAXD + 1];

void dfs(int v) {
    vi[v] = 1;
    num[v] = cnt;
    for (auto& i : adj[v]) {
        if (!vi[i]) {
            dep[i] = dep[v] + 1;
            par[i][0] = v;
            dfs(i);
        }
        else if (!out[i]) isCycle = 1;
    }
    out[v] = 1;
}

void buildSparseTable() {
	for (int i = 1; i <= MAXD; i++) {
		for (int v = 1; v <= 2 * (n + 1) + n; v++) {
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
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

    for (int i = 1; i <= 2 * (n + 1) + n; i++) {
        if (!vi[i] && !ind[i]) {
            ++cnt;
            dfs(i);
        }
    }

    for (int i = 1; i <= 2 * (n + 1) + n; i++) {
        if (!vi[i]) {
            ++cnt;
            dfs(i);
        }
    }

    buildSparseTable();
    
    while (q--) {
        int u, v; char c; int x;
        cin >> u >> v >> c;
        x = (c == 'x' ? 0 : (c == 'y' ? 1 : 2));

        if (isCycle) cout << 1 << '\n';
        else {
            int U = Hash(u, x), V = Hash(v, (x + 1) % 3);
            if (num[U] == num[V] && lca(U, V) == U) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

	return 0;
}