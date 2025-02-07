#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vs vector<string>
#define vvs vector<vector<string>>
 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
 
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	int tc; cin >> tc;
 
	while (tc--) {
		ll a, s;
		cin >> a >> s;
 
		if (2 * a <= s) {
			ll x = s - 2 * a;
			ll f = 0;
 
			for (; (1LL << f) <= x; f++);
 
			for (int i = f; i >= 0; i--) {
				if (a & (1LL << i)) continue;
				if (x >= (1LL << i)) x -= (1LL << i);
			}
 
			if (!x) cout << "Yes\n";
			else cout << "No\n";
		}
		else cout << "No\n";
	}
 
	return 0;
}
