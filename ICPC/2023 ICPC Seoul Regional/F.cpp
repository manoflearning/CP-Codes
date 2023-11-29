#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

int n, K;
vector<pii> a;
vector<int> dp;

void input() {
    cin >> n >> K;
    a.resize(n);
    for (auto& i : a)
        cin >> i.fr >> i.sc;
}

void valueCompression() {
    vector<int> c(1, -1e7);

    for (auto& i : a) {
        c.push_back(i.fr);
        c.push_back(i.sc);
    }

    sort(all(c));

    for (auto& i : a) {
        i.fr = lower_bound(all(c), i.fr) - c.begin();
        i.sc = lower_bound(all(c), i.sc) - c.begin();
    }
}

void bottomup() {
    dp.resize(n);

    vector<int> mx(n);

    // base case
    for (int i = 0; i < n; i++) {
        int res = 0, x = a[i].sc;
        for (int j = i; j < n; j++) {
            if (a[j].fr <= x && x <= a[j].sc) res++;
            dp[j] = max(dp[j], res);
        }
        mx[i] = res;
        // if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    }

    // inductive step
    for (int k = 1; k < K; k++) {
        vector<int> tmp = dp;

        int st = k;
        for (int i = k - 1; i < n; i++) {
            if (tmp[i] < i + 1) break;
            st = max(st, i + 1);
        }

        for (int i = st; i < n - (K - k) + 1; i++) {
            int res = 0, x = a[i].sc;

            // if (x == a[i - 1].sc) continue;
            // if (tmp[i - 1] + n - i <= dp[n - 1]) continue;

            for (int j = i; j < n - (K - k) + 1; j++) {
                if (a[j].fr <= x) {
                    res++;
                    dp[j] = max(dp[j], res + tmp[i - 1]);
                }
                // if (tmp[i - 1] + res + n - j - 1 <= dp[n - 1]) break;
                // if (res == mx[i]) break;
            }
        }

        for (int i = k; i < n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    // valueCompression();

    sort(all(a), [&](const pii& p1, const pii& p2) {
        return p1.sc < p2.sc;
    });

    bottomup();

    cout << dp[n - 1];
}