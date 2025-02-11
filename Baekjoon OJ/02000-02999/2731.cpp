#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e10;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; i *= 10) {
            ll x = -1;
            for (int j = 0; j <= 9; j++) {
                __int128_t k = (ans + j * i);
                __int128_t res = n - k * k % MOD * k % MOD;
                if (res % (i * 10) == 0) { x = j; break; }
            }
            assert(x != -1);
            ans += x * i;
        }
        cout << ans << '\n';
    }
}