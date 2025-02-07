#include <bits/stdc++.h>
using namespace std;

const int MAXV = 202020;

int n, m;
vector<int> adj[MAXV], radj[MAXV];
int in[MAXV], out[MAXV], num, p[2 * MAXV];
int vi[MAXV], cnt;
vector<vector<int>> scc;

vector<int> arr;
int canGo[MAXV], dep[MAXV];
vector<int> g[MAXV];

void init() {
    num = cnt = 0;
    scc.clear();
    arr.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear(); radj[i].clear();
        in[i] = out[i] = p[i << 1] = p[i << 1 | 1] = 0;
        vi[i] = 0;
        canGo[i] = dep[i] = 0;
        g[i].clear();
    }
    n = m = 0;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
}

void dfs(int v) {
    in[v] = ++num;
    for (auto& i : radj[v]) {
        if (!in[i]) dfs(i);
    }
    out[v] = ++num;
    p[num] = v;
}

void flood(int v) {
    scc[cnt].push_back(v);
    vi[v] = cnt;
    for (auto& i : adj[v]) {
        if (!vi[i]) flood(i);
    }
}

void kosaraju() {
    for (int v = 1; v <= n; v++) {
        if (!in[v]) dfs(v);
    }
    for (int v = 2 * n; v >= 1; v--) {
        if (!p[v]) continue;
        if (vi[p[v]]) continue;
        cnt++;
        scc.resize(cnt + 1);
        flood(p[v]);
    }
}

void dfsg(int v, int d) {
    dep[v] = d;
    for (auto& i : g[v])
        if (!dep[i]) dfsg(i, d + 1);
}

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int solve() {
    arr = scc[vi[1]];
    for (auto& i : arr) canGo[i] = 1;

    for (auto& i : arr) {
        for (auto& j : adj[i]) {
            if (canGo[j]) g[i].push_back(j);
        }
    }

    dfsg(1, 1);

    int res = -1;
    for (auto& u : arr) {
        for (auto& v : g[u]) {
            if (res == -1) res = abs(dep[u] + 1 - dep[v]);
            else res = gcd(res, abs(dep[u] + 1 - dep[v]));
        }
    }

    while (res % 2 == 0) res /= 2;
    while (res % 5 == 0) res /= 5;
    return res == 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        init();

        input();

        kosaraju();

        cout << (solve() ? "Yes" : "No") << '\n';
    }
}