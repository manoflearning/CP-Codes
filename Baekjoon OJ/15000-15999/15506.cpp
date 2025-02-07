#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;

struct Query { int op, t, x, l, r, h; };

int n, q;
ll w;
vector<Query> qu;

struct Node {
    ll h, t, x;
    bool operator<(const Node& rhs) const {
        return h + w * (rhs.t - t) < rhs.h;
    }
};
const Node e = { -INF, 0, 0 };
int flag;
struct Seg {
    vector<Node> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1, e);
    }
    void modify(int p, Node val) {
        for (t[p += flag - 1] = val; p > 1; p >>= 1) 
            t[p >> 1] = max(t[p], t[p ^ 1]);
    }
    Node query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return e;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
    }
}seg;
struct Sum {
    vector<int> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void modify(int p, int val) {
        for (t[p += flag - 1] = val; p > 1; p >>= 1) 
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}sum;

void input() {
    cin >> n >> q >> w;
    qu.resize(q);
    for (auto& i : qu) {
        cin >> i.op >> i.t;
        if (i.op == 1) cin >> i.x >> i.h;
        if (i.op == 2) cin >> i.l >> i.r >> i.h;
        if (i.op == 3) cin >> i.l >> i.r;
    }
}

void coordinateCompression() {
    vector<int> c(1, -1);
    vector<int> cnt(n + 1);
    for (auto& i : qu) {
        if (i.op == 1) cnt[i.x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) c.push_back(i);
        else {
            for (int j = 0; j < cnt[i]; j++) c.push_back(i);
        }
    }
    
    sort(all(c));
    
    n = sz(c);
    vector<int> prv(n + 1);
    for (auto& i : qu) {
        if (i.op == 1) {
            i.x = lower_bound(all(c), i.x) - c.begin();
            
            int tmp = i.x;
            if (prv[tmp]) i.x = prv[tmp] + 1;
            prv[tmp] = i.x;
        }
        if (i.op == 2 || i.op == 3) {
            i.l = lower_bound(all(c), i.l) - c.begin();
            i.r = upper_bound(all(c), i.r) - c.begin() - 1;
        }
    }
}

void solve() {
    seg.build(n);
    sum.build(n);
    
    for (auto& i : qu) {
        if (i.op == 1) {
            seg.modify(i.x, { i.h, i.t, i.x });
            sum.modify(i.x, 1);
        }
        if (i.op == 2) {
            while (1) {
                Node v = seg.query(i.l, i.r);
                if (v.h + w * (i.t - v.t) > i.h) {
                    seg.modify(v.x, e);
                    sum.modify(v.x, 0);
                }
                else break;
            }
        }
        if (i.op == 3) {
            cout << sum.query(i.l, i.r) << '\n';
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    coordinateCompression();

    solve();
}