#include <bits/stdc++.h>
using namespace std;

int flag;
struct Seg {
    vector<int> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void modify(int p, int val) {
        for (t[p += flag - 1] = val; p > 1; p >>= 1)
            t[p >> 1] = t[p] ^ t[p ^ 1];
    }
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) ^ query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

const int MAXV = 101010;

int n, q;
vector<int> adj[MAXV], g[MAXV];
int a[MAXV];
int siz[MAXV], dep[MAXV], par[MAXV];
int top[MAXV], in[MAXV], out[MAXV], pv;

void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int v, int prv) {
    for (auto& i : adj[v]) {
        if (i == prv) continue;
        g[v].push_back(i);
        dfs(i, v);
    }
}
int dfs1(int v) {
    siz[v] = 1;
    for (auto& i : g[v]) {
        dep[i] = dep[v] + 1, par[i] = v;
        siz[v] += dfs1(i);
        if (siz[i] > siz[g[v][0]]) swap(i, g[v][0]);
    }
    return siz[v];
}
void dfs2(int v) {
    in[v] = ++pv;
    for (auto& i : g[v]) {
        top[i] = (i == g[v][0] ? top[v] : i);
        dfs2(i);
    }
    out[v] = pv;
}
void modify(int v, int val) {
    seg.modify(in[v], val);
}
int query(int u, int v) {
    int ret = 0;
    while (top[u] ^ top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        int st = top[u];
        ret ^= seg.query(in[st], in[u]);
        u = par[st];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ret ^= seg.query(in[u], in[v]);
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    dfs(1, 0);
    top[1] = 1;
    dfs1(1);
    dfs2(1);

    seg.build(MAXV);
    for (int v = 1; v <= n; v++)
        modify(v, a[v]);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) modify(u, v);
        if (op == 2) cout << query(u, v) << '\n';
    }
}