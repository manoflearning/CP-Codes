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
    FOR(tt, 1, tc + 1) {
        string t; cin >> t;

        int n; cin >> n;
        vt<string> a(n);
        EACH(i, a) cin >> i;

        vt<int> len(sz(t), -INF), num(sz(t));

        for (int now = 0; now < sz(t); now++) {
            for (int i = 0; i < sz(a); i++) {
                const string& s = a[i];
                
                int bit = 1;
                for (int j = 0; j < sz(s); j++) {
                    if (now + j >= sz(t) || s[j] != t[now + j]) {
                        bit = 0; break;
                    }
                }

                if (bit && len[now] < now + sz(s) - 1) {
                    len[now] = now + sz(s) - 1;
                    num[now] = i;
                }
            }
        }   

        vt<pii> ans;
        int now = 0, prv = 0;
        int mxLen = -1, idx = -1, mxprv = -1;
        for (int i = 0; ; i++) {
            while (prv <= now) {
                if (len[prv] > mxLen) {
                    mxLen = len[prv];
                    idx = num[prv];
                    mxprv = prv;
                }
                prv++;
            }

            if (mxLen < now) break;

            ans.push_back({ idx, mxprv });
            now = mxLen + 1;

            if (now == sz(t)) break;
        }
        
        if (now == sz(t)) {
            cout << sz(ans) << '\n';
            EACH(i, ans) {
                cout << i.fr + 1 << ' ' << i.sc + 1 << '\n';
            }
        }
        else cout << -1 << '\n';
    }

	return 0;
}