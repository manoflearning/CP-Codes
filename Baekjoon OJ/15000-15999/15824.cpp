#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
const int MAX = 3e5;

int n;
ll Exp[MAX + 5];
vector<ll> a;

void init() {
	Exp[0] = 1;
	for (int i = 1; i <= MAX; i++) {
		Exp[i] = 2 * Exp[i - 1] % MOD;
	}
}

void input() {
	cin >> n;

	a.resize(n);
	for (auto& i : a) cin >> i;
}

ll f() {
	ll ans = 0;

	for (int i = 1; i < n; i++) {
		ll x = a[i] - a[i - 1];
		x = (x * (Exp[i] - 1 + MOD) % MOD) % MOD;
		x = (x * (Exp[n - i] - 1 + MOD) % MOD) % MOD;
		ans += x;
		ans %= MOD;
	}

	return ans;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	init();

	input();

	sort(a.begin(), a.end());
	
	cout << f();

	return 0;
}
