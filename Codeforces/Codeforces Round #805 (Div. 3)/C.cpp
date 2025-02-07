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

int n, m, st[202020], en[202020];
vt<int> a, cc;

void init() {
    n = m = 0;
    FOR(sz(cc)) st[i] = en[i] = -1;
    a.clear();
    cc.clear();
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

    memset(st, -1, sizeof(st));
    memset(en, -1, sizeof(en));

	int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        a.resize(n);
        EACH(i, a) cin >> i;

        cc = a;
        sort(all(cc));
        cc.erase(unique(all(cc)), cc.end());

        FOR(n) {
            a[i] = lower_bound(all(cc), a[i]) - cc.begin();
            if (st[a[i]] == -1) st[a[i]] = i;
            en[a[i]] = i;
        }

        FOR(m) {
            int u, v;
            cin >> u >> v;
            
            int uidx = lower_bound(all(cc), u) - cc.begin();
            int vidx = lower_bound(all(cc), v) - cc.begin();

            if (uidx == sz(cc) || cc[uidx] != u || vidx == sz(cc) || cc[vidx] != v) {
                cout << "NO\n";
            }
            else if (st[uidx] > en[vidx]) {
                cout << "NO\n";
            }
            else cout << "YES\n";
        }

        init();
    }

	return 0;
}