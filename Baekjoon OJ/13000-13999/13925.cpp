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

struct Seg { // 1-based
	int flag;  // array size
	vector<ll> t;
	vector<pll> lazy;

	void build(int N, const vt<ll>& a) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
		lazy.resize(2 * flag, { 1, 0 });

		for (int i = flag; i < flag + N; i++) t[i] = a[i - flag];
		for (int i = flag - 1; i >= 1; i--) t[i] = (t[i << 1] + t[i << 1 | 1]) % MOD;
	}
	void modify(int l, int r, pll value) {
		return modify(l, r, 1, 1, flag, value);
	}
	// add a value to all elements in interval [l, r]
	void modify(int l, int r, int n, int nl, int nr, pll value) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			lazy[n].fr = (lazy[n].fr * value.fr) % MOD;
			lazy[n].sc = (lazy[n].sc * value.fr) % MOD;
			lazy[n].sc = (lazy[n].sc + value.sc) % MOD;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, n << 1, nl, mid, value);
		modify(l, r, n << 1 | 1, mid + 1, nr, value);

		t[n] = (t[n << 1] + t[n << 1 | 1]) % MOD;
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return (query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr)) % MOD;
	}
	void propagate(int n, int nl, int nr) {
		if (lazy[n].fr == 1 && lazy[n].sc == 0) return;

		if (n < flag) {
			lazy[n << 1].fr = (lazy[n << 1].fr * lazy[n].fr) % MOD;
			lazy[n << 1].sc = (lazy[n << 1].sc * lazy[n].fr) % MOD;
			lazy[n << 1].sc = (lazy[n << 1].sc + lazy[n].sc) % MOD;
			lazy[n << 1 | 1].fr = (lazy[n << 1 | 1].fr * lazy[n].fr) % MOD;
			lazy[n << 1 | 1].sc = (lazy[n << 1 | 1].sc * lazy[n].fr) % MOD;
			lazy[n << 1 | 1].sc = (lazy[n << 1 | 1].sc + lazy[n].sc) % MOD;
		}
		t[n] = (lazy[n].fr * t[n] + lazy[n].sc * (nr - nl + 1)) % MOD;
		lazy[n] = { 1, 0 };
	}
}seg;

int n;
vt<ll> a;

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
	a.resize(n);
	EACH(i, a) cin >> i;
	seg.build(n, a);

	int q; cin >> q;
	while (q--) {
		ll op, x, y, z;
		cin >> op >> x >> y;
		if (op <= 3) {
			cin >> z;
			if (op == 1) seg.modify(x, y, { 1, z });
			if (op == 2) seg.modify(x, y, { z, 0 });
			if (op == 3) seg.modify(x, y, { 0, z });
		}
		else if (op == 4) cout << seg.query(x, y) << '\n';
	}

	return 0;
}