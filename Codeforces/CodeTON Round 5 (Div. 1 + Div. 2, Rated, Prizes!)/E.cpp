#include <bits/stdc++.h>
using namespace std;
#define ll long long

int flag;  // array size
struct Seg {  // 1-indexed
    vector<ll> t, lazy;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(2 * flag);
        lazy.resize(2 * flag);
    }
    // add a value to all elements in interval [l, r]
    void modify(int l, int r, ll value, int n = 1, int nl = 1, int nr = flag) {
        propagate(n, nl, nr);
        if (r < nl || nr < l) return;
        if (l <= nl && nr <= r) {
            lazy[n] += value;
            propagate(n, nl, nr);
            return;
        }
        int mid = (nl + nr) >> 1;
        modify(l, r, value, n << 1, nl, mid);
        modify(l, r, value, n << 1 | 1, mid + 1, nr);
        t[n] = max(t[n << 1], t[n << 1 | 1]);
    }
    ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
        propagate(n, nl, nr);
        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) / 2;
        return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
    }
    void propagate(int n, int nl, int nr) {
        if (lazy[n] != 0) {
            if (n < flag) {
                lazy[n << 1] += lazy[n];
                lazy[n << 1 | 1] += lazy[n];
            }
            t[n] += lazy[n];
            lazy[n] = 0;
        }
    }
}seg;

int n, k;
ll A, total;
struct Point { int x; ll c; };
vector<Point> p[202020];
ll dp[202020];

void input() {
    cin >> n >> k >> A;
    k += 2;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x++, y++;
        p[y].push_back({ x, c });
        total += c;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    seg.build(202020);

    for (int i = 2; i <= k; i++) {
        for (auto& j : p[k - i]) {
            seg.modify(1, j.x, j.c);
        }
        seg.modify(1, i - 1, -A);
        
        dp[i] = max(seg.query(1, i - 1), dp[i - 1]);
        seg.modify(i, i, dp[i]);
    }

    cout << total - dp[k];
}