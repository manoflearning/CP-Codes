#include <bits/stdc++.h>
using namespace std;

int n, m, d, st;
string s;

struct Edge {
    int v, p, l;
};
vector<Edge> adj[606];

void input() {
    cin >> n >> m >> d >> st;
    cin >> s;
    for (int i = 0; i < m; i++) {
        int u, v, p, l;
        cin >> u >> v >> p >> l;
        p--;
        adj[u].push_back({ v, p, l });
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
}