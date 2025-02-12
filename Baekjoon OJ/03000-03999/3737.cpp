#include <bits/stdc++.h>
using namespace std;

int n, m, ans, in[5555], out[5555], dep[5555];
vector<int> adj[5555];

void init() {
    ans = 0;
    for (int i = 0; i < 5555; i++) {
        in[i] = out[i] = dep[i] = 0;
        adj[i].clear();
    }
}

void dfs(int v, int prv) {
    in[v] = 1;
    dep[v] = dep[prv] + 1;
    for (auto& i : adj[v]) {
        if (i == prv) continue;

        if (!in[i]) {
            //cout << "Tree Edge " << v << ' ' << i << '\n';
            dfs(i, v);
        }
        else if (!out[i]) {
            //cout << "Back Edge " << v << ' ' << i << '\n';
            ans = max(ans, dep[v] - dep[i] + 1);
        }
    }
    out[v] = 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        init();

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int v = 1; v <= n; v++) {
            if (!in[v]) dfs(v, 0);
        }

        cout << ans << '\n';
    }
}