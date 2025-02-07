#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[101010];
int AB[101010];
vector<int> A, B;

void input() {
    cin >> n;
    for (int v = 1; v <= n; v++) {
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int u; cin >> u;
            adj[v].push_back(u);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    while (1) {
        int isDone = 1;
        for (int v = 1; v <= n; v++) {
            int cnt = 0;
            for (auto& u : adj[v]) {
                cnt += (AB[u] == AB[v]);
            }
            if (cnt >= 2) {
                isDone = 0;
                AB[v] = !AB[v];
            }
        }
        if (isDone) break;
    }
    
    for (int v = 1; v <= n; v++) {
        if (AB[v]) B.push_back(v);
        else A.push_back(v);
    }

    if (B.empty()) {
        B.push_back(A.back());
        A.pop_back();
    }

    cout << A.size() << ' ';
    for (auto& i : A) cout << i << ' ';
    cout << '\n';
    cout << B.size() << ' ';
    for (auto& i  : B) cout << i << ' ';
    cout << '\n';
}