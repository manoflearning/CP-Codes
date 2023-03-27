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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	cout << "YES\n";
	vector<int> ans(n + 1), ans2;
	int now = 1;
	for (int i = n - 1, bit = 0; i >= 1; i--, bit = !bit) {
		ans[now] = i;
		ans2.push_back(now);
		if (!bit) now += i;
		else now -= i;
	}
	ans[now] = n;
	ans2.push_back(now);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
	for (auto& i : ans2)
		cout << i << ' ';

	return 0;
}