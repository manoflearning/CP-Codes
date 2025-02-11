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
        int n; cin >> n;

        int d12, d23, d31;
        cin >> d12 >> d23 >> d31;

        if (d23 + d31 < d12) {
            cout << "NO\n";
            continue;
        }
        if (d23 + d31 == d12) {
            cout << "YES\n";

            vt<int> arr(d12 + 2);
            arr[1] = 1, arr[d12 + 1] = 2;
            arr[d31 + 1] = 3;

            int mxv = n;
            FOR(i, 1, d12 + 2)
                if (!arr[i]) arr[i] = mxv--;

            FOR(i, 1, d12 + 1)
                cout << arr[i] << ' ' << arr[i + 1] << '\n';
            
            FOR(i, 4, mxv + 1)
                cout << 1 << ' ' << i << '\n';

            continue;
        }

        int mxv = n;
        vt<pii> ans;
        if (d12 == 1) ans.push_back({ 1, 2 });
        else {
            FOR(d12) {
                if (i == 0) {
                    ans.push_back({ 1, mxv });
                }
                else if (i == d12 - 1) {
                    ans.push_back({ mxv--, 2 });
                }
                else {
                    ans.push_back({ mxv--, mxv });
                }
            }
        }
        
        if (abs(d23 - d31) > d12) {
            cout << "NO\n";
            continue;
        }

        int w1 = 0, w2 = d12;

        if ((abs(w1 - w2) & 1) ^ (abs(d31 - d23) & 1)) {
            cout << "NO\n";
            continue;
        }

        while (1) {
            if (w1 - w2 == d31 - d23) break;
            w1++, w2--;
        }

        int po = -1;
        if (w1 == d12) po = 2;
        else po = ans[w1].fr;

        d31 -= w1;
        if (d31 == 1) ans.push_back({ po, 3 });
        else if (d31 >= 2) {
            ans.push_back({ po, mxv });
            d31--;
            while (d31 > 1) {
                d31--;
                ans.push_back({ mxv--, mxv });
            }
            ans.push_back({ mxv--, 3 });
        }
        
        if (mxv < 3) {
            cout << "NO\n";
            continue;
        }

        FOR(i, 4, mxv + 1) 
            ans.push_back({ 1, i });

        cout << "YES\n";
        EACH(i, ans) 
            cout << i.fr << ' ' << i.sc << '\n';
    }

	return 0;
}