#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, k;
ll dp[15][101010];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[1][i] = 1;
    }

    for (int v = 1; v <= n; v++) {
        ll sum = 0;
        for (int i = 1; i <= k; i++)
            sum = (dp[v - 1][i] + sum) % MOD;

        for (int i = 1; i <= k; i++) {
            dp[v][i] += sum;
            dp[v][i] %= MOD;

            for (int j = i + i; j <= k; j += i) {
                dp[v][i] += MOD - dp[v - 1][j];
                dp[v][i] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans;

	return 0;
}