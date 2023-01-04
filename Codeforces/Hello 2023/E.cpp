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
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n;
int query(int idx) {
	string s;
	for (int i = 0; i < n; i++) {
		s.push_back(i == idx ? '0' : '1');
	}
	cout << "? " << idx + 1 << ' ' << s << endl;

	int ret; cin >> ret;
	return ret;
}

void answer(vector<int> arr) {
	string s;
	for (int i = 0; i < n; i++) s.push_back('0');
	for (auto& i : arr) s[i] = '1';
	cout << "! " << s << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	vector<pii> arr;
	for (int i = 0; i < n; i++) {
		int res = query(i);
		arr.push_back({ res, i });
	}

	sort(arr.rbegin(), arr.rend());

	ll sum = 0;
	vector<int> done;
	for (int i = 0; i < n; i++) {
		done.push_back(arr[i].sc);
		sum += arr[i].fr;

		if (sum == (n - sz(done)) * sz(done) + sz(done) * (sz(done) - 1) / 2) {
			answer(done);
			return 0;
		}
	}

	answer(done);

	return 0;
}