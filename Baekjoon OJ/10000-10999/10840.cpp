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

vector<int> a1, a2;

void input() {
    string s; cin >> s;
    EACH(i, s) a1.push_back(i - 'a');
    cin >> s;
    EACH(i, s) a2.push_back(i - 'a');
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

	input();

    FOR(len, min(sz(a1), sz(a2)), 0, -1) {
        set<vt<int>> s;
        vt<int> cnt(26);
        FOR(i, len) cnt[a1[i]]++;
        s.insert(cnt);
        FOR(i, 1, sz(a1) - len + 1) {
            cnt[a1[i - 1]]--, cnt[a1[i + len - 1]]++;
            s.insert(cnt);
        }
        cnt.clear();
        cnt.resize(26);
        FOR(i, len) cnt[a2[i]]++;
        if (s.find(cnt) != s.end()) {
            cout << len;
            return 0;
        }
        FOR(i, 1, sz(a2) - len + 1) {
            cnt[a2[i - 1]]--, cnt[a2[i + len - 1]]++;
            if (s.find(cnt) != s.end()) {
                cout << len;
                return 0;
            }
        }
    }
    cout << 0;

	return 0;
}