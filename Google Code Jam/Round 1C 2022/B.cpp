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

ll n, k;
vt<ll> a, b;

void init() {
    n = k = 0;
    a.clear();
    b.clear();
}

void input() {
    cin >> n >> k;
    a.resize(n);
    b.resize(k);
    EACH(i, a) cin >> i;
}

ll f(int idx, ll sum, ll x) {
    //cout << idx << ' ' << sum << ' ' << x << '\n';

    if (idx == k) return sum;

    /*ll y = sum > 0 ? sum : -sum;
    
    b[idx] = y / x;
    if (y % x > y / 2) b[idx]++;
    if (sum > 0) b[idx] *= -1;*/

    if (sum == 0) b[idx] = 0;
    else {
        if (x != 0 && sum % x == 0) b[idx] = -sum / x;
        else b[idx] = -x + 1;
    }

    return f(idx + 1, sum + x * b[idx], x + b[idx]);
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

    FOR(t, tc) {
        cout << "Case #" << t + 1 << ": ";

        init();

        input();

        ll sum = 0, x = 0;
        FOR(n) {
            x += a[i];
            FOR(j, i + 1, n) {
                sum += a[i] * a[j];
            }
        }

        ll res = f(0, sum, x);

        if (res == 0) {
            EACH(i, b) cout << i << ' ';
            cout << '\n';
        }
        else cout << "IMPOSSIBLE\n";

        /*FOR(n) {
            FOR(j, k) {
                sum += a[i] * b[j];
            }
        }

        FOR(k) {
            FOR(j, i + 1, k) {
                sum += b[i] * b[j];
            }
        }*/

        /*ll y = 0, z = 0;
        EACH(i, a) {
            y += i;
            z += i * i;
        }*/

        // (y + p)^2 = z + q
        

        /*if (sum == 0) {
            if (sum2 != 0) cout << "IMPOSSIBLE\n";
            else cout << 0 << '\n';
        }
        else if ((sum2 - sum * sum) % (2 * sum) == 0) {
            cout << (sum2 - sum * sum) / (2 * sum) << '\n';
        }
        else cout << "IMPOSSIBLE\n";*/
    }

	return 0;
}