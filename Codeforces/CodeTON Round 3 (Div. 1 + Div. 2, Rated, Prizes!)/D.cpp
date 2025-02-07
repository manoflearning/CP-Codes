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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int n;
ll m, a[202020];

void init() {

}

void input() {
	cin >> n >> m;
	FOR(i, 1, n + 1) cin >> a[i];
}

bool isValid() {
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] % a[i]) return 0;
	}
	return 1;
}

vt<ll> p;

void fac(ll x) {
	p.clear();

	if (x % 2 == 0) p.push_back(2);
	while (x % 2 == 0) x /= 2;

	for (ll i = 3; i <= sqrt(x); i += 2) {
		if (x % i == 0) p.push_back(i);
		while (x % i == 0) x /= i;
	}

	if (x > 1) p.push_back(x);
}

ll bt(int idx, int cnt, ll x, ll ub) {
	if (x > ub) return 0;

	if (idx == sz(p)) {
		if (cnt == 0) return 0;

		if (cnt & 1) return ub / x;
		else return -ub / x;
	}

	ll ret = 0;
	ret += bt(idx + 1, cnt, x, ub);
	ret += bt(idx + 1, cnt + 1, x * p[idx], ub);

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

		if (!isValid()) {
			cout << 0 << '\n';
			continue;
		}

		ll ans = 1;
		for (int i = 2; i <= n; i++) {
			ll x = a[i - 1] / a[i];
			// [1, m / a[i]] 구간의 정수들 중 gcd(n, x) = 1을 만족하는 모든 정수 n의 개수.

			fac(x);

			ll d = a[i];
			ll sum = m / d - bt(0, 0, 1, m / d);

			ans = (ans * sum) % MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}