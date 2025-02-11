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

vt<int> p(101010, -1);
vt<ll> w(101010);

int find(int x) {
    if (p[x] < 0) return x;
    int res = find(p[x]);
    w[x] += w[p[x]];
    return p[x] = res;
}

void merge(int u, int v, ll c) {
    int U = find(u), V = find(v);
    if (U == V) return;
    p[U] += p[V];
    p[V] = U;
    w[V] += c + w[u] - w[v];
}

int n, k;

void init() {
    FOR(101010) w[i] = 0, p[i] = -1;
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	//freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
    FOR(tt, 1, tc + 1) {
        cout << "Case #" << tt << '\n';

        init();

        cin >> n >> k;
        FOR(k) {
            int op, x, y; 
            cin >> op >> x >> y;
            if (op == 1) {
                ll z; cin >> z;
                if (find(x) == find(y)) {
                    if (-w[x] + w[y] != z) {
                        p[find(x)] = -INF;
                    }
                }
                else merge(x, y, z);
            }
            else {
                if (find(x) == find(y)) {
                    if (p[find(x)] <= -INF) cout << "CF\n";
                    else cout << -w[x] + w[y] << '\n';
                }
                else cout << "NC\n";
            }
        }
    }

	return 0;
}