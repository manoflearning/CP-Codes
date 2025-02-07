#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

vector<int> uf(2020 * 2020 + 2020, -1);
int find(int x) {
	if (uf[x] < 0) return x;
	return uf[x] = find(uf[x]);
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	uf[A] += uf[B];
	uf[B] = A;
}

int n, m;
int a[2020][2020], dist[2020][2020];
vector<int> adj[2020 * 2020 + 2020];

void bfs() {
    queue<pii> q;
    q.push({ 1, 1 });
    dist[1][1] = 0;

    while (!q.empty()) {
        int y = q.front().fr, x = q.front().sc;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (a[ny][nx]) continue;
            if (dist[ny][nx] != -1) continue;
            q.push({ ny, nx });
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
}

int dfsn[2020 * 2020 + 2020], dCnt;
stack<pii> stk;
vector<vector<pii>> bcc;

int dfs(int now, int prv) {
	int ret = dfsn[now] = ++dCnt;
	for (int next : adj[now]) {
		if (next == prv) continue;
		// If an edge { now, next } has not yet been visited, it puts an edge on the stack.
		if (dfsn[now] > dfsn[next]) stk.push({ now, next });
		// Back edge
		if (dfsn[next] != -1) ret = min(ret, dfsn[next]);
		// Tree edge
		else {
			int tmp = dfs(next, now);
			ret = min(ret, tmp);
			// if next cannot go to ancestor node of now, find BCC
			if (tmp >= dfsn[now]) {
				vector<pair<int, int>> nowBCC;
				while (true) {
					pair<int, int> t = stk.top();
					stk.pop();
					nowBCC.push_back(t);
					if (t == pair<int, int>(now, next)) break;
				}
				bcc.push_back(nowBCC);
			}
		}
	}
	return ret;
}
void getBCC() {
	memset(dfsn, -1, sizeof(dfsn));

    dfs(1 * 2020 + 1, 0);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    for (int i = 0; i < 2020; i++) {
        for (int j = 0; j < 2020; j++) {
            a[i][j] = 1;
            dist[i][j] = -1;
        }
    }

	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    bfs();

    if (dist[n][m] == -1) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int y = i + dy[k], x = j + dx[k];
                if (a[y][x]) continue;
                adj[i * 2020 + j].push_back(y * 2020 + x);
            }
        }
    }

    getBCC();
    
    for (auto& i : bcc) {
        int b1 = 0, b2 = 0;
        for (auto& j : i) {
            if (j.fr == 1 * 2020 + 1 || j.sc == 1 * 2020 + 1) b1 = 1;
            if (j.fr == n * 2020 + m || j.sc == n * 2020 + m) b2 = 1;
        }
        if (b1 ^ b2) {
            cout << 1;
            return 0;
        }
    }
    
    cout << 2;

	return 0;
}