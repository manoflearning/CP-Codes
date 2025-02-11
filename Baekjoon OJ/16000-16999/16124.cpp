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
const int MOD = 998244353;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Seg { // 1-based
	int flag;  // array size
    vector<ll> p10, len;
	vector<vt<ll>> t;
    vector<vt<int>> lazy;

    vt<ll> concat(const vt<ll>& u, const vt<ll>& v, int len) {
        vt<ll> ret(10);
        FOR(10) ret[i] = (p10[len - 1] * u[i] + v[i]) % MOD;
        return ret;
    }

	void build(int N, const string& s) {
        p10.resize(N + 1);
        p10[0] = 1;
        FOR(i, 1, N + 1) p10[i] = 10 * p10[i - 1] % MOD;

		for (flag = 1; flag < N; flag <<= 1);

		lazy.resize(2 * flag, vt<int>(10));
        FOR(i, 2 * flag) FOR(j, 10) lazy[i][j] = j;

        len.resize(2 * flag);
        len[1] = flag;
        for (int i = 1; i < flag; i++) len[i << 1] = len[i << 1 | 1] = len[i] / 2;

        t.resize(2 * flag, vt<ll>(10));
		for (int i = flag; i < flag + N; i++) t[i][s[i - flag] - '0']++;
        for (int i = flag - 1; i >= 1; i--) t[i] = concat(t[i << 1], t[i << 1 | 1], len[i << 1 | 1] + 1);
	}
	void modify(int l, int r, int from, int to) {
		return modify(l, r, 1, 1, flag, from, to);
	}
	void modify(int l, int r, int n, int nl, int nr, int from, int to) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			//compose(lazy[n], from, to);
            lazy[n][from] = to;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, n << 1, nl, mid, from, to);
		modify(l, r, n << 1 | 1, mid + 1, nr, from, to);

		t[n] = concat(t[n << 1], t[n << 1 | 1], len[n << 1 | 1] + 1);
	}
	ll query(int l, int r) {
		vt<ll> res = query(l, r, 1, 1, flag);
        ll ret = 0;
        FOR(10) ret = (ret + i * res[i]) % MOD;
        return ret;
	}
	vt<ll> query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
        if (mid + 1 <= r) return concat(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr), max(1, min(nr, r) - mid + 1));
        else return query(l, r, n << 1, nl, mid);
	}
	void propagate(int n, int nl, int nr) {
        int bit = 1;
        FOR(10) if (lazy[n][i] != i) bit = 0;
        if (bit) return;
        
		if (n < flag) {
            vt<int> tmpLazy1(10), tmpLazy2(10);
            FOR(10) {
                tmpLazy1[i] = lazy[n][lazy[n << 1][i]];
                tmpLazy2[i] = lazy[n][lazy[n << 1 | 1][i]];
            }
            lazy[n << 1] = tmpLazy1;
            lazy[n << 1 | 1] = tmpLazy2;
		}

        vt<ll> tmp(10);
		FOR(10) {
            tmp[lazy[n][i]] = (tmp[lazy[n][i]] + t[n][i]) % MOD;
            lazy[n][i] = i;
        }
        t[n] = tmp;
	}
}seg;

int n;
string s;

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
    n = sz(s);
    seg.build(n, s);

    /*FOR(len, 1, n + 1) {
        FOR(l, 1, n + 1) {
            int r = l + len - 1;
            if (r > n) continue;
            cout << l << ' ' << r << ' ' << seg.query(l, r) << '\n';
        }
        cout << '\n';
    }*/

    int q; cin >> q;
    while (q--) {
        ll op, aa, bb, cc, dd;
        cin >> op >> aa >> bb;
        if (op == 1) {
            cin >> cc >> dd;
            seg.modify(aa, bb, cc, dd);
        }
        if (op == 2) {
            cout << seg.query(aa, bb) << '\n';
        }
    }
    
	return 0;
}