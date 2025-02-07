#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

const int MAXN = 1010;
const ll INF = 1e18;

int n;
ll a[MAXN], b[MAXN];

vector<ll> dp(11, INF), prv1, prv2;
ll ans = INF;

void bottomup() {
    dp[b[1]] = b[1] + a[1];

    for (int i = 2; i <= n; i++) {
        prv2 = prv1;
        prv1 = dp;
        dp.clear();

        for (ll t = 1; t < sz(prv1); t++) {
            if (t + b[i] >= sz(dp)) {
                dp.resize(t + b[i] + 1, INF);
            }
            
            dp[t + b[i]] = min(dp[t + b[i]], max(t + b[i], prv1[t]) + a[i]);
        }

        for (ll t = 1; t < sz(prv2); t++) {
            if (t + b[i] >= sz(dp)) {
                dp.resize(t + b[i] + 1, INF);
            }

            dp[t + b[i]] = min(dp[t + b[i]], max(t + b[i], prv2[t] + a[i - 1]) + a[i]);
        }
    }

    for (int t = 1; t < sz(dp); t++) {
        ans = min(ans, dp[t]);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    bottomup();

    cout << ans;
}