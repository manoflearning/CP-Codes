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

int n, p10[] = {1, 10, 100, 1000, 10000 };
double t;
vector<pair<double, int>> a;

int cal2(int l, int r, string s) {
	int ret = 0;
	FOR(i, l, r + 1) ret += p10[r - i] * (s[i] - '0');
	return ret;
}

double cal(string s1, string s2) {
	int y, m, d, h, mi, s;
	y = cal2(0, 3, s1);
	m = cal2(5, 6, s1);
	d = cal2(8, 9, s1);
	h = cal2(0, 1, s2);
	mi = cal2(3, 4, s2);
	s = cal2(6, 7, s2);

	double ret = 0;
	FOR(i, 2019, y) ret += (i == 2020 ? 366 : 365);
	FOR(i, 1, m) {
		if (i == 2) ret += (y == 2020 ? 29 : 28);
		else {
			if (i < 8 && (i & 1)) ret += 31;
			else if (i >= 8 && !(i & 1)) ret += 31;
			else ret += 30;
		}
	}
	ret += d;

	ret *= 24 * 60 * 60;
	ret += h * 60 * 60 + mi * 60 + s;
	
	return ret;
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

	if (n == 0) {
		cout << 0;
		return 0;
	}

    a.resize(n);
    FOR(n) {
		string s1, s2;
        cin >> s1 >> s2 >> a[i].sc;
		a[i].fr = cal(s1, s2);
		if (i == n - 1) t = a[i].fr;
    }

    FOR(n) {
		double res = pow(0.5, (t - a[i].fr) / (365 * 24 * 60 * 60));
		//cout << res << '\n';
        a[i].fr = max(res, pow(0.9, n - 1 - i));
    }

	double ans = 0, ans2 = 0;
	EACH(i, a) ans += i.fr * i.sc, ans2 += i.fr;
	//cout << ans << ' ' << ans2 << '\n';
	//cout << ans / ans2 << '\n';
	cout << round(ans / ans2);

	return 0;
}