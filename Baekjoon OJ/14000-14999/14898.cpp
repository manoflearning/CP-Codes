#include <bits/stdc++.h>
using namespace std;

struct PST {
    int flag;
    struct Node { int l, r, val; };
    Node t[45'000'000];
    int root[3030303], rp, tp;

    void addNode() { t[tp++] = { -1, -1, 0 }; }
    void build(int l, int r, int n) {
        assert(0 <= n && n < tp);
        if (l == r) { return; }
        addNode();
        t[n].l = tp - 1;
        addNode();
        t[n].r = tp - 1;

        int mid = (l + r) >> 1;
        build(l, mid, t[n].l);
        build(mid + 1, r, t[n].r);
        t[n].val = t[t[n].l].val + t[t[n].r].val;
    }
    void build(int Flag) {
        addNode();
        root[rp] = 0;
        flag = Flag;
        build(1, flag, root[rp]);
        rp++;
    }
    void modify(int p, int val, int l, int r, int n1, int n2) {
        assert(0 <= n1 && n1 < tp);
        assert(0 <= n2 && n2 < tp);
        if (p < l || r < p) { t[n2] = t[n1]; return; }
        if (l == r) { t[n2].val = val; return; }

        int mid = (l + r) >> 1;
        if (p <= mid) {
            t[n2].r = t[n1].r;
            addNode();
            t[n2].l = tp - 1;
            modify(p, val, l, mid, t[n1].l, t[n2].l);
        }
        else {
            t[n2].l = t[n1].l;
            addNode();
            t[n2].r = tp - 1;
            modify(p, val, mid + 1, r, t[n1].r, t[n2].r);
        }
        t[n2].val = t[t[n2].l].val + t[t[n2].r].val;
    }
    void modify(int p, int val) {
        addNode();
        root[rp] = tp - 1;
        modify(p, val, 1, flag, root[rp - 1], root[rp]);
        rp++;
    }
    int query(int l, int r, int n, int nl, int nr) {
        assert(0 <= n && n < tp);
        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n].val;
        int mid = (nl + nr) >> 1;
        return query(l, r, t[n].l, nl, mid) + query(l, r, t[n].r, mid + 1, nr);
    }
    int query(int l, int r, int n) {
        return query(l, r, root[n], 1, flag);
    }
}pst;

int n, a[1010101], prv[1010101], Hash[1010101];

void cc() {
    vector<int> c(1, -1);
    for (int i = 1; i <= n; i++)
        c.push_back(a[i]);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cc();

    pst.build(n);

    memset(prv, -1, sizeof(prv));
    for (int i = 1; i <= n; i++) {
        if (prv[a[i]] != -1) 
            pst.modify(prv[a[i]], 0);
        pst.modify(i, 1);
        Hash[i] = pst.rp - 1;
        prv[a[i]] = i;
    }

    int q; cin >> q;
    int ans = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l += ans;

        ans = pst.query(l, r, Hash[r]);
        cout << ans << '\n';
    }
}