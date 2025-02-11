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

struct point {
    ll y, x;
    int idx;
};  

int n;
vt<point> p;
vt<int> cc, py[1010], px[1010];

void init() {
    p.clear();
    FOR(sz(cc)) {
        py[i].clear();
        px[i].clear();
    }
    cc.clear();
}

void co() {
    EACH(i, p) {
        cc.push_back(i.x);
        cc.push_back(i.y);
    }

    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());
}

int Hash(int val) {
    return lower_bound(all(cc), val) - cc.begin();
}

ll cal(int v) {
    FOR(sz(cc)) {
        py[i].clear();
        px[i].clear();
    }

    EACH(i, p) {
        if (i.idx == v) continue;
        py[Hash(i.y)].push_back(i.idx);
        px[Hash(i.x)].push_back(i.idx);
    }

    ll ret = 0;
    FOR(sz(cc)) {
        if (sz(py[i]) & 1) return -INF;
        if (sz(px[i]) & 1) return -INF;

        sort(all(py[i]));
        sort(all(px[i]));

        FOR(j, 0, sz(py[i]), 2) {
            int u = py[i][j], v = py[i][j + 1];
            ret += abs(p[u].x - p[v].x);
        }
        FOR(j, 0, sz(px[i]), 2) {
            int u = px[i][j], v = px[i][j + 1];
            ret += abs(p[u].y - p[v].y);
        }
    }

    return ret;
}

int main() {
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);

	setbuf(stdout, NULL);

	int tc; cin >> tc;
    FOR(tt, 1, tc + 1) {
        printf("Case #%d\n", tt);
        
        init();

        scanf("%d", &n);
        p.resize(n);
        FOR(n) {
            scanf("%lld %lld", &p[i].x, &p[i].y);
            p[i].idx = i;
        }

        co();

        ll ans = max(0ll, cal(-1));
        FOR(n) {
            ans = max(ans, cal(i));
        }
        printf("%lld\n", ans);
    }

	return 0;
}