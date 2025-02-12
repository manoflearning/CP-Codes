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
const int MOD = 1e9;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m, vi[10101], fi[10101], isC, isO;
vt<int> adj[10101];
ll dp[10101];
vt<int> c;

void ck(int v) {
	vi[v] = true;
	for (int next : adj[v]) {
		if (!vi[next]) ck(next);
		//vi[next]가 참인 정점 next에 대해 fi[next]가 거짓이라면, 이는 사이클이 존재함을 뜻한다. 
		//그래프에 사이클이 존재할 경우 위상 정렬 문제는 정의되지 않는다.
		else if (!fi[next]) { c.push_back(v); isC = true; }
	}
	fi[v] = true;
}

int find2(int v) {
    vi[v] = 1; 
    if (v == 2) return 1;
    int ret = 0;
    EACH(i, adj[v]) {
        if (!vi[i]) ret |= find2(i);
    }
    return ret;
}

ll f(int v) {
    ll& ret = dp[v];
    if (ret != -1) return ret;
    if (v == 2) return ret = 1;
    ret = 0;
    EACH(i, adj[v]) {
        ret += f(i);
        if (ret >= MOD) {
            isO = 1, ret %= MOD;
        }
    }
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

	cin >> n >> m;
    FOR(m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 예외 처리 1: 1에서 2로 도달 불가능
    if (!find2(1)) {
        cout << 0;
        return 0;
    }

    // 예외 처리 2: 1에서 2로 가는 경로 중 싸이클 or self-loop을 포함하는 경로가 존재
    memset(vi, 0, sizeof(vi));
    ck(1);
    if (isC) {
        memset(vi, 0, sizeof(vi));
        int bit = 0;
        EACH(i, c) bit |= find2(i);
        if (bit) {
            cout << "inf";
            return 0;
        }
    }

    // 이제 1에서 출발해서 2로 갈 수 있는 경로가 존재하며, 1을 포함하는 컴포넌트는 DAG다.
    FOR(10101) dp[i] = -1;
    ll res = f(1), d = 0;
    if (isO) {
        for (ll i = 1; i <= res; i *= 10, d++);
        FOR(9 - d) cout << 0;
    }
    cout << f(1);

	return 0;
}