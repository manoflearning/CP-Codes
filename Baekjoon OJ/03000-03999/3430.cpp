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
        int n, m;
        cin >> n >> m;

        vt<int> a(m);
        vt<vt<int>> q(n + 1);

        EACH(i, a) cin >> i;

        FOR(i, m - 1, -1, -1) {
            if (a[i] == 0) continue;
            q[a[i]].push_back(i);
        }

        set<pii> s;
        FOR(i, 1, n + 1) {
            if (sz(q[i])) {
                s.insert({ q[i].back(), i });
                q[i].pop_back();
            }
        }

        int isP = 1;
        vt<int> ans;
        FOR(m) {
            int x = a[i];
            if (x == 0) {
                if (sz(s)) {
                    ans.push_back(s.begin()->sc);
                    s.erase(*s.begin());
                }
                else {
                    ans.push_back(0);
                }
            }
            else {
                if (s.find({ i, x }) != s.end()) { isP = 0; break; }

                if (sz(q[x])) {
                    s.insert({ q[x].back(), x });
                    q[x].pop_back();
                }
            }
        }

        if (isP) {
            cout << "YES\n";
            EACH(i, ans) cout << i << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }

	return 0;
}