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

int n;
string s1, s2;

void init() {

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

		cin >> n >> s1 >> s2;

		int bit = 0;
		EACH(i, s1) bit |= (i == '1');
		EACH(i, s2) bit |= (i == '1');

		if (!bit) {
			cout << "YES" << '\n';
			cout << 0 << '\n';
			continue;
		}

		int same = 0, diff = 0;
		for (int i = 0; i < sz(s1); i++) {
			if (s1[i] == s2[i]) same = 1;
			if (s1[i] != s2[i]) diff = 1;
		}

		if (same && diff) {
			cout << "NO\n";
			continue;
		}

		vt<pii> ans;
		for (int i = 0; i < sz(s1); i++) {
			if (s1[i] == '1') {
				ans.push_back({ i + 1, i + 1 });
			}
		}
		
		if ((diff && (sz(ans) & 1)) || (same && !(sz(ans) & 1))) {
			cout << "YES\n";
			cout << sz(ans) << '\n';
			EACH(i, ans)
				cout << i.fr << ' ' << i.sc << '\n';
		}
		else {
			ans.push_back({ 1, n });
			ans.push_back({ 1, 1 });
			ans.push_back({ 2, n });
			cout << "YES\n";
			cout << sz(ans) << '\n';
			EACH(i, ans)
				cout << i.fr << ' ' << i.sc << '\n';
		}
	}

	return 0;
}