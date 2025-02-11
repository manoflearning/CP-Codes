#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second

int MAX = 0;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

ll phi(ll x) {
    vector<pll> p;
    for (ll i = 2; i <= sqrt(x); i++) {
        ll res = 1;
        while (x % i == 0) {
            x /= i, res *= i;
        }
        if (res > 1) p.push_back({ res, i });
    }
    if (x > 1) p.push_back({ x, x });

    ll ret = 1;
    for (auto& i : p) {
        ret *= (i.fr / i.sc) * (i.sc - 1);
    }
    return ret;
}

int flag;
struct Seg {
    vector<ll> t;
    void build(int n) {
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void add(int p, int val) {
        for (t[p += flag - 1] += val; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (r < nl || nr < l) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

void modify(int x) {
    int v = x;
    vector<int> pp;
    for (int i = 2; i <= sqrt(v); i++) {
        int bit = 0;
        while (v % i == 0) v /= i, bit = 1;
        if (bit) pp.push_back(i);
    }
    if (v > 1) pp.push_back(v);

    int cnt = pp.size();
    for (int bit = 0; bit < (1 << cnt); bit++) {
        int cnt = 0, p = 1;
        for (int i = 0; i < cnt; i++) {
            if (bit & (1 << i)) {
                cnt++;
                p *= pp[i];
            }
        }

        int add = (cnt & 1 ? 1 : -1);
        for (int i = (x + p - 1) / p * p; i < MAX; i += p) {
            seg.add(i, add);
        }
    }
}

ll dp[50505];
ll psum[50505];

int n;
struct Query {
    int a, b, idx;
};
vector<Query> q;
ll ans[50505];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // initialize
    dp[1] = 1;
    psum[1] = phi(1);
    for (int i = 2; i < 50505; i++) {
        dp[i] = 2 * phi(i) + dp[i - 1];
        psum[i] = phi(i) + psum[i - 1];
    }

    // input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a /= d, b /= d;
        if (a > b) swap(a, b); // wlog, a <= b
        q.push_back({ a, b, i });
        MAX = max(MAX, b + 1);
    }

    // solve
    sort(q.begin(), q.end(), [&](const Query& p1, const Query& p2) {
        return p1.a > p2.a;
    });

    seg.build(MAX);

    int prv = MAX;
    for (auto& i : q) {
        int a = i.a, b = i.b;

        while (a < prv) modify(--prv);

        ll res = 0;
        res += dp[b];
        res -= psum[b] - psum[a];
        res -= (ll)(b - a + 1) * (b - a) / 2 - seg.query(a + 1, b);

        ans[i.idx] = res;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
}