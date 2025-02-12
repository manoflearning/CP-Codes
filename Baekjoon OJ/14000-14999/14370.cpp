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

vt<int> cnt(26);
vt<vt<int>> num(10);
vt<string> nums = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
vt<int> ans;

void init() {
    FOR(26) cnt[i] = 0;
    ans.clear();
}

void cal(char x, int y) {
    while (cnt[x - 'A']) {
        EACH(j, num[y]) cnt[j]--;
        ans.push_back(y);
    }
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


    FOR(i, 10) {
        EACH(j, nums[i]) num[i].push_back(j - 'A');
    }

	int tc; cin >> tc;

    FOR(t, 1, tc + 1) {
        init();
        cout << "Case #" << t << ": ";
        string s; cin >> s;
        EACH(i, s) cnt[i - 'A']++;
        
        cal('Z', 0);
        cal('W', 2);
        cal('U', 4);
        cal('X', 6);
        cal('G', 8);
        cal('O', 1);
        cal('H', 3);
        cal('F', 5);
        cal('S', 7);
        cal('N', 9);
        
        sort(all(ans));
        EACH(i, ans) cout << i;
        cout << '\n';
    }

	return 0;
}