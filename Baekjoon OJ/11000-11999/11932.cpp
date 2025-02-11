#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define fr first
#define sc second

const int MAXN = 101010;
const int MAXD = 16;
const ll INF = 1e18;

struct Query { int u, v, k; };

int n, a[MAXN];
vector<int> adj[MAXN];
int q;
vector<Query> qu;

void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    qu.resize(q);
    for (auto& i : qu)
        cin >> i.u >> i.v >> i.k;
}

vector<int> t[MAXN];
int dep[MAXN], par[MAXN][MAXD + 1];
void dfs(int v, int prv) {
    for (auto& i : adj[v]) {
        if (i == prv) continue;
        t[v].push_back(i);
        dep[i] = dep[v] + 1;
        par[i][0] = v;
        dfs(i, v);
    }
}

// sparse table, lca
void buildSparseTable() {
    for (int d = 1; d <= MAXD; d++) {
        for (int v = 1; v <= n; v++) {
            par[v][d] = par[par[v][d - 1]][d - 1];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int d = MAXD; d >= 0; d--) {
        if ((1 << d) & diff) u = par[u][d];
    }
    if (u == v) return u;
    for (int d = MAXD; d >= 0; d--) {
        if (par[u][d] ^ par[v][d]) 
            u = par[u][d], v = par[v][d];
    }
    return par[u][0];
}

// value compression
vector<ll> c;
void valComp() {
    c.push_back(-INF);
    for (int i = 1; i <= n; i++) 
        c.push_back(a[i]);
    sort(all(c));
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(all(c), a[i]) - c.begin();
}

// persistent segment tree
int vHash[MAXN];
struct PST { // 1-indexed
    int flag; // array size
    struct Node { int l, r, val; };
    vector<Node> t;
    vector<int> root;

    void addNode() { t.push_back({ -1, -1, 0 }); }
    void build(int l, int r, int n)  {
        assert(0 <= n && n < sz(t));
        if (l == r) { t[n].val = 0; return; }
        addNode();
        t[n].l = sz(t) - 1;
        addNode();
        t[n].r = sz(t) - 1;

        int mid = (l + r) >> 1;
        build(l, mid, t[n].l);
        build(mid + 1, r, t[n].r);
        t[n].val = t[t[n].l].val + t[t[n].r].val;
    }
    void build(int Flag) {
        addNode();
        root.push_back(sz(t) - 1);
        flag = Flag;
        build(1, flag, root[0]);
    }
    void modify(int p, int l, int r, int n1, int n2) {
        assert(0 <= n1 && n1 < sz(t));
        assert(0 <= n2 && n2 < sz(t));
        if (p < l || r < p) { t[n2] = t[n1]; return; }
        if (l == r) { t[n2].val++; return; }

        int mid = (l + r) >> 1;
        if (p <= mid) {
            t[n2].r = t[n1].r;
            addNode();
            t[n2].l = sz(t) - 1;
            modify(p, l, mid, t[n1].l, t[n2].l);
        }
        else {
            t[n2].l = t[n1].l;
            addNode();
            t[n2].r = sz(t) - 1;
            modify(p, mid + 1, r, t[n1].r, t[n2].r);
        }
        t[n2].val = t[t[n2].l].val + t[t[n2].r].val;
    }
    void modify(int p, int prv) {
        addNode();
        root.push_back(sz(t) - 1);
        modify(p, 1, flag, root[vHash[prv]], root[sz(root) - 1]);
    }
    int query(int l, int r, int n, int nl, int nr) {
        assert(0 <= n && n < sz(t));
        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n].val;
        int mid = (nl + nr) >> 1;
        return query(l, r, t[n].l, nl, mid) + query(l, r, t[n].r, mid + 1, nr);
    }
    int query(int l, int r, int v) {
        return query(l, r, root[vHash[v]], 1, flag);
    }
    int kth(int u, int v, int p, int q, int nl, int nr, int k) {
        int mid = (nl + nr) >> 1;        
        int leftChildCount = t[t[u].l].val + t[t[v].l].val - t[t[p].l].val - t[t[q].l].val;

        if (k <= leftChildCount) return kth(t[u].l, t[v].l, t[p].l, t[q].l, nl, mid, k);
        else return kth(t[u].r, t[v].r, t[p].r, t[q].r, mid + 1, nr, k - leftChildCount);
    }
    int kth(int u, int v, int p, int q, int k) {
        return kth(root[vHash[u]], root[vHash[v]], root[vHash[p]], root[vHash[q]], 1, flag, k);
    }
}pst;

void constructPST() {
    vector<pii> ord;
    for (int v = 1; v <= n; v++) {
        ord.push_back({ dep[v], v });
    }

    sort(all(ord));
    pst.build(n);
    for (int i = 0; i < n; i++) {
        int v = ord[i].sc;
        vHash[v] = i + 1;
        if (i == 0) pst.modify(a[v], 0);
        else pst.modify(a[v], par[v][0]);
    }
}

int query(int u, int v, int k) {
    int lc = lca(u, v);
    return c[pst.kth(u, v, lc, par[lc][0], k)];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    dfs(1, 0);

    buildSparseTable();

    valComp();

    constructPST();

    for (auto& i : qu) {
        cout << query(i.u, i.v, i.k) << '\n';
    }
}