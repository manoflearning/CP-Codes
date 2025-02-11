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

int n, m, k;
map<int, int> mp;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
    FOR(n) {
        int key, value;
        cin >> key >> value;
        mp.insert({ key, value });
    }
    
    FOR(m) {
        int op, key, value;
        cin >> op >> key;
        if (op == 1 || op == 2) cin >> value;
        
        if (op == 1) mp.insert({ key, value });
        if (op == 2) {
            auto l = mp.lower_bound(key), r = l;
            
            if (l == mp.begin()) {
                if (abs(l->fr - key) <= k) l->sc = value;
            }
            else {
                l--;
                if (r == mp.end()) {
                    if (abs(l->fr - key) <= k) l->sc = value;
                }
                else {
                    int lw = abs(l->fr - key), rw = abs(r->fr - key);
                    if (lw > k && rw > k) continue;
                    else if (lw < rw) l->sc = value;
                    else if (lw > rw) r->sc = value;
                }
            }
        }
        if (op == 3) {
            auto l = mp.lower_bound(key), r = l;
            
            if (l == mp.begin()) {
                if (abs(l->fr - key) <= k) cout << l->sc << '\n';
                else cout << -1 << '\n';
            }
            else {
                l--;
                if (r == mp.end()) {
                    if (abs(l->fr - key) <= k) cout << l->sc << '\n';
                    else cout << -1 << '\n';
                }
                else {
                    int lw = abs(l->fr - key), rw = abs(r->fr - key);

                    if (lw > k && rw > k) cout << -1 << '\n';
                    else if (lw < rw) cout << l->sc << '\n';
                    else if (lw > rw) cout << r->sc << '\n';
                    else cout << '?' << '\n';
                }
            }
        }
    }

	return 0;
}