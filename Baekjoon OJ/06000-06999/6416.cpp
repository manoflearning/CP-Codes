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

vt<pii> a;
vt<int> cc, ind, vi;
int End = 0;

void init() {
    a.clear();
    cc.clear();
    ind.clear();
    vi.clear();
}

void input() {
    while (1) {
        int u, v;
        cin >> u >> v;
        
        if (u == -1) End = 1;
        if (u <= 0) break;

        a.push_back({ u, v });
        cc.push_back(u);
        cc.push_back(v);
    }
}

void com() {
    sort(all(cc));
    cc.erase(unique(all(cc)), cc.end());

    EACH(i, a) {
        i.fr = lower_bound(all(cc), i.fr) - cc.begin() + 1;
        i.sc = lower_bound(all(cc), i.sc) - cc.begin() + 1;
    }
    
    ind.resize(sz(cc) + 1);
    vi.resize(sz(cc) + 1);
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

	for (int tt = 1; ; tt++) {
        input();

        if (End) break;

        cout << "Case " << tt << " is ";

        com();

        EACH(i, a) ind[i.sc]++;

        if (a.empty()) {
            cout << "a tree.\n";
        }
        else {
            int cnt = 0, ans = 1;
            FOR(i, 1, sz(cc) + 1) {
                if (!ind[i]) cnt++;
                if (ind[i] >= 2) ans = 0;
            }

            if (cnt == 1 && ans) cout << "a tree.\n";
            else cout << "not a tree.\n";
        }

        init();
    }

	return 0;
}