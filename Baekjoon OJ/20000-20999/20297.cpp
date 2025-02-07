#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int MAXN = 101010;
const int MAXD = 16;
const ll INF = 1e18;
const int sq = 700;

int N, a[MAXN];
vector<int> t[MAXN];
vector<int> byColor[MAXN], byDep[MAXN];
ll dep[MAXN];
int in[MAXN], out[MAXN], p;
int par[MAXN][MAXD + 1];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        byColor[a[i]].push_back(i);
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
}

void dfs(int v, int prv) {
    in[v] = ++p;
    dep[v] = dep[prv] + 1;
    byDep[dep[v]].push_back(v);
    par[v][0] = prv;
    for (auto& i : t[v]) if (i != prv) dfs(i, v);
    out[v] = p;
}

void buildSparseTable() {
    for (int d = 1; d <= MAXD; d++) {
        for (int v = 1; v <= N; v++) {
            par[v][d] = par[par[v][d - 1]][d - 1];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int d = 0; d <= MAXD; d++) {
        if (diff & (1 << d)) u = par[u][d];
    }
    if (u == v) return u;
    for (int d = MAXD; d >= 0; d--) {
        if (par[u][d] ^ par[v][d]) {
            u = par[u][d];
            v = par[v][d];
        }
    }
    return par[u][0];
}

ll case1(int co) {
    ll ret = INF;
    for (int i = 0; i < sz(byColor[co]); i++) {
        for (int j = i + 1; j < sz(byColor[co]); j++) {
            int u = byColor[co][i], v = byColor[co][j];
            int lc = lca(u, v);
            ret = min(ret, dep[u] + dep[v] - 2 * dep[lc]);
        }
    }
    return ret;
}

struct Node {
    ll x, y;
    Node operator+(const Node& rhs) const {
        Node ret;
        if (y <= rhs.x) ret = { x, y };
        else if (rhs.y <= x) ret = rhs;
        else {
            if (x <= rhs.x) ret = { x, min(y, rhs.x) };
            else ret = { rhs.x, min(rhs.y, x) };
        }
        return ret;
    }
};
const Node e = { INF, INF };

int flag;
struct Seg {
    vector<Node> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1, e);
    }
    void modify(int p, Node val) {
        for (t[p += flag - 1] = val; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    Node query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (r < nl || nr < l) return e;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

ll case2(int co) {
    ll ret = INF;
    for (int i = N; i >= 1; i--) {
        for (auto v : byDep[i]) {
            Node res = seg.query(in[v] + 1, out[v]);
            ret = min(ret, res.x + res.y - 2 * i);
            if (a[v] == co) {
                ret = min(ret, res.x - i);
                seg.modify(in[v], { i, INF });
            }
        }
    }
    for (auto v : byColor[co]) 
        seg.modify(in[v], e);
    return ret;
}

ll solve() {
    ll ret = INF;
    seg.build(N);
    for (int co = 1; co <= N; co++) {
        if (sz(byColor[co]) <= 1) continue;
        else if (sz(byColor[co]) <= sq) ret = min(ret, case1(co));
        else ret = min(ret, case2(co));
    }
    return ret;
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

    cout << solve();
}