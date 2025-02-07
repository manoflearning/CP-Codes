#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second

const int INF = 1e9 + 7;

int flag;
struct Seg {
    vector<int> t, lazy;
    void build(int N) {
        t.clear();
        lazy.clear();
        for (flag = 1; flag < N; flag <<= 1);
        t.resize(flag << 1, INF);
        lazy.resize(flag << 1);
        for (int i = flag; i < flag + N; i++) t[i] = 0;
        for (int i = flag - 1; i >= 1; i--)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void modify(int l, int r, int val, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);
        if (nr < l || r < nl) return;
        if (l <= nl && nr <= r) {
            lazy[n] += val;
            propagate(n);
            return;
        }

        int mid = (nl + nr) >> 1;
        modify(l, r, val, n << 1, nl, mid);
        modify(l, r, val, n << 1 | 1, mid + 1, nr);
        t[n] = min(t[n << 1], t[n << 1 | 1]);
    }
    void propagate(int n) {
        if (lazy[n]) {
            if (n < flag) {
                lazy[n << 1] += lazy[n];
                lazy[n << 1 | 1] += lazy[n];
            }
            t[n] += lazy[n];
            lazy[n] = 0;
        }
    }
}seg;

struct Node { int x1, y1, x2, y2, w; };

int n, X, Y, mxw;
vector<Node> a;

void input() {
    cin >> X >> Y >> mxw >> n;
    X++, Y++;
    a.resize(n);
    for (auto& i : a) {
        cin >> i.x1 >> i.y1 >> i.x2 >> i.y2 >> i.w;
        i.x2++, i.y2++;
    }
}

int f(int len) {
    vector<vector<pair<pii, int>>> idx(X - len + 2);
    for (auto& i : a) {
        idx[max(1, i.x1 - len + 1)].push_back({ { i.y1 - len + 1, i.y2 - 1 }, i.w });
        idx[min(X - len + 1, i.x2)].push_back({ { i.y1 - len + 1, i.y2 - 1 }, -i.w });
    }

    seg.build(Y - len);
    
    int ret = INF;
    for (int i = 1; i <= X - len; i++) {
        for (auto& x : idx[i])
            seg.modify(x.fr.fr, x.fr.sc, x.sc);
        ret = min(ret, seg.t[1]);
    }
    
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    int l = 0, r = min(X, Y) - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (f(mid) <= mxw) l = mid;
        else r = mid - 1;
    }

    cout << l;
}