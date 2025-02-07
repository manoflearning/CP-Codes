#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, ub[63];
map<ll, ll> dp;

void init() {
    for (int i = 2; i <= 61; i++) {
        ll l = 1, r = (1ll << 50);
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (i * log(mid) < log(1ll << 62)) l = mid;
            else r = mid - 1;
        }
        ub[i] = l; 
    }
}

ll pxy(ll x, ll y) {
    if (y == 1) return x;
    ll ret = pxy(x, y / 2);
    return ret * ret * (y & 1 ? x : 1);
}

ll cal(ll x, ll y) {
    ll l = 0, r = ub[y];
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (pxy(mid, y) >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

ll f(ll x) {
    if (x == 1) return 0;
    if (x == 2) return 1;

    ll& ret = dp[x];
    if (ret) return ret;
    
    ret = x - 1;

    for (ll i = 2; i <= 61; i++) {
        ll r = cal(x, i), l = r - 1;
        //cout << x << ' ' << i << ' ' << r << '\n';
        if (x > l) ret = min(ret, f(l) + abs(pxy(l, i) - x) + 1);
        if (x > r) ret = min(ret, f(r) + abs(pxy(r, i) - x) + 1);
    }

    return ret;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    cin >> n;
    cout << f(n);

    return 0;
}