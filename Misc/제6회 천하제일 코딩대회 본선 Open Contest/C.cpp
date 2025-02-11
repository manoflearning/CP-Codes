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

struct cv {
    int c, v, idx;
    bool operator<(const cv& rhs) const {
        return c < rhs.c;
    }
    bool operator<(const int& rhs) const {
        return c < rhs;
    }
};

ll n, a[202020], b[202020];
vt<cv> adj[202020];
vt<int> co[202020], vi[202020];
ll w[202020];

void input() {
    cin >> n;
    FOR(n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        
        adj[u].push_back({ c, v, 0 });
        adj[v].push_back({ c, u, 0 });
    }
    FOR(i, 1, n + 1) cin >> a[i];
    FOR(i, 1, n + 1) cin >> b[i];
}

vt<int> res;

void dfs(int v, int idx, int c) {
    vi[v][idx] = 1;
    res.push_back(v);
    
    int l = lower_bound(all(adj[v]), c) - adj[v].begin();
    int r = lower_bound(all(adj[v]), c + 1) - adj[v].begin();

    FOR(i, l, r) {
        auto& e = adj[v][i];
        if (e.c ^ c) continue;
        if (vi[e.v][e.idx]) continue;

        dfs(e.v, e.idx, c);
    }
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

    FOR(v, 1, n + 1) {
        EACH(i, adj[v]) co[v].push_back(i.c);
        
        sort(all(co[v]));
        co[v].erase(unique(all(co[v])), co[v].end());

        vi[v].resize(sz(co[v]));
    }

    FOR(v, 1, n + 1) {
        EACH(i, adj[v]) {
            i.idx = lower_bound(all(co[i.v]), i.c) - co[i.v].begin();
        }

        sort(all(adj[v]));
    }

    FOR(v, 1, n + 1) {
        FOR(i, sz(co[v])) {
            if (vi[v][i]) continue;
            
            dfs(v, i, co[v][i]);

            ll sum = 0;
            EACH(j, res) sum += a[j];
            EACH(j, res) w[j] += sum;

            res.clear();
        }
    }

    ll ans1 = 0, ans2 = 0;
    sort(w + 1, w + 1 + n);
    sort(b + 1, b + 1 + n);

    FOR(i, 1, n + 1) {
        ans1 += w[n - i + 1] * b[i];
        ans2 += w[i] * b[i];
    }

    cout << ans1 << '\n' << ans2;

	return 0;
}