#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define ll long long

const int INF = 1e9 + 7;

int N, K, w1, w2, w3;
string s;
int dp[101010][55];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K >> w1 >> w2 >> w3;
    cin >> s;

    for (int i = 1; i <= 50; i++) {
        dp[0][i] = dp[1][i] = -INF;
    }
    if (2 <= N && s[0] == '.' && s[1] == '.') dp[1][0] = 1;

    for (int i = 2; i < sz(s); i++) {
        for (int j = 0; j <= 50; j++) dp[i][j] = dp[i - 1][j];

        if (i == 2 && s[0] == '.' && s[1] == '#' && s[2] == '.') dp[2][1] = 0;

        if (s[i] == '.' && s[i - 1] == '.') {
            for (int j = 0; j <= 50; j++) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 2][j]);
            }
        }

        if (i >= 3 && s[i] == '.' && s[i - 1] == '#' && s[i - 2] == '.') {
            for (int j = 0; j <= 50; j++) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 3][j]);
                // cout << dp[i - 3][j] << '\n';
            }
        }
    }

    int cntDot = 0;
    for (auto& i : s) {
        if (i == '.') cntDot++;
    }

    ll ans = 0;
    for (int i = 0; i <= 50; i++) {
        if (dp[N - 1][i] < 0) break;
        
        ll cnt2 = dp[N - 1][i], cnt3 = i;
        ll cnt1 = cntDot - 2 * (cnt2 + cnt3);
        cnt1 = min<ll>(cnt1, K);

        ll res = cnt1 * w1 + cnt2 * w2 + cnt3 * w3;
        
        while (cnt1 < K && 0 < cnt2) {
            if (cnt1 + 2 <= K && w2 < 2 * w1) {
                cnt2--;
                res -= w2;
                res += 2 * w1;
                cnt1 += 2;
            }
            else if (w2 < w1) {
                cnt2--;
                res -= w2;
                res += w1;
                cnt1++;
            }
            else break;
        }

        ans = max(ans, res);
    }

    cout << ans;
}