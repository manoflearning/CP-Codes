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

set<int> s[101010];
vt<int> p(101010, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    int A = find(a), B = find(b);
    if (A == B) return;
    
    if (sz(s[B]) > sz(s[A])) swap(A, B);
    p[A] += p[B];
    p[B] = A;
    EACH(i, s[B]) s[A].insert(i);
}

struct opx { int op, x; };

int n, q;
int par[101010], co[101010], del[101010];
vt<opx> qu;
vt<int> ans;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
    FOR(v, 2, n + 1) {
        cin >> par[v];
    }

    FOR(v, 1, n + 1) {
        cin >> co[v];
        s[v].insert(co[v]);
    }

    qu.resize(n + q - 1);
    EACH(i, qu) {
        cin >> i.op >> i.x;
        if (i.op == 1) del[i.x] = 1;
    }

    FOR(v, 2, n + 1) {
        if (!del[v])
            merge(v, par[v]);
    }

    FOR(i, n + q - 2, -1, -1) {
        auto it = qu[i];
        if (it.op == 2) ans.push_back(sz(s[find(it.x)]));
        else {
            merge(it.x, par[it.x]);
        }
    }

    for (int i = sz(ans) - 1; i >= 0; i--) 
        cout << ans[i] << '\n';

	return 0;
}