#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long

const int MOD = 998'244'353;

int n, a[202020];
ll dp[202020], lazy[202020];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << dp[i] << ' ' << lazy[i] << '\n';
        for (int j = i + a[i]; j <= n; j += a[i]) {
            dp[j] = (dp[j] + dp[i] + lazy[i]) % MOD;
            if (a[j] == a[i]) {
                lazy[j] = (lazy[j] + dp[i] + lazy[i]) % MOD;
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % MOD;

    cout << ans;
}