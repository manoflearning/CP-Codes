#include <bits/stdc++.h>
using namespace std;
#define ll long long

int flag;
struct Seg {
    struct Node {
        int mx, l, r, len;
        Node operator+(const Node& rhs) const {
            Node ret = { 0, 0, 0 };
            ret.mx = max({ r + rhs.l, mx, rhs.mx });
            ret.l = (mx == len ? mx + rhs.l : l);
            ret.r = (rhs.mx == rhs.len ? rhs.mx + r : rhs.r);
            ret.len = len + rhs.len;
            return ret;
        }
    };
    vector<Node> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
        for (int i = flag; i < flag + n; i++) t[i].len = 1;
        for (int i = flag - 1; i >= 1; i--)
            t[i].len = t[i << 1].len + t[i << 1 | 1].len;
    }
    void modify(int p, int val) {
        p += flag - 1;
        t[p].l = t[p].r = t[p].mx = val;
        for (; p > 1; p >>= 1) {
            if (p & 1) t[p >> 1] = t[p ^ 1] + t[p];
            else t[p >> 1] = t[p] + t[p ^ 1];
        }
    }
    int query() { return t[1].mx; }
}seg;

struct Point {
    ll x, y; int co;
    bool operator<(const Point& rhs) const {
        return tie(x, y) < tie(rhs.x, rhs.y);
    }
};

struct Line {
    int i, j; ll dx, dy; // i < j, dx >= 0
    bool operator<(const Line& rhs) const {
        if (dy * rhs.dx != rhs.dy * dx) return dy * rhs.dx < rhs.dy * dx;
        return tie(i, j) < tie(rhs.i, rhs.j);
    }
    bool operator==(const Line& rhs) const {
        return (dy * rhs.dx == rhs.dy * dx);
    }
};

int n, pos[1010];
Point p[1010];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        char c; cin >> c;
        p[i].co = (c == 'R');
    }

    seg.build(n);

    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        seg.modify(i, p[i].co);
    }

    vector<Line> arr;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            arr.push_back({ i, j, p[j].x - p[i].x, p[j].y - p[i].y });
        }
    }
    sort(arr.begin(), arr.end());

    int ans = seg.query();
    for (int i = 0, j = 0; i < arr.size(); i = j) {
        while (j < arr.size() && arr[i] == arr[j]) j++; // all lines in [i, j) are same
        for (int k = i; k < j; k++) {
            int u = arr[k].i, v = arr[k].j;
            seg.modify(pos[u], p[pos[v]].co);
            seg.modify(pos[v], p[pos[u]].co);
            swap(p[pos[u]], p[pos[v]]);
            swap(pos[u], pos[v]);
        }
        ans = max(ans, seg.query());
    }

    cout << ans;
}