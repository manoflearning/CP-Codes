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

int h, w, o, p, sx, sy, ex, ey;
int ob[101][101], dist[101][101];

void init() {
    FOR(101) {
        FOR(j, 101) {
            ob[i][j] = 0;
            dist[i][j] = -1;
        }
    }
}

void input() {
    cin >> h >> w >> o >> p >> sx >> sy >> ex >> ey;
    FOR(o) {
        int x, y;
        cin >> x >> y;
        cin >> ob[y][x];
    }
}

int bfs() {
    queue<pii> q;
    q.push({ sy, sx });
    dist[sy][sx] = 0;

    while (sz(q)) {
        pii v = q.front();
        int d = dist[v.fr][v.sc], pp = p - d;
        q.pop();
        
        if (v.fr == ey && v.sc == ex) return 1;
        if (!pp) continue;
        
        FOR(4) {
            int ny = v.fr + dy[i], nx = v.sc + dx[i];
            int hh = max(0, ob[ny][nx] - ob[v.fr][v.sc]);
            if (dist[ny][nx] != -1 || hh > pp) continue;
            if (ny < 1 || w < ny || nx < 1 || h < nx) continue;
            q.push({ ny, nx });
            dist[ny][nx] = d + 1;
        }
    }

    return 0;
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
        init();

        input();

        if (bfs()) cout << "잘했어!!\n";
        else cout << "인성 문제있어??\n";
    }

	return 0;
}