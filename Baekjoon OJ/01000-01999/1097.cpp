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

int n, k;
vt<string> a;
int vi[8];
vt<int> p;

int isM() {
    string s;
    EACH(i, p) {
        EACH(j, a[i]) s.push_back(j);
    }

    ll x = 0, y = 0, cnt = 1, p = 1;
    EACH(i, s) {
        x *= 26;
        x += (i - 'A');
        x %= MOD;
    }

    FOR(sz(s) - 1) p *= 26, p %= MOD;
    //if (s == "ABRAABRA") cout << "ABRAABRA" << '\n';
    //if (s == "ABRAABRA") cout << x << '\n';
    y = x;
    FOR(i, 1, sz(s)) {
        x -= p * (s[i - 1] - 'A');
        x %= MOD;
        x = (x + MOD) % MOD;
        x *= 26;
        x += (s[i - 1] - 'A');
        x %= MOD; 
        if (x == y) cnt++;
        //if (s == "ABRAABRA") cout << x << '\n';
    }
    //cout << s << ' ' << cnt << '\n';
    return cnt == k;
}

int bt() {
    if (sz(p) == n) {
        return isM();
    }

    int ret = 0;
    FOR(n) {
        if (vi[i]) continue;
        vi[i] = 1;
        p.push_back(i);
        ret += bt();
        vi[i] = 0;
        p.pop_back();
    }
    return ret;
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
	
	cin >> n;
    a.resize(n);
    EACH(i, a) cin >> i;
    cin >> k;

    cout << bt();

	return 0;
}