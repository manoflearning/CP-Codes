#include <bits/stdc++.h>
using namespace std;

int isValid(const vector<int>& a, int n, int m, int k) {
    int imx = 0, dmx = 0;

    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[i] = dp[j] + 1;
        }
        imx = max(imx, dp[i]);
    }

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) dp[i] = dp[j] + 1;
        }
        dmx = max(dmx, dp[i]);
    }

    return imx == m && dmx == k;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans;

    int lb = 1, ub = n;
    int dcnt = 0, icnt = 0;

    while (lb <= ub) {
        int ilen = m - dcnt;
        if (ilen > 0) {
            int st = max(lb, ub - ilen + 1);
            for (int i = st; i <= ub; i++) {
                ans.push_back(i);
            }
            ub = st - 1;
            icnt++;
        }
        if (lb > ub) break;
        int dlen = k - icnt;
        if (dlen > 0) {
            int st = min(ub, lb + dlen - 1);
            for (int i = st; i >= lb; i--) {
                ans.push_back(i);
            }
            lb = st + 1;
            dcnt++;
        }
    }

    if (ans.size() < n) {
        cout << -1;
        return 0;
    }

    if (!isValid(ans, n, m, k)) {
        cout << -1;
        return 0;
    }

    for (auto& i : ans)
        cout << i << ' ';
}