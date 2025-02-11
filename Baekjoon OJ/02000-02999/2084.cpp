#include <bits/stdc++.h>
using namespace std;

int n, deg[2020], sum, mx;
int ans[2020][2020];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        sum += deg[i];
        mx = max(mx, deg[i]);
    }

    if ((sum & 1) || mx > sum / 2) {
        cout << -1;
        return 0;
    }

    priority_queue<pair<int, int>> pq;
    for (int v = 1; v <= n; v++) {
        if (!deg[v]) continue;
        pq.push({ deg[v], v });
    }

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        vector<int> used;
        while (deg[v]) {
            int u = pq.top().second;
            pq.pop();
            deg[v]--, deg[u]--;
            ans[v][u] = ans[u][v] = 1;
            used.push_back(u);
        }

        for (auto& i : used)
            if (deg[i]) pq.push({ deg[i], i });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}