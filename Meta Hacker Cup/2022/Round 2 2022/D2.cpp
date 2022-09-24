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
	vector<ll> t;

	void build(int n) {
        t.clear();
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag);

		//for (int i = flag; i < flag + n; i++) cin >> t[i];
		//for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void modify(int p, ll value) {  // set value at position p
		for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
	}
}segx[3], seg, segl[3];

int n, m;
int a[1010101];

ll query(int l1, int r1, int l2, int r2) {
    ll diff = seg.query(l1, r1) - seg.query(l2, r2);
    
    ll s2 = segx[2].query(l1, r1);
    ll e1 = segx[1].query(l2, r2);

    ll cnt1 = min(s2, e1);
    cnt1 = min(cnt1, diff / 2);
    diff -= cnt1 * 2;

    if (diff > 0) return -1;
    else {
        ll ret = 0;
        if (r1 < l2) {
            int s1 = l1, e1 = r1;
            while (s1 < e1) {
                int mid = (s1 + e1) >> 1;
                if (segx[2].query(mid, r1) > cnt1) s1 = mid + 1;
                else e1 = mid;
            }
            ret -= segl[2].query(s1, r1);

            int s2 = l2, e2 = r2;
            while (s2 < e2) {
                int mid = (s2 + e2) >> 1;
                if (segx[1].query(l2, mid) >= cnt1) e2 = mid;
                else s2 = mid + 1;
            }
            ret += segl[1].query(l2, s2);
        }
        else {
            int s1 = l1, e1 = r1;
            while (s1 < e1) {
                int mid = (s1 + e1) >> 1;
                if (segx[2].query(l1, mid) >= cnt1) e1 = mid;
                else s1 = mid + 1;
            }
            ret += segl[2].query(l1, s1);

            int s2 = l2, e2 = r2;
            while (s2 < e2) {
                int mid = (s2 + e2) >> 1;
                if (segx[1].query(mid, r2) > cnt1) s2 = mid + 1;
                else e2 = mid;
            }
            ret -= segl[1].query(s2, r2);
        }
        return ret;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	FOR(tt, 1, tc + 1) {
		cout << "Case #" << tt << ": ";

        cin >> n >> m;

        seg.build(n);
        segx[1].build(n);
        segx[2].build(n);
        segl[1].build(n);
        segl[2].build(n);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            seg.modify(i, a[i]);
            segx[a[i]].modify(i, 1);
            segl[a[i]].modify(i, i);
        }

        ll ans = 0;
        while (m--) {
            int x, y, z;
            cin >> x >> y >> z;

            segx[a[x]].modify(x, 0);
            segl[a[x]].modify(x, 0);
            a[x] = y;
            segx[a[x]].modify(x, 1);
            segl[a[x]].modify(x, x);
            
            seg.modify(x, y);
            
            if (seg.query(1, z) > seg.query(z + 1, n)) ans += query(1, z, z + 1, n);
            if (seg.query(1, z) < seg.query(z + 1, n)) ans += query(z + 1, n, 1, z);
        }

        cout << ans << '\n';
	}

	return 0;
}