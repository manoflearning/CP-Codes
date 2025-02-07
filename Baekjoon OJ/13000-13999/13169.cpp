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

const int MAXD = 35;

int n, mid;
vt<ll> a, L, R, R2[MAXD + 1];

void bt(int idx, ll sum, int rb) {
    if (idx == rb) {
        if (rb == mid + 1) L.push_back(sum);
        if (rb == n) R.push_back(sum);
        return;
    }

    bt(idx + 1, sum, rb);
    bt(idx + 1, sum + a[idx], rb);
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

	cin >> n;
    a.resize(n);
    EACH(i, a) cin >> i;

    if (n == 1) {
        cout << a[0];
        return 0;
    }

    mid = (n - 1) / 2;
    
    bt(0, 0, mid + 1);
    bt(mid + 1, 0, n);
    
    EACH(i, R) {
        FOR(d, MAXD + 1) {
            R2[d].push_back(i % (1ll << (d + 1)));
        }
    }

    FOR(d, MAXD + 1) sort(all(R2[d]));

    ll ans = 0;
    EACH(x, L) {
        FOR(d, MAXD + 1) {
            ll y = x % (1ll << (d + 1));

            ll val = (1ll << d), val2 (1ll << (d + 1));
            int l = lower_bound(all(R2[d]), val - y) - R2[d].begin();
            int r = lower_bound(all(R2[d]), val2 - y) - R2[d].begin();

            if ((r - l) & 1) ans ^= (1ll << d);

            val = (1ll << d) + (1ll << (d + 1));
            l = lower_bound(all(R2[d]), val - y) - R2[d].begin();
            r = R2[d].end() - R2[d].begin();

            if ((r - l) & 1) ans ^= (1ll << d);
        }
    }

    cout << ans;

	return 0;
}