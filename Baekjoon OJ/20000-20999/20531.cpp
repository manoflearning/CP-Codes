#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

vector<int> uf(5050, -1);
int find(int x) {
    if (uf[x] < 0) return x;
    return uf[x] = find(uf[x]);
}
void merge(int u, int v) {
    int U = find(u), V = find(v);
    if (U == V) return;
    uf[U] = V;
}

ll dp[5050][5050], sum[5050];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    dp[1][1] = sum[1] = 1;
    for (int i = 2; i < 5050; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] %= MOD;
            dp[i][j] += j * dp[i - 1][j];
            dp[i][j] %= MOD;
            sum[i] = (dp[i][j] + sum[i]) % MOD;
        }
    }

    int n, m;
    cin >> n >> m;
    int cnt = n;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) {
            merge(u, v);
            cnt--;
        }
        cout << sum[cnt] << '\n';
    }
}