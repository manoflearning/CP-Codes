#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second

const int MOD = 40'000;

int n;
vector<pll> a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (y != 0) a.push_back({ x, y });
    }

    sort(a.begin(), a.end(), [&](const pll& p1, const pll& p2) {
        return p2.fr * p1.sc < p1.fr * p2.sc;
    });

    ll tsum = 0, ans = 0;
    for (auto& i : a) {
        ll tnow = tsum * i.fr + i.sc;
        ans = (ans + tnow) % MOD;
        tsum = (tsum + tnow) % MOD;
    }

    cout << ans;
}