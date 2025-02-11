#include <bits/stdc++.h>
using namespace std;

const int MAXN = 303030;
const int MAXD = 18;

int n, q;
struct Edge { int w, v; };
vector<Edge> t[MAXN];
struct Query { int s, e; };
vector<Query> qu;

void input() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        t[u].push_back({ w, v });
        t[v].push_back({ w, u });
    }
    qu.resize(q);
    for (auto& i : qu) cin >> i.s >> i.e;
}

int par[MAXN][MAXD + 1];
int dep[MAXN];
int dist[MAXN][MAXD + 1];

void dfs(int v, int prv) {
    for (auto& i : t[v]) {
        if (i.v == prv) continue;
        par[i.v][0] = v;
        dep[i.v] = dep[v] + 1;
        dist[i.v][0] = i.w;
        dfs(i.v, v);
    }
}

void buildSparseTable() {
    for (int d = 1; d <= MAXD; d++) {
        for (int v = 1; v <= n; v++) {
            par[v][d] = par[par[v][d - 1]][d - 1];
            dist[v][d] = max(dist[v][d - 1], dist[par[v][d - 1]][d - 1]);
        }
    }
}

int getDist(int u, int v) {
    int ret = 0;

    if (dep[u] < dep[v]) swap(u, v);

    int diff = dep[u] - dep[v];
    for (int d = 0; d <= MAXD; d++) {
        if (diff & (1 << d)) {
            ret = max(ret, dist[u][d]);
            u = par[u][d];
        }
    }

    if (u == v) return ret;

    for (int d = MAXD; d >= 0; d--) {
        if (par[u][d] ^ par[v][d]) {
            ret = max(ret, dist[u][d]);
            ret = max(ret, dist[v][d]);
            u = par[u][d];
            v = par[v][d];
        }
    }

    ret = max(ret, dist[u][0]);
    ret = max(ret, dist[v][0]);

    return ret;
}

int flag;
struct Seg {
    vector<int> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void modify(int p, int val) {
        for (t[p += flag - 1] = val; p > 1; p >>= 1)
            t[p >> 1] = max(t[p], t[p ^ 1]);
    }
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
    }
}seg;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    input();

    dfs(1, 0);

    buildSparseTable();

    seg.build(n);
    for (int v = 1; v + 1 <= n; v++) {
        seg.modify(v, getDist(v, v + 1));
    }

    for (auto& i : qu) {
        cout << seg.query(i.s, i.e - 1) << '\n';
    }
}