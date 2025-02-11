#define _USE_MATH_DEFINES
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

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m;
vt<int> a[1010];
pair<vt<int>, vt<int>> suba[1010];
pii edge[1010];
vt<vt<int>> b;

struct vidx {
    int v, idx;
};

int N, M;
vt<vidx> adj[2020];
int ind[2020], outd[2020], nxt[2020], vi[2020][2020];
vt<int> ans;

void input() {
    cin >> n >> m;
    FOR(n - m + 1) {
        a[i].resize(m);
        EACH(j, a[i]) cin >> j;
    }
}

void cc() {
    FOR(n - m + 1) {
        vt<int> v, u;
        FOR(j, m) {
            if (j < m - 1) v.push_back(a[i][j]);
            if (j > 0) u.push_back(a[i][j]);
        }

        suba[i] = { v, u };
        b.push_back(v);
        b.push_back(u);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    FOR(n - m + 1) {
        edge[i].fr = lower_bound(all(b), suba[i].fr) - b.begin();
        edge[i].sc = lower_bound(all(b), suba[i].sc) - b.begin();
    }
}

void makingGraph() {
    N = sz(b), M = n - m + 1;
    FOR(M) {
        adj[edge[i].fr].push_back({ edge[i].sc, i });
        ind[edge[i].sc]++;
        outd[edge[i].fr]++;
    }
}

void dfs(int now) {
    for (int& i = nxt[now]; i < sz(adj[now]); i++) {
        if (i < sz(adj[now]) && !vi[now][i]) {
            vi[now][i] = 1;
            dfs(adj[now][i].v);
        }
    }
    ans.push_back(now);
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();

    cc();

    makingGraph();

    FOR(i, N) {
        if (ind[i] + 1 == outd[i] && !vi[i][0]) {
            dfs(i);
        }
    }

    if (ans.empty()) dfs(0);

    FOR(i, sz(ans) - 1, 0, -1) {
        cout << b[ans[i]][0] << ' ';
    }
    EACH(i, b[ans[0]]) cout << i << ' ';

	return 0;
}