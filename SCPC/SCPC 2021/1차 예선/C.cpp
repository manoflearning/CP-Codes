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

int n, m, k, vi[505], en;
vt<int> adj[505];

void init() {
    FOR(505) adj[i].clear();
}

void input() {
    cin >> n >> m >> k;
    FOR(m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

int dfs(int v) {
    vi[v] = 1;

    if (v == en) return 1;

    int ret = 0;
    EACH(i, adj[v]) 
        if (!vi[i]) ret |= dfs(i);

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
    FOR(tt, 1, tc + 1) {
        cout << "Case #" << tt << '\n';

        init();

        input();

        FOR(k) {
            int u, v;
            cin >> u >> v;

            en = u;
            memset(vi, 0, sizeof(vi));

            if (dfs(v)) {
                cout << 1;
                adj[v].push_back(u);
            }
            else {
                cout << 0;
                adj[u].push_back(v);
            }
        }
        cout << '\n';
    }

	return 0;
}