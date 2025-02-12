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

const int MAX = 202020;

vt<ll> p(MAX, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

ll getVal(int x) {
    if (p[x] < 0) return -p[x];
    return getVal(p[x]);
}

void merge(int a, int b) {
    int A = find(a), B = find(b);
    if (A == B) return;
    p[A] = max(p[A], p[B]);
    p[B] = A;
}

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};

int n, m;
vt<Edge> e;

void input() {
    cin >> n >> m;
    FOR(m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        e.push_back({ u, v, w });
    }
    FOR(i, 1, n + 1) {
        ll x; cin >> x;
        p[i] = -x;
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

    sort(all(e));

    ll ans = 0;
    EACH(i, e) {
        if (find(i.u) == find(i.v)) continue;

        if (min(getVal(i.u), getVal(i.v)) + i.w <= getVal(i.u) + getVal(i.v)) {
            ans += i.w;
            merge(i.u, i.v);
        }
    }

    vt<int> a;
    FOR(i, 1, n + 1) {
        a.push_back(find(i));
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());

    EACH(i, a) ans += getVal(i);
    
    cout << ans;

	return 0;
}