//segment tree
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

struct Seg {
	int flag;  // array size
	vector<ll> t;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
	}
	void modify(int p, ll value) {  // set value at position p
		for (t[p += flag - 1] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
	}
}seg;

struct xidx {
    int x, idx;
};

bool operator<(xidx& a, xidx& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.idx > b.idx;
}

int n;
vector<xidx> a;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back({ x, i + 1 });
    }
}

void f() {
    for (auto& i : a) {
        seg.modify(i.idx, seg.query(1, i.idx - 1) + 1);
    }
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();
	
	seg.build(n);
	
	sort(a.begin(), a.end());
	
	f();
	
	cout << seg.query(1, n);
	
	return 0;
}
