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

int n, k;
vt<ll> a, psum;

void init() {
    a.clear();
    psum.clear();
}

void input() {
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
}

bool f(int l, int r) {
    bool ret = 0;

    ll sum = psum[r] - psum[l - 1];
    //cout << l << ' ' << r << ' ' << sum << '\n';
    ll nsum = sum, mx = sum;
    int nr = -1;
    for (int i = r + 1; i <= n && nsum >= 0; i++) {
        nsum += a[i];
        if (mx < nsum) {
            mx = nsum;
            nr = i;
        }
    }
    
    if (nsum >= 0) return 1;
    if (mx > sum) ret |= f(l, nr);

    nsum = sum, mx = sum;
    //cout << l << ' ' << r << ' ' << nsum << '\n';
    int nl = -1;
    for (int i = l - 1; i >= 1 && nsum >= 0; i--) {
        nsum += a[i];
        if (mx < nsum) {
            mx = nsum;
            nl = i;
        }
    }
    
    if (nsum >= 0) return 1;
    if (mx > sum) ret |= f(nl, r);

    return ret;
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
		init();

        input();
        
        psum.resize(n + 1);
        for (int i = 1; i <= n; i++)
            psum[i] = a[i] + psum[i - 1];
        
        if (f(k, k)) cout << "YES\n";
        else cout << "NO\n";
	}

	return 0;
}