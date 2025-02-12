#include <bits/stdc++.h>
using namespace std;
#define ll long long

// nCr in O(r)
// Beware of integer overflow
ll binom(int n, int r) {
    if (r < 0 || n < r) return 0;
    r = min(r, n - r);
    ll ret = 1;
    for (ll i = 1; i <= r; i++) {
        ret *= n + 1 - i;
        ret /= i;
    }
    return ret;
}

ll dp[22];
ll dp2[22];

int main() {
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp2[0] = dp2[1] = 1;
    dp2[2] = 1;

    for (int i = 3; i <= 20; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += binom(i - 1, j) * dp2[j] * dp2[i - 1 - j];
        }
        dp2[i] = dp[i] / 2;
    }

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}
