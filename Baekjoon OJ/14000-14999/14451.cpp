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
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

struct yx {
    int y0, x0, dir0;
    int y1, x1, dir1;
};

int n;
vt<vt<char>> a;
int dist[20 * 20][4][20 * 20][4];

void init() {
    FOR(400) {
        FOR(j, 4) {
            FOR(k, 400) {
                FOR(p, 4) dist[i][j][k][p] = -1;
            }
        }
    }
}

void input() {
    cin >> n;
    a.resize(n, vt<char>(n));
    FOR(n) {
        FOR(j, n) {
            cin >> a[i][j];
        }
    }
}

int inv(int y, int x) {
    return y * 20 + x;
}

void bfs() {
    queue<yx> q;

    q.push({ n - 1, 0, 1, n - 1, 0, 2 });
    dist[inv(n - 1, 0)][1][inv(n - 1, 0)][2] = 0;

    while (sz(q)) {
        int y0 = q.front().y0, x0 = q.front().x0, dir0 = q.front().dir0;
        int y1 = q.front().y1, x1 = q.front().x1, dir1 = q.front().dir1;
        int d = dist[inv(y0, x0)][dir0][inv(y1, x1)][dir1];
        q.pop();
        
        // 전진
        int ny0 = y0 + dy[dir0], nx0 = x0 + dx[dir0];
        if (ny0 < 0) ny0 = 0;
        if (nx0 < 0) nx0 = 0;
        if (n <= ny0) ny0 = n - 1;
        if (n <= nx0) nx0 = n - 1;
        if (a[ny0][nx0] == 'H') ny0 = y0, nx0 = x0;
        if (y0 == 0 && x0 == n - 1) ny0 = 0, nx0 = n - 1;

        int ny1 = y1 + dy[dir1], nx1 = x1 + dx[dir1];
        if (ny1 < 0) ny1 = 0;
        if (nx1 < 0) nx1 = 0;
        if (n <= ny1) ny1 = n - 1;
        if (n <= nx1) nx1 = n - 1;
        if (a[ny1][nx1] == 'H') ny1 = y1, nx1 = x1;
        if (y1 == 0 && x1 == n - 1) ny1 = 0, nx1 = n - 1;

        if (dist[inv(ny0, nx0)][dir0][inv(ny1, nx1)][dir1] == -1) {
            dist[inv(ny0, nx0)][dir0][inv(ny1, nx1)][dir1] = d + 1;
            q.push({ ny0, nx0, dir0, ny1, nx1, dir1 });
        }

        // 좌회전
        int ndir0 = (dir0 - 1 + 4) % 4, ndir1 = (dir1 - 1 + 4) % 4;

        if (dist[inv(y0, x0)][ndir0][inv(y1, x1)][ndir1] == -1) {
            dist[inv(y0, x0)][ndir0][inv(y1, x1)][ndir1] = d + 1;
            q.push({ y0, x0, ndir0, y1, x1, ndir1 });
        }

        // 우회전
        ndir0 = (dir0 + 1) % 4, ndir1 = (dir1 + 1) % 4;

        if (dist[inv(y0, x0)][ndir0][inv(y1, x1)][ndir1] == -1) {
            dist[inv(y0, x0)][ndir0][inv(y1, x1)][ndir1] = d + 1;
            q.push({ y0, x0, ndir0, y1, x1, ndir1 });
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
    
    init();

    input();

    bfs();

    int ans = INF;
    FOR(4) {
        ans = min(ans, dist[inv(0, n - 1)][i][inv(0, n - 1)][(i + 1) % 4]);
    }
    
    cout << ans;

	return 0;
}