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
const int dy[] = { 0, 1, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, 0, 0, 0, 1, -1, 1, -1 };

int n, m;
int a[1010][1010], dpmx[1010][1010], dpmn[1010][1010];

void init() {
    FOR(n) {
        FOR(j, m) {
            a[i][j] = 0;
            dpmx[i][j] = dpmn[i][j] = -1;
        }
    }
    n = m = 0;
}

int fmx(int y, int x) {
    int& ret = dpmx[y][x];
    if (ret != -1) return ret;
    if (y == n - 1 && x == m - 1) return ret = a[y][x];

    ret = 0;
    FOR(2) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny >= n || nx >= m) continue;
        ret = max(ret, fmx(ny, nx) + a[y][x]);
    }

    return ret;
}

int fmn(int y, int x) {
    int& ret = dpmn[y][x];
    if (ret != -1) return ret;
    if (y == n - 1 && x == m - 1) return ret = a[y][x];

    ret = INF;
    FOR(2) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny >= n || nx >= m) continue;
        ret = min(ret, fmn(ny, nx) + a[y][x]);
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

    FOR(1010) {
        FOR(j, 1010) {
            dpmx[i][j] = dpmn[i][j] = -1;
        }
    }

	int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        FOR(n) {
            FOR(j, m) {
                cin >> a[i][j];
                if (a[i][j] == -1) a[i][j] = 0;
            }
        }

        if ((n + m - 1) & 1) {
            cout << "NO\n";
            continue;
        }

        int cnt = (n + m - 1) / 2;
        if (fmn(0, 0) <= cnt && cnt <= fmx(0, 0)) {
            cout << "YES\n";
        }
        else cout << "NO\n";

        init();
    }

	return 0;
}