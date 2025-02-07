// indegree of each nodes in G_s is at most 1
// G_s is dag. for each edges (u, v), v is bigger than u.
// 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1e9 + 7;
const int MAXV = 202020;

vector<int> uf(MAXV);
void init() {
    for (int i = 1; i < MAXV; i++) uf[i] = -i;
}
int find(int x) {
	if (uf[x] < 0) return x;
	return uf[x] = find(uf[x]);
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
    if (uf[A] < uf[B]) swap(A, B);
	uf[B] = A;
}

int n, p[MAXV];
vector<int> g[MAXV];
int rg[MAXV];

int vi[MAXV], jump[MAXV];

void dfs(int v, int st, int en) {
    if (v < en || n < v) return;

    vi[v] = 1;
    merge(v, st);
    jump[find(v)] = rg[v];

    if (v == en) return;

    int nxt = rg[v];
    if (nxt != 0) merge(nxt, st);

    if (vi[nxt]) dfs(jump[find(nxt)], st, en);
    else dfs(nxt, st, en);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i + 1);
        rg[i + 1] = p[i];
    }

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;

            if (find(u) == find(v)) continue;
            
            if (u < v) swap(u, v);
            if (vi[u]) dfs(jump[find(u)], u, v);
            else dfs(u, u, v);
        }
        if (op == 2) {
            int x; cin >> x;
            cout << -uf[find(x)] << '\n';
        }
    }
}