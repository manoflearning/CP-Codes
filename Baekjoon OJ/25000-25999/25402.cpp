#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> uf(252525, -1);

int find(int x) {
    if (uf[x] < 0) return x;
    return uf[x] = find(uf[x]);
}

void merge(int u, int v) {
    int U = find(u), V = find(v);
    if (U == V) return;
    uf[U] += uf[V];
    uf[V] = U;
}

int n, k, par[252525], exist[252525];
vector<int> adj[252525], arr;

int vi[252525];
void dfs(int v, int prv) {
    vi[v] = 1;
    for (auto& i : adj[v]) {
        if (vi[i]) continue;
        par[i] = v;
        dfs(i, v);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int q; cin >> q;
    while (q--) {
        cin >> k;
        arr.resize(k);
        for (auto& i : arr) {
            cin >> i;
            exist[i] = 1;
        }

        for (auto& i : arr) {
            if (exist[i] && exist[par[i]]) {
                merge(i, par[i]);
            }
        }

        set<int> s;
        for (auto& i : arr)
            s.insert(find(i));

        ll ans = 0;
        for (auto& i : s) {
            ans += -uf[i] * (-uf[i] - 1) / 2;
        }

        cout << ans << '\n';

        for (auto& i : arr) {
            uf[i] = -1;
            exist[i] = 0;
        }
    }
}