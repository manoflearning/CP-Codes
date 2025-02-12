#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second
#define sz(x) (int)(x).size()

int n, m, st;
ll a[1010], d[1010];
ll psum[1010], all, dp[1010][1010][2];
vector<pll> loc;

ll query(int l, int r) {
    return psum[r] - (l ? psum[l - 1] : 0);
}

ll f(int l, int r, int bit) {
    ll& ret = dp[l][r][bit];
    if (ret != -1) return ret;
    if (l == 0 && r == sz(loc) - 1) return ret = 0;

    ll now = (!bit ? loc[l].sc : loc[r].sc);

    ret = 1e18;
    if (0 < l) {
        ll len = abs(now - loc[l - 1].sc);
        ret = min(ret, len * (all - query(l, r)) + f(l - 1, r, 0));
    }
    if (r + 1 < sz(loc)) {
        ll len = abs(now - loc[r + 1].sc);
        ret = min(ret, len * (all - query(l, r)) + f(l, r + 1, 1));
    }

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    // initialize
    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    // input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> d[i] >> w;
        a[d[i]] += w;
    }

    // solve
    for (int i = 0; i <= 1000; i++) {
        if (!a[i]) continue;
        loc.push_back({ a[i], i });
        if (d[m - 1] == i) st = sz(loc) - 1;
    }

    psum[0] = loc[0].fr;
    for (int i = 1; i < sz(loc); i++) {
        psum[i] = loc[i].fr + psum[i - 1];
    }
    all = psum[sz(loc) - 1];

    cout << f(st, st, 0);
}