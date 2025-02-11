#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

struct Node {
    ll p, q, u, v;
    Node operator+(const Node& rhs) const {
        Node ret;
        ret.p = (rhs.p * p + rhs.q * u) % MOD;
        ret.q = (rhs.p * q + rhs.q * v) % MOD;
        ret.u = (rhs.u * p + rhs.v * u) % MOD;
        ret.v = (rhs.u * q + rhs.v * v) % MOD;
        return ret;
    }
};

const Node e = { 1, 0, 0, 1 };

int flag;
struct Seg {
    vector<Node> t;
    vector<bool> lazy;
    void build(int n, const string& s) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1, e);
        lazy.resize(flag << 1);

        for (int i = flag; i < flag + n; i++) {
            t[i].p = 1, t[i].q = 0, t[i].u = 0, t[i].v = 1;
            if (s[i - flag] == 'A') t[i].q = 1;
            if (s[i - flag] == 'B') t[i].u = 1;
        }
        for (int i = flag - 1; i >= 1; i--) {
            t[i] = t[i << 1] + t[i << 1 | 1];
        }
    }
    void modify(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lazy[n] = true;
            propagate(n);
            return;
        }

        int mid = (nl + nr) >> 1;
        modify(l, r, n << 1, nl, mid);
        modify(l, r, n << 1 | 1, mid + 1, nr);
        t[n] = t[n << 1] + t[n << 1 | 1];
    }
    Node query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);
        if (nr < l || r < nl) return e;
        if (l <= nl && nr <= r) return t[n];

        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
    void propagate(int n) {
        if (lazy[n] == false) return;
        if (n < flag) {
            lazy[n << 1] = !lazy[n << 1];
            lazy[n << 1 | 1] = !lazy[n << 1 | 1];
        }

        Node tmp = t[n];
        t[n].p = tmp.v, t[n].q = tmp.u;
        t[n].u = tmp.q, t[n].v = tmp.p;
        lazy[n] = false;
    }
}seg;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s; cin >> s;

    seg.build(n, s);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            seg.modify(l, r);
        }
        if (op == 2) {
            int l, r;
            ll A, B;
            cin >> l >> r >> A >> B;
            Node res = seg.query(l, r);

            ll ansA = (res.p * A + res.q * B) % MOD;
            ll ansB = (res.u * A + res.v * B) % MOD;
            cout << ansA << ' ' << ansB << '\n';
        }
    }
}