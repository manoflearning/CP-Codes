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

vt<ll> fiN;
vt<string> T;
int n;
string P;
ll dp[111];
vector<int> pi;

vector<int> getpi(const string& P) {
	vector<int> pi(sz(P));

	int begin = 1, matched = 0;
	while (begin + matched < sz(P)) {
		if (P[begin + matched] == P[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}

ll kmp(const string& T, const string& P) {
	ll ret = 0;

	int begin = 0, matched = 0;
	while (begin <= sz(T) - sz(P)) {
		if (matched < sz(P) && T[begin + matched] == P[matched]) {
			matched++;
			if (matched == sz(P)) ret++;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
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

	fiN.push_back(1);
    T.push_back("0");
    fiN.push_back(1);
    T.push_back("1");
    while (fiN.back() <= 500000) {
        fiN.push_back(fiN[sz(fiN) - 1] + fiN[sz(fiN) - 2]);
        T.push_back(T[sz(T) - 1] + T[sz(T) - 2]);
    }
    
    for (int tc = 1; ; tc++) {
        cin >> n;
        if (cin.eof()) break;
        cin >> P;

        cout << "Case " << tc << ": ";
        if (n < sz(fiN) && fiN[n] < sz(P)) {
            cout << 0 << '\n';
            continue;
        }

        pi = getpi(P);

        int idx = lower_bound(all(fiN), sz(P)) - fiN.begin();
        
        if (idx == n) {
            cout << kmp(T[idx], P) << '\n';
            continue;
        }
        if (idx + 1 == n) {
            cout << kmp(T[idx + 1], P) << '\n';
            continue;
        }

        dp[idx] = kmp(T[idx], P);
        dp[idx + 1] = kmp(T[idx + 1], P);
        dp[idx + 2] = kmp(T[idx + 1] + T[idx], P);
        ll x = kmp(T[idx] + T[idx + 1], P) - dp[idx] - dp[idx + 1], y = kmp(T[idx + 1] + T[idx + 1], P) - 2 * dp[idx + 1];
        for (int i = idx + 3; i <= n; i++) {
            if ((i - idx) & 1) dp[i] = x + dp[i - 2] + dp[i - 1];
            else dp[i] = y + dp[i - 2] + dp[i - 1];
        }

        cout << dp[n] << '\n';
    }

	return 0;
}