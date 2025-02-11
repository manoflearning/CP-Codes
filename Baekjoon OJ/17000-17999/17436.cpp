#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll m;
vector<ll> p;

ll ans = 0;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    p.resize(n);
    for (auto& i : p) cin >> i;

    for (int bit = 1; bit < (1 << n); bit++) {
        int cnt = 0; ll x = 1;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) cnt++, x *= p[i];
        }

        if (cnt & 1) ans += m / x;
        else ans -= m / x;
    }

    cout << ans;
}