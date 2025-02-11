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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

const int MAXN = 1e5 + 5;

struct Seg {
	int flag;  // array size
	vector<ll> t, lazy;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
		lazy.resize(2 * flag);
	}
	void modify(int l, int r, int value) {
		return modify(l, r, 1, 1, flag, value);
	}
	// add a value to all elements in interval [l, r]
	void modify(int l, int r, int n, int nl, int nr, int value) {
		propagate(n, nl, nr);

		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			lazy[n] = value;
			propagate(n, nl, nr);
			return;
		}

		int mid = (nl + nr) >> 1;
		modify(l, r, n << 1, nl, mid, value);
		modify(l, r, n << 1 | 1, mid + 1, nr, value);

		t[n] = max(t[n << 1], t[n << 1 | 1]);
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		propagate(n, nl, nr);

		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
	}
	void propagate(int n, int nl, int nr) {
		if (lazy[n] != 0) {
			if (n < flag) {
				lazy[n << 1] = lazy[n];
				lazy[n << 1 | 1] = lazy[n];
			}
			t[n] = lazy[n];
			lazy[n] = 0;
		}
	}
}seg;

int n, w[MAXN], d[MAXN];
vi a;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> d[i];
        a.push_back(d[i]);
        a.push_back(w[i] + d[i] - 1);
    }
}

void comp() {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();
	
	comp();
	
	seg.build(a.size());
	
	for (int i = 0; i < n; i++) {
	    int s = lower_bound(a.begin(), a.end(), d[i]) - a.begin() + 1;
	    int e = lower_bound(a.begin(), a.end(), w[i] + d[i] - 1) - a.begin() + 1;
	    seg.modify(s, e, seg.query(s, e) + 1);
	}
    
    cout << seg.query(1, a.size());
	
	return 0;
}
