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

int n, vi[111][111];
ll dp[111][111][4][30];

ll f(int ny, int nx, int prv, int cnt) {
    ll ret = 0;
    if (cnt == n - 1) {
        if (prv != 0 && vi[ny][nx + 1]) ret++;
        if (prv != 1 && vi[ny][nx - 1]) ret++;
        if (ny % 2 != nx % 2 && prv != 2 && vi[ny + 1][nx]) ret++;
        if (ny % 2 == nx % 2 && prv != 3 && vi[ny - 1][nx]) ret++;
        return ret;
    }

    if (prv != 0 && !vi[ny][nx + 1]) {
        vi[ny][nx + 1] = 1;
        ret += f(ny, nx + 1, 1, cnt + 1);
        vi[ny][nx + 1] = 0;
    }
    if (prv != 1 && !vi[ny][nx - 1]) {
        vi[ny][nx - 1] = 1;
        ret += f(ny, nx - 1, 0, cnt + 1);
        vi[ny][nx - 1] = 0;
    }
    if (ny % 2 != nx % 2 && prv != 2 && !vi[ny + 1][nx]) {
        vi[ny + 1][nx] = 1;
        ret += f(ny + 1, nx, 3, cnt + 1);
        vi[ny + 1][nx] = 0;
    }
    if (ny % 2 == nx % 2 && prv != 3 && !vi[ny - 1][nx]) {
        vi[ny - 1][nx] = 1;
        ret += f(ny - 1, nx, 2, cnt + 1);
        vi[ny - 1][nx] = 0;
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

    //FOR(111) FOR(j, 111) FOR(k, 4) FOR(a, 30) dp[i][j][k][a] = -1;

    cin >> n;

    vi[50][50] = vi[50][49] = 1;
    cout << f(50, 49, 0, 0);

	return 0;
}