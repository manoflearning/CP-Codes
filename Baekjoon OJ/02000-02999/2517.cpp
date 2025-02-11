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

int flag = 1;
struct Seg {
    vector<int> t;
    void build(int n) {
        for (; flag < n; flag <<= 1);
        t.resize(flag * 2);
    }
    void modify(int idx) {
        t[idx += flag - 1]++;
        for (; idx > 1; idx >>= 1)
            t[idx >> 1] = t[idx] + t[idx ^ 1];
    }
    int query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
        if (nr < l || r < nl) return 0;
        if (l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) >> 1;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
}seg;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    vector<int> c = a;
    sort(all(c));
    c.erase(unique(all(c)), c.end());

    for (auto& i : a)
        i = lower_bound(all(c), i) - c.begin() + 1;

    seg.build(n);

    for (auto& i : a) {
        cout << seg.query(i, n) + 1 << '\n';
        seg.modify(i);
    }

	return 0;
}