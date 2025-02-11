#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const int INF = 1e9 + 7;

int n, m;
string r, p;
vector<int> dp, pi;

void init() {
    dp.clear();
    pi.clear();
}

void input() {
    cin >> r >> p;
    n = sz(r), m = sz(p);
}

int naive() { // 그룹 1 (20점), 그룹 2 (40점), 그룹 3 (60점)
    dp.resize(n, INF);

    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m && i + j < n; j++) {
            if (r[i + j] != p[j]) break;
            dp[i] = min(dp[i], 1 + dp[i + j + 1]);
        }
    }

    return dp[0] == INF ? -1 : dp[0];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << endl;

        init();

        input();

        cout << naive() << endl;
    }
}