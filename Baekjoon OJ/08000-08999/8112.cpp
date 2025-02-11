#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        vector<int> dist(n + 1, -1), prv(n + 1, -1), bit(n + 1);

        queue<int> q;
        q.push(1 % n);
        dist[1 % n] = 0;
        bit[1 % n] = 1;

        string ans;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v % n == 0) {
                while (v != -1) {
                    ans.push_back('0' + bit[v]);
                    v = prv[v];
                }
                reverse(ans.begin(), ans.end());
                break;
            }
            for (int i = 0; i < 2; i++) {
                int u = (v * 10 + i) % n;
                if (dist[u] != -1) continue;
                q.push(u);
                dist[u] = dist[v] + 1;
                prv[u] = v;
                bit[u] = i;
            }
        }

        cout << (ans.empty() ? "BRAK" : ans) << '\n';
    }
}