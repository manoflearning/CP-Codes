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

int flag;  // array size
struct Seg {  // 1-indexed
	vector<ll> t, lazy;

	void build(int n) {
        t.clear();
        lazy.clear();
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag, INF);
		lazy.resize(2 * flag, INF);
	}
	// add a value to all elements in interval [l, r]
	void modify(int l, int r, ll value, int n = 1, int nl = 1, int nr = flag) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			lazy[n] = min(lazy[n], value);
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, value, n << 1, nl, mid);
		modify(l, r, value, n << 1 | 1, mid + 1, nr);

		t[n] = min(t[n << 1], t[n << 1 | 1]);
	}
	ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return INF;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return min(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
	}
	void propagate(int n, int nl, int nr) {
		if (lazy[n] != INF) {
			if (n < flag) {
				lazy[n << 1] = min(lazy[n << 1], lazy[n]);
				lazy[n << 1 | 1] = min(lazy[n << 1 | 1], lazy[n]);
			}
			t[n] = min(t[n], lazy[n]);
			lazy[n] = INF;
		}
	}
}segy, segx;

struct Line {
    ll sx, sy, ex, ey, w;
};

struct Canon {
    ll co;
    int bit;
};

ll n, cntl, cntc;
vt<Line> line;
vt<Canon> canon;
vt<ll> cc;
ll ans[101010];

void init() {
    line.clear();
    canon.clear();
    cc.clear();
    FOR(i, cntc) ans[i] = 0;
}

void input() {
    cin >> n >> cntl >> cntc;
    line.resize(cntl);
    EACH(i, line) {
        cin >> i.sx >> i.sy;
        cin >> i.ex >> i.ey >> i.w;
    }
    canon.resize(cntc);
    EACH(i, canon) cin >> i.co >> i.bit;
}

void coComp() {
    EACH(i, line) {
        cc.push_back(i.sx);
        cc.push_back(i.sy);
        cc.push_back(i.ex);
        cc.push_back(i.ey);
    }
    EACH(i, canon) {
        cc.push_back(i.co);
    }

    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());

    EACH(i, line) {
        i.sx = lower_bound(all(cc), i.sx) - cc.begin() + 1;
        i.sy = lower_bound(all(cc), i.sy) - cc.begin() + 1;
        i.ex = lower_bound(all(cc), i.ex) - cc.begin() + 1;
        i.ey = lower_bound(all(cc), i.ey) - cc.begin() + 1;
    }
    EACH(i, canon) {
        i.co = lower_bound(all(cc), i.co) - cc.begin() + 1;
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

	int tc; cin >> tc;
	FOR(tt, 1, tc + 1) {
        init();

		input();

        coComp();

        segx.build(sz(cc));
        segy.build(sz(cc));

        FOR(i, cntc) {
            auto it = canon[i];
            if (it.bit) {
                segx.modify(it.co, it.co, i);
                //segy.modify(1, sz(cc), i);
            }
            else {
                //segx.modify(1, sz(cc), i);
                segy.modify(it.co, it.co, i);
            }
        }

        EACH(i, line) {
            ll idx = segx.query(min(i.sx, i.ex), max(i.sx, i.ex));
            idx = min(idx, segy.query(min(i.sy, i.ey), max(i.sy, i.ey)));
            //cout << i.w << ' ' << idx << '\n';
            if (idx < 101010) ans[idx] = max(ans[idx], i.w);
        }

        FOR(i, cntc) cout << ans[i] << '\n';
	}

	return 0;
}