#define _USE_MATH_DEFINES
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

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Seg {
	int flag;  // array size
	vector<ll> t;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);
	}
	void modify(int p) {  // set value at position p
		for (t[p += flag - 1]++; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
	}
}seg;

struct Query {
    ll op, a, b;
};

int n, q;
vt<Query> query;
vt<ll> arr;
set<ll> s;

void input() {
    cin >> q;
    query.resize(q);
    EACH(i, query) {
        cin >> i.op;
        if (i.op == 1) {
            cin >> i.a >> i.b;
            ll aa = i.a, bb = i.b;
            if (aa < 0) aa *= -1, bb *= -1;
            if (aa != 0) {
                if (-bb >= 0) arr.push_back(-bb / aa);
                else arr.push_back((-bb - aa + 1) / aa);
            }
        }
        if (i.op == 2) {
            cin >> i.a;
            arr.push_back(i.a);
        }
    }
}

void cc() {
    vt<ll> c;
    EACH(i, arr) c.push_back(i);
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    n = sz(c);
    seg.build(n);
    EACH(i, arr) {
        i = lower_bound(all(c), i) - c.begin() + 1;
    }
}

void solve() {
    int cur = 1, idx = 0;
    EACH(i, query) {
        if (i.op == 1) {
            if (i.a != 0) {
                cur *= (i.a > 0 ? 1 : -1);
                seg.modify(arr[idx++]);
            }
            else cur *= (i.b > 0 ? 1 : (i.b < 0 ? -1 : 0));
            if (i.a != 0 && i.b % i.a == 0) s.insert(-i.b / i.a);
        }
        if (i.op == 2) {
            if (cur == 0 || s.find(i.a) != s.end()) cout << 0 << '\n';
            else {
                if (cur > 0 && seg.query(arr[idx], n) % 2 == 0) cout << "+\n";
                else if (cur < 0 && seg.query(arr[idx], n) % 2 == 1) cout << "+\n";
                else cout << "-\n";
            }
            idx++;
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

    cc();

    solve();

	return 0;
}