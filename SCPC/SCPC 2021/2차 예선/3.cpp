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

int n, k, rb;
ll a[1212][1212];
int dist[1212][1212];

void init() {
    FOR(i, rb) FOR(j, rb) a[i][j] = 0;
    n = k = rb = 0;
}

ll bfs(int sy, int sx) {
    ll ret = 0;
    vt<pii> path;

    queue<pii> q;
    q.push({ sy, sx });

    dist[sy][sx] = 0;
    path.push_back({ sy, sx });

    while (sz(q)) {
        int y = q.front().fr, x = q.front().sc;
        q.pop();

        ret += (k - dist[y][x]) * a[y][x];

        if (dist[y][x] == k) break;

        FOR(4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || rb <= ny || nx < 0 || rb <= nx) continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            path.push_back({ ny, nx });
            q.push({ ny, nx });
        }
    }

    EACH(i, path) dist[i.fr][i.sc] = -1;

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

    FOR(1212) FOR(j, 1212) dist[i][j] = -1;

	int tc; cin >> tc;
    FOR(tt, 1, tc + 1) {
        cout << "Case #" << tt << '\n';

        cin >> n >> k;
        FOR(i, n) FOR(j, n) 
            cin >> a[i + k][j + k];

        rb = n + k;

        ll ans = 0;
        FOR(i, rb) FOR(j, rb) {
            ans = max(ans, bfs(i, j));
        }

        cout << ans << '\n';

        init();
    }

	return 0;
}