#include <bits/stdc++.h>
using namespace std;

int flag;
struct Seg {
    vector<int> t, lazy;
    void build(int N) {
        for (flag = 1; flag < N; flag <<= 1);
        t.resize(flag << 1);
        lazy.resize(flag << 1);

        for (int i = flag; i < flag + N; i++) t[i] = (1 << 1);
        for (int i = flag - 1; i >= 1; i--) {
            t[i] = t[i << 1] | t[i << 1 | 1];
        }
    }
    void modify(int l, int r, int value, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);
        
        if (r < nl || nr < l) return;
        if (l <= nl && nr <= r) {
            lazy[n] = value;
            propagate(n);
            return;
        }

        int mid = (nl + nr) >> 1;
        modify(l, r, value, n << 1, nl, mid);
        modify(l, r, value, n << 1 | 1, mid + 1, nr);
        t[n] = t[n << 1] | t[n << 1 | 1];
    }
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);

        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n];

        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) | query(l, r, n << 1 | 1, mid + 1, nr);
    }
    void propagate(int n) {
        if (!lazy[n]) return;

        if (n < flag) {
            lazy[n << 1] = lazy[n];
            lazy[n << 1 | 1] = lazy[n];
        }
        t[n] = lazy[n];
        lazy[n] = 0;
    }
}seg;

int n, t, q;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> t >> q;
    seg.build(n);
    for (int i = 0; i < q; i++) {
        char c;
        int x, y, z;
        cin >> c >> x >> y;
        if (x > y) swap(x, y);
        if (c == 'C') {
            cin >> z;
            seg.modify(x, y, 1 << z);
        }
        else {
            int res = seg.query(x, y);
            int ans = 0;
            for (int i = 1; i <= 30; i++)
                if ((1 << i) & res) ans++;
            cout << ans << '\n';
        }
    }
}