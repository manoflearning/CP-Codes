#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int flag;  // array size
struct Seg {  // 1-based
	vector<ll> t, lazy;

	void build(int n) {
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag);
		lazy.resize(2 * flag);

		for (int i = flag; i < flag + n; i++) cin >> t[i];
		for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	// add a value to all elements in interval [l, r]
	void modify(int l, int r, ll value, int n = 1, int nl = 1, int nr = flag) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			lazy[n] += value;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, value, n << 1, nl, mid);
		modify(l, r, value, n << 1 | 1, mid + 1, nr);

		t[n] = t[n << 1] + t[n << 1 | 1];
	}
	ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
	}
	void propagate(int n, int nl, int nr) {
		if (lazy[n] != 0) {
			if (n < flag) {
				lazy[n << 1] += lazy[n];
				lazy[n << 1 | 1] += lazy[n];
			}
			t[n] += lazy[n] * (nr - nl + 1);
			lazy[n] = 0;
		}
	}
}seg;

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	
	seg.build(n);

	for (int i = 0; i < m + k; i++) {
		ll op, x, y, z;
		cin >> op >> x >> y;
		if (op == 1) {
			cin >> z;
			seg.modify(x, y, z);
		}
		if (op == 2) cout << seg.query(x, y) << '\n';
	}

	return 0;
}
