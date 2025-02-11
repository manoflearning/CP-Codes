//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, a[101][101];
int co[101][101], cnt;

void dfs(int y, int x) {
    co[y][x] = cnt;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 1 || n < ny || nx < 1 || n < nx) continue;
        if (a[ny][nx] == 0) continue;
        if (co[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int ans = INF;
vector<vector<int>> dist(101, vector<int>(101, -1));
int bfs(int sty, int stx) {
    vector<pii> res;
    queue<pii> q;
    q.push({ sty, stx });
    res.push_back({ sty, stx });
    dist[sty][stx] = 0;

    int ret = INF;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        if (ans < dist[y][x]) break;

        if (co[y][x] && !(y == sty && x == stx)) {
            ret = dist[y][x] - 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 1 || n < ny || nx < 1 || n < nx) continue;
            if (co[ny][nx] == co[sty][stx]) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny, nx });
            res.push_back({ ny, nx });
        }
    }

    for (auto& i : res)
        dist[i.fr][i.sc] = -1;

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] && !co[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            if (!a[y][x]) continue;
            
            int bit = 0;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 1 || n < ny || nx < 1 || n < nx) continue;
                if (a[ny][nx] == 0) { bit = 1; break; }
            }

            if (bit) ans = min(ans, bfs(y, x));
        }
    }
    
    cout << ans;

	return 0;
}