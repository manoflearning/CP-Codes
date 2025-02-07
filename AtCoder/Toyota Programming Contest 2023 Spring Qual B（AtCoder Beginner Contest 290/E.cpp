//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, a[202020];
vector<int> idx[202020];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idx[a[i]].push_back(i);
	}

	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i <= (n + 1) / 2) {
			ans += (n - i + 1 - i) * i;
			ans += (i - 1) * i / 2;
		}
		else {
			ans += (n - i) * (n - i + 1) / 2;
		}
	}

	for (int x = 1; x <= n; x++) {
		if (sz(idx[x]) == 1) continue;

		vector<ll> psum(sz(idx[x]) + 1);
		for (int i = sz(idx[x]) - 1; i >= 0; i--) {
			psum[i] = (n - idx[x][i] + 1) + psum[i + 1];
		}
		for (int i = 0; i < sz(idx[x]) - 1; i++) {
			int s = idx[x][i];
			int p = upper_bound(all(idx[x]), n - s + 1) - idx[x].begin();

			if (p <= i) p = i + 1;
			if (p > i) {
				ans -= (p - i - 1) * (ll)s;
				ans -= psum[p];
				//cout << (p - i - 1) * (ll)s << ' ' << psum[p] << '\n';
			}
		}
	}

	cout << ans;

	return 0;
}