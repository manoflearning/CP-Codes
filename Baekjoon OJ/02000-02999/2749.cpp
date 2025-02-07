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
const int MOD = 1000000;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Matrix {
	vt<vt<ll>> a;
	Matrix operator*(const Matrix& rhs) const {
		Matrix ret;
		ret.a.resize(sz(a), vt<ll>(sz(rhs.a[0])));
		for (int y = 0; y < sz(ret.a); y++) {
			for (int x = 0; x < sz(ret.a[y]); x++) {
				ll sum = 0;
				for (int i = 0; i < sz(a[y]); i++) {
					sum = (sum + a[y][i] * rhs.a[i][x]) % MOD;
				}
				ret.a[y][x] = sum;
			}
		}
		return ret;
	}
};

Matrix ma;

Matrix f(Matrix a, ll cnt) {
	if (cnt == 1) return a;

	Matrix res = f(a, cnt / 2);
	if (cnt & 1) return res * res * ma;
	else return res * res;
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
	
	ll n; cin >> n;

	if (n == 0 || n == 1) {
		cout << n;
		return 0;
	}

	ma.a.resize(2, vt<ll>(2));
	ma.a[0][0] = 1, ma.a[0][1] = 1;
	ma.a[1][0] = 1, ma.a[1][1] = 0;

	Matrix res = f(ma, n - 1);

	cout << res.a[0][0];

	return 0;
}