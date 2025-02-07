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
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

struct xy {
    int x, y;
	bool operator<(const xy& rhs) const {
		if (x ^ rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
};

int r, c, k;
vt<vt<int>> a;
int wCnt;
set<pair<xy, xy>> s;
vt<xy> co[6];

void input() {
	cin >> r >> c >> k;
	a.resize(r + 1, vt<int>(c + 1));
	FOR(x, 1, r + 1) {
		FOR(y, 1, c + 1) {
			int val; cin >> val;
			if (val > 0) {
				co[val].push_back({ x, y });
			}
		}
	}

	cin >> wCnt;
	FOR(wCnt) {
		int x, y, bit;
		cin >> x >> y >> bit;
		if (!bit) {
			s.insert({{ x, y }, { x - 1, y }});
			s.insert({{ x - 1, y }, { x, y }});
		}
		else {
			s.insert({{ x, y }, { x, y + 1 }});
			s.insert({{ x, y + 1 }, { x, y }});
		}
	}
}

bool isWall(int x, int y, int nx, int ny, int i) {
	if (abs(x - nx) == 1 && abs(y - ny) == 1) {
		//if (s.find({{ x, y }, { x + dx[i], y + dy[i] }}) != s.end()) return 1;
		//if (s.find({{ x + dx[i], y + dy[i] }, { nx, ny }}) != s.end()) return 1;

		if (i <= 2) {
			if (s.find({{ x, y }, { nx, y }}) != s.end()) return 1;
			if (s.find({{ nx, y }, { nx, ny }}) != s.end()) return 1;
		}
		if (i >= 3) {
			if (s.find({{ x, y }, { x, ny }}) != s.end()) return 1;
			if (s.find({{ x, ny }, { nx, ny }}) != s.end()) return 1;
		}	
	}
	else {
		if (s.find({{ x, y }, { nx, ny }}) != s.end()) return 1;
	}
	return 0;
}

void windwind(int num, const vt<int>& nxt) {
	EACH(i, co[num]) {
		vt<vt<int>> vi(r + 1, vt<int>(c + 1));

		queue<pair<xy, int>> q;
		q.push({ { i.x + dx[nxt[0]], i.y + dy[nxt[0]] }, 5 });
		vi[i.x + dx[nxt[0]]][i.y + dy[nxt[0]]] = 1;

		while (sz(q)) {
			int x = q.front().fr.x, y = q.front().fr.y;
			int w = q.front().sc;
			q.pop();
			//cout << x << ' ' << y << '\n';
			a[x][y] += w;

			if (w == 1) continue;

			EACH(j, nxt) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 1 || r < nx || ny < 1 || c < ny) continue;
				if (vi[nx][ny]) continue;
				if (isWall(x, y, nx, ny, num)) continue;

				vi[nx][ny] = 1;
				q.push({ { nx, ny }, w - 1 });
			}
		}
	}
}

//const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
//const int dx[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

void wind() {
	vt<int> nxt = { 1, 4, 5 };
	windwind(1, nxt);
	nxt = { 3, 6, 7 };
	windwind(2, nxt);
	nxt = { 2, 5, 7 };
	windwind(3, nxt);
	nxt = { 0, 4, 6 };
	windwind(4, nxt);
}

void jojul() {
	vt<vt<int>> b = a;
	FOR(x, 1, r + 1) {
		FOR(y, 1, c + 1) {
			FOR(i, 2) {
				int nx = x + dx[i], ny = y + dy[i];
				if (r < nx || c < ny) continue;
				if (isWall(x, y, nx, ny, 0)) continue;

				int diff = abs(a[x][y] - a[nx][ny]) / 4;

				if (a[x][y] > a[nx][ny]) {
					b[x][y] -= diff;
					b[nx][ny] += diff;
				}
				else {
					b[x][y] += diff;
					b[nx][ny] -= diff;
				}
			}
		}
	}
	a = b;
}

void minus1() {
	FOR(y, 1, c + 1) {
		if (a[1][y] > 0) a[1][y]--;
		if (a[r][y] > 0) a[r][y]--;
	}
	FOR(x, 2, r) {
		if (a[x][1] > 0) a[x][1]--;
		if (a[x][c] > 0) a[x][c]--;
	}
}

bool isDone() {
	EACH(i, co[5]) {
		if (a[i.x][i.y] < k) return 0;
	}
	return 1;
}

void print() {
	FOR(x, 1, r + 1) {
		FOR(y, 1, c + 1) {
			cout << a[x][y] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();

	int ans = -1;
	for (ans = 1; ans <= 100; ans++) {
		wind();

		jojul();

		minus1();
		
		//if (ans == 100) print();

		if (isDone()) break;
	}

	cout << ans;

	return 0;
}