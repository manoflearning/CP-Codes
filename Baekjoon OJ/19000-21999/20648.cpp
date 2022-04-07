#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
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

struct xy {
    int x, y;
};

bool operator<(const xy& a, const xy& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int n;
vt<xy> a;

void input() {
	cin >> n;
	a.resize(n);
	EACH(i, a) {
        cin >> i.x >> i.y;
    }
}

void cc() {
	vt<int> b;
	EACH(i, a) {
        b.push_back(i.x);
        b.push_back(i.y);
    }

	sort(all(b));
	b.erase(unique(all(b)), b.end());

	EACH(i, a) {
        i.x = lower_bound(all(b), i.x) - b.begin();
        i.y = lower_bound(all(b), i.y) - b.begin();
    }
}

ll f() {
	ll ret = n + 1;

    FOR(sy, 0, n) {
		FOR(ey, sy + 1, n) {
			int cnt = upper_bound(all(a), ey) - lower_bound(all(a), sy);
            
			ret += cnt * (cnt - 1) / 2;
		}
	}

	return ret;
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

    sort(all(a));

	cout << f() << '\n';

	return 0;
}