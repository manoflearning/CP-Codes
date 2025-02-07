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

int n, a, b, c;
ll dp[12][101][101][101];
ll fac[11], p[11][4];

void init() {
    FOR(12) {
        FOR(j, 101) {
            FOR(k, 101) {
                FOR(x, 101) {
                    dp[i][j][k][x] = -1;
                }
            }
        }
    }

    fac[0] = 1;
    FOR(i, 1, 11) fac[i] = i * fac[i - 1]; 

    FOR(i, 1, 11) {
        p[i][1] = 1;
        if (i % 2 == 0) p[i][2] = fac[i] / (fac[i / 2] * fac[i / 2]);
        if (i % 3 == 0) p[i][3] = fac[i] / (fac[i / 3] * fac[i / 3] * fac[i / 3]);
    }
}

void input() {
    cin >> n >> a >> b >> c;
}

ll f(int v, int a, int b, int c) {
    ll& ret = dp[v][a][b][c];
    if (ret != -1) return ret;
    if (v == n + 1) {
        //cout << v << ' ' << a << ' ' << b << ' ' << c << '\n';
        return ret = 1;
    }

    ret = 0;

    if (v % 3 == 0) {
        int w = v / 3;
        if (a >= w && b >= w && c >= w) ret += p[v][3] * f(v + 1, a - w, b - w, c - w);
    }

    if (v % 2 == 0) {
        int w = v / 2;
        if (a >= w && b >= w) ret += p[v][2] * f(v + 1, a - w, b - w, c);
        if (a >= w && c >= w) ret += p[v][2] * f(v + 1, a - w, b, c - w);
        if (b >= w && c >= w) ret += p[v][2] * f(v + 1, a, b - w, c - w);
    }

    if (a >= v) ret += p[v][1] * f(v + 1, a - v, b, c);
    if (b >= v) ret += p[v][1] * f(v + 1, a, b - v, c);
    if (c >= v) ret += p[v][1] * f(v + 1, a, b, c - v);

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

    init();

    input();

    cout << f(1, a, b, c);

	return 0;
}