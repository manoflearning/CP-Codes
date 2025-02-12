// a_{ik + j} = p_i * 2^{q_j}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 998'244'353;
const int MAXN = 202020, MAXK = 202020;

int flag;
struct Seg {
    vector<ll> t;
    void build(int n) {
        t.clear();
        for (flag = 1; flag < n; flag <<= 1);
        t.resize(flag << 1);
    }
    void add(int p, int val) {
        for (t[p += flag - 1] += val; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

ll power2[22];

int n, k;
int p[MAXN], q[MAXK];
ll ans = 0;

void init() {
    ans = 0;
}

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= k; i++) { cin >> q[i]; q[i]++; }
}

void case1() {
    seg.build(k);
    for (int i = 1; i <= k; i++) {
        ans = (ans + n * seg.query(q[i] + 1, k)) % MOD;
        seg.add(q[i], 1);
    }
}

ll cal(ll j) {
    ll mx = -1, mn = -1;
    if (j < 0) {
        mx = k + j, mn = 0;
        if (mx < mn) return 0;
        return (mx - mn + 1) * (mx + mn) / 2;
    }
    if (0 <= j) {
        mx = k, mn = j + 1;
        if (mx < mn) return k * k % MOD;
        return (mx - mn + 1) * (mx + mn) / 2 + k * (k - (mx - mn + 1)) % MOD;
    }
}

void case2() {
    seg.build(2 * n - 1);
    for (int i = 1; i <= n; i++) {
        for (int j = -20; j <= 20; j++) { // 2^j y < x < 2^{j + 1} y
            ll lb = -1, ub = -1;
            if (j < 0) {
                lb = p[i] / power2[-j];
                ub = (p[i] + power2[-j - 1] - 1) / power2[-j - 1];
            }
            if (0 <= j) {
                lb = power2[j] * p[i];
                ub = power2[j + 1] * p[i];
            }

            if (2 * n - 1 < lb) continue;

            ll cnt = seg.query(lb + 1, ub - 1);
            ans = (ans + cnt * cal(j) % MOD) % MOD;
        }

        seg.add(p[i], 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    power2[0] = 1;
    for (int i = 1; i < 22; i++)
        power2[i] = 2 * power2[i - 1] % MOD;

    int tc; cin >> tc;
    while (tc--) {
        init();

        input();

        case1();

        case2();

        cout << ans << '\n';
    }
}