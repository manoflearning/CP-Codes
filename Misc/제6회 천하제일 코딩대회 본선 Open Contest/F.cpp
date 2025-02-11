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

ll n, t;
ll a[303030], b[303030];
ll c[303030], d[303030], e[303030];

void input() {
    cin >> n >> t;
    FOR(i, 1, n + 1) {
        cin >> a[i] >> b[i];
        cin >> c[i] >> d[i];
    }
    FOR(i, n + 1) cin >> e[i];
}

ll cal(ll st) {
    ll x = st + e[0];
    FOR(i, 1, n + 1) {
        x = max(x, c[i]);

        if ((x - c[i]) % a[i] + d[i] > b[i]) {
            x += a[i] - (x - c[i]) % a[i];
        }

        x += d[i];
        x += e[i];
    }

    return x;
}

int bs1() {
    int l = 0, r = t;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (cal(mid) <= t) l = mid;
        else r = mid - 1;
    }
    return l;
}

int bs2() {
    int l = 0, r = t;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (cal(mid) <= t) l = mid + 1;
        else r = mid;
    }
    return l;
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

	int tc; cin >> tc;
    while (tc--) {
        input();

        // case 1: 선린랜드까지 T 시간 이하로 갈 수 없음.
        if (cal(0) > t) {
            cout << "NO\n";
            continue;
        }
        
        int l = bs1(), r = bs2();
        //cout << l << ' ' << r << '\n';
        //cout << cal(l) << ' ' << cal(r) << '\n';
        int ans = 0;
        FOR(i, l, r + 1) {
            if (cal(i) == t) {
                ans = 1; break;
            }
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";

        /*int l = max(e[0] - c[1], 0ll), r = max(e[0] - c[1] + d[1], d[1]);
        FOR(i, 2, n + 1) {
            l += e[i - 1], r += e[i - 1];

            l -= c[i], r -= c[i];
            
            l %= a[i], r %= a[i];
            l = (l + a[i]) % a[i], r = (r + a[i]) % a[i];

            if (r > b[i]) r = b[i];
        }

        l += e[n], r += e[n];
        if (l % a[n] <= (t - c[n]) % a[n] && (t - c[n]) % a[n] <= r % a[n]) {
            cout << "YES\n";
        }
        else cout << "NO\n";*/
    }

	return 0;
}