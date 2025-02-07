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

struct uvw {
    int u, v;
    ll w;
    bool operator<(const uvw& rhs) const {
        return w > rhs.w;
    }
};

int n, m;
vt<int> p;

vt<uvw> e;

vector<int> uf(101010, -1);

int find(int x) {
	if (uf[x] < 0) return x;
	return uf[x] = find(uf[x]);
}

void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	uf[A] += uf[B];
	uf[B] = A;
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
    p.resize(n + 1);
    FOR(i, 1, n + 1) cin >> p[i];

    e.resize(m);
    EACH(i, e) cin >> i.u >> i.v >> i.w;

    int bit = 1;
    FOR(i, 1, n + 1) {
        if (i != p[i]) bit = 0;
    }

    if (bit) {
        cout << -1;
        return 0;
    }

    sort(all(e));

    int l = 0, r = m - 1;
    while (l < r) {
        uf.clear();
        uf.resize(101010, -1);

        int mid = (l + r) >> 1;
        FOR(i, mid + 1) {
            merge(e[i].u, e[i].v);
        }

        int bit = 1;
        FOR(i, 1, n + 1) {
            if (i != p[i] && find(i) != find(p[i])) bit = 0;
        }
        
        if (bit) r = mid;
        else l = mid + 1;
    }

    cout << e[l].w;

	return 0;
}