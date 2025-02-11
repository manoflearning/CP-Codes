#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202;
const int INF = 1e9 + 7;

int N, K, a[MAXN];
int dp[MAXN][MAXN];

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
}

void bottom_up() {
    // base case
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 0;
    }

    // inductive step
    for (int len = 2; len <= N; len++) {
        for (int st = 1; ; st++) {
            int en = st + len - 1;
            if (N < en) break;
            dp[st][en] = INF;
            for (int i = st; i + 1 <= en; i++) {
                dp[st][en] = min(dp[st][en], dp[st][i] + dp[i + 1][en] + (a[st] != a[i + 1]));
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    bottom_up();

    cout << dp[1][N];
}