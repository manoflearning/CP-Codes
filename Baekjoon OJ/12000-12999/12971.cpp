#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second
#define sz(x) (int)(x).size()

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}
ll minv(ll x, ll y) {
    if (x == 0 && y == 1) return 0;
    if (x == 1) return 1;
    return y - minv(y % x, x) * y / x;
}

pll crt(pll U, pll V) {
    if (U.sc == -1 || V.sc == -1) return { -1, -1 };
    if (U.sc == 1) return V;
    if (V.sc == 1) return U;
    ll g = gcd(U.sc, V.sc), l = U.sc * V.sc / g;
    if ((V.fr - U.fr) % g) return { -1, -1 };

    ll u = U.sc / g, v = V.sc / g;
    ll mul = (V.fr - U.fr) / g;
    mul = mul * minv(u % v, v) % v;

    pll ret = { mul * U.sc + U.fr, l };
    ret.fr %= ret.sc, ret.fr = (ret.fr + ret.sc) % ret.sc;
    return ret;
}
ll linearCongruence(const vector<pll>& a) {
    if (sz(a) == 1) return a[0].fr;
    pll ret = crt(a[0], a[1]);
    for (int i = 2; i < sz(a); i++) {
        ret = crt(ret, a[i]);
    }
    return ret.fr;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll p1, p2, p3, x1, x2, x3;
    cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
    
    vector<pll> a;
    a.push_back({ x1, p1 });
    a.push_back({ x2, p2 });
    a.push_back({ x3, p3 });

    cout << linearCongruence(a);
}