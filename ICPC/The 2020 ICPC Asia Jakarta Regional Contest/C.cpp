#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

const int MAXN = 101010;

int n;
struct Edge { ll w; int v; };
vector<Edge> t[MAXN];

void input() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        t[u].push_back({ w, v });
        t[v].push_back({ w, u });
    }
}

ll ans = 0;
ll dp[MAXN][2];

void dfs(int v, int prv) {
    vector<vector<ll>> arr;

    for (auto& i : t[v]) {
        if (i.v == prv) continue;
        dfs(i.v, v);
        arr.push_back({ dp[i.v][0], dp[i.v][1] });
        arr.back()[1] += i.w;
    }

    if (arr.empty()) return;

    // knapsack dp
    vector<vector<ll>> dp2(sz(arr), vector<ll>(2));
    dp2[0][0] = arr[0][0];
    dp2[0][1] = arr[0][1];
    for (int i = 1; i < sz(arr); i++) {
        dp2[i][0] = max(dp2[i][0], dp2[i - 1][0] + arr[i][0]);
        dp2[i][0] = max(dp2[i][0], dp2[i - 1][1] + arr[i][1]);

        dp2[i][1] = max(dp2[i][1], dp2[i - 1][0] + arr[i][1]);
        dp2[i][1] = max(dp2[i][1], dp2[i - 1][1] + arr[i][0]);
    }

    dp[v][0] = dp2[sz(arr) - 1][0];
    dp[v][1] = dp2[sz(arr) - 1][1];

    // update answer
    ans = max(ans, dp[v][0]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    if (n == 2) {
        cout << t[1][0].w;
        return 0;
    }

    for (int v = 1; v <= n; v++) {
        if (sz(t[v]) >= 2) { dfs(v, -1); break; }
    }

    cout << ans;
}