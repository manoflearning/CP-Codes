#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define fr first
#define sc second
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
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Seg {
	int flag;  // array size
	vector<ll> t;

	void build(int N, vector<pii>& a) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);

		for (int i = flag; i < flag + N; i++) t[i] = -1;
		for (auto& i : a) t[i.fr + flag - 1] = i.sc;
		for (int i = flag - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
	void modify(int p, ll value) {  // set value at position p
		for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		if (r < nl || nr < l) return -1;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
	}
}seg;

int n, m;
vector<pii> a, q;
vi co, rHash;

void input() {
	cin >> n;
	a.resize(n);
	for (auto& i : a) {
		cin >> i.fr >> i.sc;
		co.push_back(i.fr);
	}

	cin >> m;
	q.resize(m);
	for (auto& i : q) {
		cin >> i.fr >> i.sc;
		co.push_back(i.fr);
		co.push_back(i.sc);
	}
}

void comp() {
	sort(co.begin(), co.end());
	co.erase(unique(co.begin(), co.end()), co.end());
	rHash.resize(co.size() + 1);

	for (auto& i : a) {
		int x = lower_bound(co.begin(), co.end(), i.fr) - co.begin() + 1;
		rHash[x] = i.fr, i.fr = x;
	}
	for (auto& i : q) {
		i.fr = lower_bound(co.begin(), co.end(), i.fr) - co.begin() + 1;
		i.sc = lower_bound(co.begin(), co.end(), i.sc) - co.begin() + 1;
	}
}

void f() {
	for (auto& i : q) {
		int l = seg.query(i.fr, i.fr), r = seg.query(i.sc, i.sc);
		int segMx = seg.query(i.fr + 1, i.sc - 1);

		int cnt = (l == -1) + (r == -1) + (segMx == -1);

		if (cnt >= 2) cout << "maybe\n";
		if (cnt == 1) {
			int ans = 1;

			if (segMx == -1) ans &= (r <= l);
			if (l == -1) ans &= (segMx < r);
			if (r == -1) ans &= (segMx < l);

			if (ans) cout << "maybe\n";
			else cout << "false\n";
		}
		if (cnt == 0) {
			if (segMx < r && r <= l) {
				if (i.sc - i.fr == rHash[i.sc] - rHash[i.fr]) cout << "true\n";
				else cout << "maybe\n";
			}
			else cout << "false\n";
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	comp();

	seg.build(co.size(), a);

	f();

	return 0;
}
