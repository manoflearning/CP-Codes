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

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

ll nC2(ll n) {
    return n * (n + 1) / 2;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		ll n, k;
        cin >> n >> k;

        vector<ll> a(n + 1), psum(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            psum[i] = a[i] + psum[i - 1];
        }

        if (k <= n) {
            ll mx = 0;
            for (int s = 1; s <= n; s++) {
                int e = s + k - 1;
                if (e > n) break;
                mx = max(mx, psum[e] - psum[s - 1]);
            }
            mx += nC2(k - 1);
            cout << mx << '\n';
        }
        else {
            cout << psum[n] + nC2(k - 1) - nC2(k - n - 1) << '\n';
        }
	}

	return 0;
}