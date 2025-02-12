#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

const int INF = 1e9 + 7;

int flag;
struct Seg {
    vector<int> t;
    vector<int> lazy;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
        lazy.resize(flag << 1);
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
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        propagate(n);
        if (nr < l || r < nl) return INF;
        if (l <= nl && nr <= r) return t[n];

        int mid = (nl + nr) >> 1;
        return min(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
    }
    void propagate(int n) {
        if (lazy[n] == 0) return;

        if (n < flag) {
            lazy[n << 1] += lazy[n];
            lazy[n << 1 | 1] += lazy[n];
        }

        t[n] += lazy[n];
        lazy[n] = 0;
    }
}seg;

int n, m, q;
int mid, cnt0, cnt1;

vector<int> arr[101010];
int fired[101010];
int arr0[101010], arr1[101010];

struct Query { int y, idx, val; };
vector<Query> qu;

void init() {
    for (int i = 0; i < 101010; i++) {
        arr[i].resize(1);
    }
}

void input() {
    cin >> n >> m >> q;
    cin >> mid;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        if (x < mid) cnt0++;
        if (mid < x) cnt1++;
    }
    for (int i = 1; i <= m; i++) {
        int cnt; cin >> cnt;
        fired[i] = cnt;
        while (cnt--) {
            int x; cin >> x;
            arr[i].push_back(x);
            if (x < mid) arr0[i]++;
            if (mid < x) arr1[i]++;
        }
    }

    qu.resize(q);
    for (auto& i : qu) {
        cin >> i.y >> i.idx >> i.val;
    }
}

int sum[101010];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    input();

    seg.build(m + 1);
    sum[1] = cnt0 - fired[1];
    seg.modify(1, 1, sum[1]);
    // cout << sum[1] << ' ';
    for (int i = 2; i <= m + 1; i++) {
        sum[i] = arr0[i - 1] - fired[i] + sum[i - 1];
        seg.modify(i, i, sum[i]);
        // cout << sum[i] << ' ';
    }
    // cout << '\n';

    for (auto& i : qu) {
        bool prvSmall = arr[i.y][i.idx] < mid;
        bool nowSmall = i.val < mid;
        if (prvSmall == true && nowSmall == false) {
            seg.modify(i.y + 1, m + 1, -1);
        }
        if (prvSmall == false && nowSmall == true) {
            seg.modify(i.y + 1, m + 1, +1);
        }
        arr[i.y][i.idx] = i.val;
        // cout << seg.query(1, m + 1) << '\n';
        if (seg.query(1, m + 1) < 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}