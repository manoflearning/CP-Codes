// m <= ans
// if n = 2, ans = m
// if n = m, ans = m

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

vector<int> getArray(ll x, ll len) {
    int add = 1;
    vector<int> ret;
    for (int i = 0, v = 1; i < len; i++) {
        ret.push_back(v);
        v += add;
        if (v == 1) add = 1;
        if (v == x) add = -1;
    }
    return ret;
}

ll naive(ll x, ll y, ll len) {
    vector<int> A = getArray(x, len);
    vector<int> B = getArray(y, len);

    for (int i = 0; i < len / 2 + 1; i++)
        cout << A[i] << ' ';
    cout << '\n';
    for (int i = 0; i < len / 2 + 1; i++)
        cout << B[i] << ' ';
    cout << '\n';

    set<pair<int, int>> s;
    for (int i = 0; i < len; i++) {
        s.insert({ A[i], B[i] });
    }
    return s.size();
}

void simul() {
    ll n = 3;
    for (ll m = n; m <= 100; m++) {
        ll lc = lcm(2 * n - 2, 2 * m - 2);
        ll ans = naive(n, m, lc);

        cout << "n = " << n << ", m = " << m << '\n';
        cout << "ans = " << ans << '\n';
        cout << '\n';
    }
}

ll n, m;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    if (n > m) swap(n, m); // wlog, n <= m

    ll len = lcm(2 * n - 2, 2 * m - 2);

    simul();
}