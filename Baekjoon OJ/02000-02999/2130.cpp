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

    vector<ll> psum(2020202);
    for (int i = 0; i < n; i++) {
        int s, e;
        ll x, y;
        cin >> s >> e >> x >> y;
        psum[s] += x * y;
        psum[s + e] -= x * y;
    }

    for (int i = 1; i < 2020202; i++) {
        psum[i] += psum[i - 1];
    }

    cout << fixed;
    cout.precision(2);

    ll sum; cin >> sum;
    for (int i = 0; i < 2020202; i++) {
        if (sum > psum[i]) sum -= psum[i];
        else {
            cout << i + (double)sum / psum[i];
            return 0;
        }
    }

    cout << "OVERFLOW";

	return 0;
}