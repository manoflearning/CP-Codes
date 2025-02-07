// 홀수 크기의 부분 트리에 연산을 적용하는 일은 의미가 없음 -> 짝수 크기의 부분 트리만을 고려
// 각각 u, v를 루트로 하는 짝수 크기의 부분 트리에 연산을 적용할 때,
// lca(u, v) == u or v이면 둘 중 dep가 작은 노드(조상 노드)만을 고려하면 됨. 둘 모두에 연산을 적용할 필요 X.
// 따라서 disjoint한 서브 트리들에 연산을 적용하면 됨.
// tree dp로 해결.

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, w[202020], all, sub[202020], siz[202020];
vector<int> adj[202020], t[202020];
int dp[202020][32];

void dfsInit(int v, int prv) {
    sub[v] ^= w[v];
    siz[v]++;
    for (auto& i : adj[v]) {
        if (i == prv) continue;
        t[v].push_back(i);
        dfsInit(i, v);
        sub[v] ^= sub[i];
        siz[v] += siz[i];
    }
}

void dfs(int v) {
    if (!(siz[v] & 1))
        dp[v][sub[v]] = 1;

    for (auto& u : t[v]) dfs(u);

    vector<int> knap(32), tmp(32);
    knap[0] = 1;
    for (auto& u : t[v]) {
        for (int i = 0; i < 32; i++) {
            if (!dp[u][i]) continue;
            for (int j = 0; j < 32; j++) {
                if (knap[j] && !knap[j ^ i]) tmp[j ^ i] = 1;
            }
        }

        for (int i = 0; i < 32; i++)
            if (tmp[i]) knap[i] = 1;
        
        tmp.clear();
        tmp.resize(32);
    }

    for (int i = 0; i < 32; i++) {
        dp[v][i] |= knap[i];
    }
}

vector<int> ans;

void rdfs(int v, int sum) {
    if (!(siz[v] & 1) && sum == sub[v]) {
        ans.push_back(v);
        return;
    }

    vector<int> knap(32), tmp(32);
    vector<pii> track(32);
    knap[0] = 1;
    track[0] = { 0, 0 };
    for (auto& u : t[v]) {
        for (int i = 0; i < 32; i++) {
            if (!dp[u][i]) continue;
            for (int j = 0; j < 32; j++) {
                if (knap[j] && !knap[j ^ i]) {
                    tmp[j ^ i] = 1;
                    track[j ^ i] = { i, u };
                }
            }
        }

        for (int i = 0; i < 32; i++)
            if (tmp[i]) knap[i] = 1;
        
        tmp.clear();
        tmp.resize(32);
    }

    for (int i = sum; i != 0; i = (i ^ track[i].fr)) {
        rdfs(track[i].sc, track[i].fr);
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
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        all ^= w[i];
    }

    for (int v = 2; v <= n; v++) {
        int u; cin >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    if (!(n & 1)) {
        cout << 2 << '\n';
        cout << 1 << ' ' << 1;
        return 0;
    }

    dfsInit(1, 0);

    dfs(1);
    
    if (dp[1][all]) {
        rdfs(1, all);

        cout << sz(ans) + 2 << '\n';
        for (auto& i : ans)
            cout << i << ' ';
        cout << 1 << ' ' << 1;
        return 0;
    }
    else cout << -1;

	return 0;
}