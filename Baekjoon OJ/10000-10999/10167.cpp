#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size() 

const int INF = 1e9 + 7;

int flag;
struct Seg {
    struct Node {
        ll l, r, mx, sum;
        Node operator+(const Node& rhs) const {
            ll resl = max(l, sum + rhs.l);
            ll resr = max(r + rhs.sum, rhs.r);
            ll resmx = max({ mx, rhs.mx, r + rhs.l });
            ll ressum = sum + rhs.sum;
            return { resl, resr, resmx, ressum };
        }
    };

    vector<Node> t;
    void build(int n) {
        t.clear();
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void modify(int p, ll w) {
        p += flag - 1;
        t[p].l += w, t[p].r += w;
        t[p].mx += w, t[p].sum += w;
        for (; p > 1; p >>= 1) {
            if (p & 1) {
                t[p >> 1] = t[p ^ 1] + t[p];
            }
            else {
                t[p >> 1] = t[p] + t[p ^ 1];
            }
        }
    }
    Node query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (r < nl || nr < l) return { 0, 0, 0, 0 };
        if (l <= nl && nr <= r) return t[n];

        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

struct xy { int x, y; ll w; };

int n;
vector<xy> a, arr[6060];
vector<int> c;

void input() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) {
        cin >> i.x >> i.y >> i.w;
    }
}

void cc() {
    c.push_back(-INF);

    for (auto& i : a) {
        c.push_back(i.x);
        c.push_back(i.y);
    }

    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    for (auto& i : a) {
        i.x = lower_bound(c.begin(), c.end(), i.x) - c.begin();
        i.y = lower_bound(c.begin(), c.end(), i.y) - c.begin();
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

    cc();

    for (auto& i : a) {
        arr[i.x].push_back(i);
    }

    ll ans = 0;
    for (int sx = 1; sx < sz(c); sx++) {
        if (arr[sx].empty()) continue;

        seg.build(sz(c));

        for (int ex = sx; ex < sz(c); ex++) {
            if (arr[ex].empty()) continue;

            for (auto& i : arr[ex]) {
                seg.modify(i.y, i.w);
            }
            ans = max(ans, seg.query(1, sz(c) - 1).mx);
        }
    }

    cout << ans;

    return 0;
}