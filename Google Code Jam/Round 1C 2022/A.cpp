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

    FOR(t, tc) {
        int n; cin >> n;
        vt<string> a(n);
        EACH(i, a) cin >> i;

        string ans;
        vt<int> st[26], en[26], same[26], visited(n);

        FOR(n) {
            int isS = 1;
            FOR(j, sz(a[i]) - 1) {
                if (a[i][j] != a[i][j + 1]) isS = 0;
            }

            if (isS) same[a[i][0] - 'A'].push_back(i);
            
            if (!isS) st[a[i][0] - 'A'].push_back(i);
            if (!isS) en[a[i].back() - 'A'].push_back(i);
        }

        int idx = -1;

        FOR(k, n << 1) {
            if (idx == -1) {
                FOR(26) {
                    int isSt = 0, isSame = 0, isEn = 0;
                    EACH(j, st[i])
                        if (!visited[j]) isSt = 1;
                    EACH(j, same[i])
                        if (!visited[j]) isSame = 1;
                    EACH(j, en[i])
                        if (!visited[j]) isEn = 1;

                    //cout << (char)(i + 'A') << ' ' << isSt << ' ' << isSame << ' ' << isEn << '\n';
                    if ((isSt || isSame) && !isEn) {
                        idx = i;
                        break;
                    }
                }
            }
            //assert(idx != -1);

            if (idx == -1) break;

            int bit = 0;

            EACH(i, same[idx]) {
                if (visited[i]) continue;
                EACH(j, a[i]) 
                    ans.push_back(j);
                visited[i] = 1;
            }
            
            EACH(i, st[idx]) {
                if (visited[i]) continue;
                EACH(j, a[i])
                    ans.push_back(j);
                visited[i] = bit = 1;
                idx = a[i].back() - 'A';
                break;
            }  

            if (!bit) idx = -1;
        }
        
        int imp = 0;
        FOR(n) {
            if (!visited[i]) imp = 1;
        }

        vt<int> cnt(26);
        FOR(sz(ans)) {
            if (i > 0 && ans[i - 1] != ans[i] && cnt[ans[i] - 'A']) imp = 1;
            cnt[ans[i] - 'A']++;
        }

        cout << "Case #" << t + 1 << ": ";
        if (imp) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }

	return 0;
}