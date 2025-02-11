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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

//
const int MAX = 1e4;

bool isPrime[MAX + 1];
vector<int> prime(1, 2);

void getPrime() {
	fill(isPrime + 2, isPrime + MAX + 1, 1);

	for (ll i = 4; i <= MAX; i += 2)
		isPrime[i] = 0;
	for (ll i = 3; i <= MAX; i++) {
		if (isPrime[i]) prime.push_back(i);
		for (ll j = i * i; j <= MAX; j += i * 2)
			isPrime[j] = 0;
	}
}

//
struct yx {
	int y, x;
};

struct dv {
	int d, v;
};

bool operator<(dv a, dv b) {
	return a.d > b.d;
}

int n;
vt<yx> a(2);
vt<dv> adj[4040];
vt<int> dist(4040, INF);

void input() {
	cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;

	cin >> n;
	a.resize(n + 2);
	FOR(i, 2, n + 2) cin >> a[i].x >> a[i].y;
}

int calD(yx a, yx b) {
	return (int)sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
}

void modeling() {
	FOR(sz(a)) {
		FOR(j, sz(a)) {
			int d = calD(a[i], a[j]);

			if (!isPrime[d]) continue;

			adj[i].push_back({ d, j });
			adj[j].push_back({ d, i });
		}
	}
}

void dijkstra() {
	priority_queue<dv> pq;

	pq.push({ 0, 0 });
	dist[0] = 0;

	while (!pq.empty()) {
		int now = pq.top().v, d = pq.top().d;
		pq.pop();

		for (auto& e : adj[now]) {
			int next = e.v;
			if (dist[next] > d + e.d) {
				dist[next] = d + e.d;
				pq.push({ dist[next], next });
			}
		}
	}
}

void solve() {
	getPrime();

	input();

	modeling();

	dijkstra();

	if (dist[1] == INF) cout << -1;
	else cout << dist[1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
