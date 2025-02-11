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
const ll INF = 1e18 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { -1, 0, 0, 1 };
const int dx[] = { 0, 1, -1, 0 };

int n, p, m, sty, stx;
vt<pll> dirCost(4);
ll dist[11][11][22];

void init() {
    FOR(11) {
        FOR(j, 11) {
            FOR(k, 22) {
                dist[i][j][k] = -INF;
            }
        }
    }
}

void input() {
    cin >> n >> p >> m >> sty >> stx;

    FOR(4) {
        char c; int w;
        cin >> c >> w;
        if (c == '+') dirCost[i].fr = 0;
        if (c == '-') dirCost[i].fr = 1;
        if (c == '*') dirCost[i].fr = 2;
        if (c == '/') dirCost[i].fr = 3;
        dirCost[i].sc = w;
    }
}

ll cal(ll c, ll dir) {
    auto it = dirCost[dir];
    if (it.fr == 0) return c + it.sc;
    if (it.fr == 1) return c - it.sc;
    if (it.fr == 2) return c * it.sc;
    if (it.fr == 3) {
        if (c >= 0) return c / it.sc;
        else {
            if (c % it.sc) return c / it.sc - 1;
            else return c / it.sc;
        }
    }
    return 0;
}

ll dijkstra() {
    struct wv {
        ll w; int y, x, t;
        bool operator<(const wv& rhs) const {
            return w < rhs.w;
        }
    };

    priority_queue<wv> pq;

    pq.push({ 0, sty, stx, m });
    dist[sty][stx][m] = 0;

    ll ret = 0;
    while (sz(pq)) {
        int y = pq.top().y, x = pq.top().x, t = pq.top().t;
        ll w = pq.top().w;
        pq.pop();
        
        if (t == 0) {
            ret = max(ret, w);
            //cout << y << ' ' << x << ' ' << t << ' ' << w << '\n';
            continue;
        }
        if (w < dist[y][x][t]) continue;
        //cout << y << ' ' << x << ' ' << t << ' ' << w << '\n';
        FOR(4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || n < ny || nx < 1 || n < nx) continue;
            ll nw = cal(w, i);
            if (dist[ny][nx][t - 1] >= nw) continue;
            dist[ny][nx][t - 1] = nw;
            /*if (ny == 2 && nx == 2 && t - 1 == 1 && nw == 10) {
                cout << y << ' ' << x << ' ' << t << ' ' << w << '\n';
            }
            if (nw == 20) {
                cout << y << ' ' << x << ' ' << t << ' ' << w << '\n';
            }*/
            pq.push({ nw, ny, nx, t - 1 });
        }

        if (dist[y][x][t - 1] < w) {
            dist[y][x][t - 1] = w;
            pq.push({ w, y, x, t - 1 });
        }
    }

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    
	int tc; cin >> tc;
	FOR(tt, 1, tc + 1) {
        cout << "Case #" << tt << ": ";

        init();

		input();

        cout << dijkstra() << '\n';
	}

	return 0;
}