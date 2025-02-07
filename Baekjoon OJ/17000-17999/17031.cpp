#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second
#define cnt first
#define sum second

const int MOD = 1e9 + 7;
const int MAX = 1515, MAXD = 10;

int N, M;
ll X, Y;

// about graph
struct wv { ll w; int v; };
vector<wv> adj[MAX];
int co[MAX], label;
int dep[MAX], par[MAX][MAXD + 1];
ll w[MAX][MAXD + 1];

// about length of path
unordered_map<int, pll> arr[MAX];
unordered_map<int, pll> dp[MAX];

ll fac[MAX];

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAX; i++)
        fac[i] = i * fac[i - 1] % MOD;
}

void input() {
    cin >> N >> M >> X >> Y;
    for (int i = 0; i < M; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u });
    }
}

void dfs(int v, int prv) {
    co[v] = label;
    par[v][0] = prv;
    dep[v] = dep[prv] + 1;
    for (auto& i : adj[v]) {
        if (i.v != prv) {
            dfs(i.v, v);
            w[i.v][0] = i.w;
        }
    }
}

void buildSparseTable() {
    for (int i = 1; i <= MAXD; i++) {
        for (int v = 1; v <= N; v++) {
            par[v][i] = par[par[v][i - 1]][i - 1];
            w[v][i] = w[v][i - 1] + w[par[v][i - 1]][i - 1];
        }
    }
}

ll lca(int u, int v) {
    ll ret = 0;
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = MAXD; i >= 0; i--)
		if (diff & (1 << i)) { ret += w[u][i]; u = par[u][i]; }
	if (u == v) return ret;
	for (int i = MAXD; i >= 0; i--) {
		if (par[u][i] ^ par[v][i]) {
            ret += w[u][i];
			u = par[u][i];
            ret += w[v][i];
			v = par[v][i];
		}
	}
	return ret += w[u][0] + w[v][0];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    input();

    for (int v = 1; v <= N; v++) {
        if (!co[v]) { label++; dfs(v, 0); }
    }

    buildSparseTable();

    // solve
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (co[i] ^ co[j]) continue;
            int len = min<int>(2500, lca(i, j));
            arr[co[i]][len].cnt++;
            arr[co[i]][len].cnt %= MOD;
            arr[co[i]][len].sum += lca(i, j);
            arr[co[i]][len].sum %= MOD;
        }
    }

    for (auto& i : arr[1]) {
        int len = min<int>(i.fr, 2500);
        dp[1][len].cnt += i.sc.cnt;
        dp[1][len].cnt %= MOD;
        dp[1][len].sum += i.sc.sum;
        dp[1][len].sum %= MOD;
    }

    /*for (auto& i : dp[1]) {
        cout << i.fr << ' ' << i.sc.cnt << ' ' << i.sc.sum << '\n';
    }*/

    for (int v = 2; v <= label; v++) {
        for (auto& i : arr[v]) {
            for (auto& j : dp[v - 1]) {
                int len = min<int>(i.fr + j.fr, 2500);
                dp[v][len].cnt += 2 * i.sc.cnt * j.sc.cnt;
                dp[v][len].cnt %= MOD;
                dp[v][len].sum += 2 * (j.sc.cnt * i.sc.sum + j.sc.sum * i.sc.cnt);
                dp[v][len].sum %= MOD;
            }
        }
    }

    ll ans = 0;
    for (auto& i : dp[label]) {
        if (i.fr + X * label >= Y) {
            ans = (ans + i.sc.sum) % MOD;
            ll left = i.sc.cnt * label % MOD * X % MOD;
            ans = (ans + left) % MOD;
        }
    }

    ans = ans * fac[label - 1] % MOD;
    cout << ans;
}