// hld + prefix sum
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 232323;

int N, Q;
vector<int> adj[MAXV], g[MAXV];
int siz[MAXV], dep[MAXV], par[MAXV];
int top[MAXV], in[MAXV], out[MAXV], pv;
int psum[MAXV];

void input() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int v, int prv) {
    for (auto& i : adj[v]) {
        if (i == prv) continue;
        g[v].push_back(i);
        dfs(i, v);
    }
}

int dfs1(int v) {
    siz[v] = 1;
    for (auto& i : g[v]) {
        dep[i] = dep[v] + 1, par[i] = v;
        siz[v] += dfs1(i);
        if (siz[i] > siz[g[v][0]]) swap(i, g[v][0]);
    }
    return siz[v];
}

void dfs2(int v) {
    in[v] = ++pv;
    for (auto& i : g[v]) {
        top[i] = (i == g[v][0] ? top[v] : i);
        dfs2(i);
    }
    out[v] = pv;
}

void modify(int u, int v) {
    while (top[u] ^ top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        int st = top[u];
        psum[in[st]]++, psum[in[u] + 1]--;
        u = par[st];
    }
    if (dep[u] > dep[v]) swap(u, v);
    psum[in[u] + 1]++, psum[in[v] + 1]--;
}

int query(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    return psum[in[v]];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    dfs(1, 0);
    top[1] = 1;
    dfs1(1);
    dfs2(1);

    while (Q--) {
        int u, v;
        cin >> u >> v;
        modify(u, v);
    }

    for (int i = 1; i <= pv; i++)
        psum[i] += psum[i - 1];

    int ans = 0;
    pair<int, int> ans2 = { N + 1, N + 1 };
    for (int v = 1; v <= N; v++) {
        for (auto& i : g[v]) {
            int res = query(v, i);
            pair<int, int> res2 = { min(v, i), max(v, i) };

            //cout << res2.first << ' ' << res2.second << ' ' << res << '\n';
            if (ans < res || (ans == res && res2 < ans2)) 
                ans = res, ans2 = res2;
        }
    }
    cout << ans2.first << ' ' << ans2.second << ' ' << ans;
}