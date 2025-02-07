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

int n, cnt1, cnt2, ans = 1, need[202020];
vt<int> adj[202020];

int dfs(int v, int prv) {
    int cnt = 0;

    EACH(i, adj[v]) {
        if (i == prv) continue;
        if (dfs(i, v)) cnt++;
    }

    if (need[v] && cnt == 1) cnt1++;
    if (need[v] && cnt == 2) {
        cnt2++;
        if (prv != 0) ans = 0;
    }
    
    int ret = need[v];
    if (cnt >= 1) ret = 1;
    return ret;
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

    cin >> n;
    FOR(n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        vt<int> b(m);
        EACH(i, b) cin >> i;

        if (m == 1) {
            cout << "YES\n";
            continue;
        }

        EACH(i, b) need[i] = 1;
        FOR(i, 1, n + 1) {
            if (need[i]) { dfs(i, 0); break; }
        }
        EACH(i, b) need[i] = 0;
        //cout << cnt1 << ' ' << cnt2 << '\n';
        
        if (cnt1 == m - 1) cout << "YES\n";
        else if (ans && cnt2 == 1 && cnt1 == m - 3) cout << "YES\n";
        else cout << "NO\n";

        cnt1 = cnt2 = 0;
        ans = 1;
    }

	return 0;
}