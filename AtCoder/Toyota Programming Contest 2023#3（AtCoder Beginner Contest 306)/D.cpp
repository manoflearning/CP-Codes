//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n;
ll poison[303030], y[303030];
ll dp[303030][2];

const int healthy = 1, upset = 0;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> poison[i] >> y[i];

    dp[0][healthy] = 0;
    dp[0][upset] = -1e18;

    for (int i = 1; i <= n; i++) {
        if (!poison[i]) {
            dp[i][healthy] = max(dp[i - 1][healthy], y[i] + max(dp[i - 1][healthy], dp[i - 1][upset]));
            dp[i][upset] = dp[i - 1][upset];
        }
        if (poison[i]) {
            dp[i][healthy] = dp[i - 1][healthy];
            dp[i][upset] = max(dp[i - 1][upset], y[i] + dp[i - 1][healthy]);
        }
    }

    cout << max(dp[n][healthy], dp[n][upset]);
}