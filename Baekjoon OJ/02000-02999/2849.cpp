#include <bits/stdc++.h>
using namespace std;

int flag;
struct Seg {
    struct Node {
        int all, bl, br, mx, mxl, mxr;
        Node operator+(const Node& rhs) const {
            Node ret;
            ret.all = all + rhs.all;
            ret.bl = bl;
            ret.br = rhs.br;
            ret.mx = max({ mx, rhs.mx, (br != rhs.bl ? mxr + rhs.mxl : 0) });
            ret.mxl = (all == mxl && br != rhs.bl ? all + rhs.mxl : mxl);
            ret.mxr = (rhs.all == rhs.mxr && br != rhs.bl ? rhs.all + mxr : rhs.mxr);
            return ret;
        }
    };

    vector<Node> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);

        for (int i = flag; i < flag + n; i++)
            t[i] = { 1, 0, 0, 1, 1, 1 };
        for (int i = flag + n; i < 2 * flag; i++)
            t[i] = { 0, 2, 2, 0, 0, 0 };
        
        for (int i = flag - 1; i >= 1; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void modify(int p) {
        p += flag - 1;
        t[p].bl = !t[p].bl;
        t[p].br = !t[p].br;
        for (; p > 1; p >>= 1) {
            if (p & 1) t[p >> 1] = t[p ^ 1] + t[p];
            else t[p >> 1] = t[p] + t[p ^ 1];
        }
    }
    int query() { return t[1].mx; }
    Node query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (r < nl || nr < l) return { 0, 2, 2, 0, 0, 0 };
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    seg.build(n);
    while (q--) {
        int x; cin >> x;
        seg.modify(x);
        cout << seg.query() << '\n';
    }
}