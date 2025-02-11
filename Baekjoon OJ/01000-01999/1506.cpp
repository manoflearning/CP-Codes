#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXV = 101;

int n, w[MAXV];
vector<int> adj[MAXV], radj[MAXV];
int in[MAXV], out[MAXV], num, p[MAXV << 1];
int vi[MAXV], cnt;
vector<vector<int>> scc;
ll ans = 0;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '0') continue;
            adj[i].push_back(j);
            radj[j].push_back(i);
        }
    }
}

void dfs(int v) {
    in[v] = ++num;
    for (auto& i : radj[v]) {
        if (!in[i]) dfs(i);
    }
    out[v] = ++num;
    p[num] = v;
}

void flood(int v) {
    scc[cnt].push_back(v);
    vi[v] = cnt;
    for (auto& i : adj[v]) {
        if (!vi[i]) flood(i);
    }
}

void kosaraju() {
    for (int v = 1; v <= n; v++) {
        if (!in[v]) dfs(v);
    }
    
    for (int v = 2 * n; v >= 1; v--) {
        if (!p[v]) continue;
        if (vi[p[v]]) continue;
        cnt++;
        scc.resize(cnt + 1);
        flood(p[v]);
    }
}

void getAns() {
    for (auto& i : scc) {
        if (i.empty()) continue;
        int res = 1e9 + 7;
        for (auto& j : i) res = min(res, w[j]);
        ans += res;
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

    kosaraju();

    getAns();

    cout << ans;

    return 0;
}