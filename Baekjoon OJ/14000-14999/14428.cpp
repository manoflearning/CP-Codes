#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 7;

int flag;
struct Seg {
    vector<pii> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1, { INF, INF });
    }
    void modify(int p, int val) {
        t[p + flag - 1] = { val, p };
        for (p += flag - 1; p > 1; p >>= 1)
            t[p >> 1] = min(t[p], t[p ^ 1]);
    }
    pii query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return { INF, INF };
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return min(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
    }
}seg;

int n, a[101010];
int m;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    seg.build(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        seg.modify(i, a[i]);
    }

    cin >> m;
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        // cout << op << ' ' << x << ' ' << y << '\n';
        if (op == 1) seg.modify(x, y);
        if (op == 2) cout << seg.query(x, y).sc << '\n';
    }
}