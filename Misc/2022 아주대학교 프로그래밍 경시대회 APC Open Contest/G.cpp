#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

const int MAXN = 505050;  // limit for array size
struct Seg {  // 0-indexed
	int n;  // array size
	ll t[2 * MAXN];
	void build(int N) {
		n = N;
		for (int i = 0; i < n; i++) cin >> t[n + i];
		for (int i = n - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void modify(int p, ll value) {  // set value at position p
		for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll query(int l, int r) {  // sum on interval [l, r)
        r++;
		ll ret = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret += t[l++];
			if (r & 1) ret += t[--r];
		}
		return ret;
	}
}seg;

int n, m, s, mxCnt;
vt<int> q;

int cnt[505050], prvIdx[505050];
vt<pii> c(1, { -INF, -INF });

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;
    cin >> m;
    q.resize(m);
    EACH(i, q) cin >> i;

    c.push_back({ 0, -0 });
    for (int i = 0; i < m; i++) {
        int x = q[i];
        cnt[x]++;
        c.push_back({ cnt[x], -i });
        mxCnt = max(mxCnt, cnt[x]);
    }

    sort(all(c));
    c.erase(unique(all(c)), c.end());

    memset(cnt, 0, sizeof(cnt));
    
    seg.build(sz(c) + 2);
    seg.modify(1, n);

    for (int i = 0; i < m; i++) {
        int x = q[i];

        // modify
        pii du = { cnt[x], -prvIdx[x] };
        int prv = lower_bound(all(c), du) - c.begin();

        prvIdx[x] = i;
        cnt[x]++;

        du = { cnt[x], -prvIdx[x] };
        int now = lower_bound(all(c), du) - c.begin();

        seg.modify(prv, -1);
        seg.modify(now, 1);

        // query
        du = { cnt[1], -prvIdx[1] };
        int idx = lower_bound(all(c), du) - c.begin();

        int ans1 = seg.query(idx, sz(c));
        cout << ans1 << ' ';

        if (ans1 <= s) {
            cout << 0 << '\n';
        }
        else {
            int l = 0, r = mxCnt + 1;
            while (l < r) {
                int mid = (l + r) >> 1;

                du = { mid, -INF };
                int lb = lower_bound(all(c), du) - c.begin();

                if (seg.query(lb, sz(c) + 1) >= s) l = mid + 1;
                else r = mid;
            }
            
            cout << max(0, l - cnt[1]) << '\n';
        }
    }

	return 0;
}