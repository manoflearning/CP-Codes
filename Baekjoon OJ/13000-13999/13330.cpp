// solution 1: time complexity O(n^2)
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

int n, a, b;
vt<int> arr;
int dist[10101][10101], dp[10101];

void input() {
    cin >> n >> a >> b;
    string s1; cin >> s1;
    EACH(i, s1) arr.push_back(i - 'a');
}

int f(int idx) {
    int& ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == n) return ret = 0;

    ret = INF;
    
    if (2 * dist[idx][n - 1] * b >= (n - idx) * a) return ret = 1;

    for (int i = idx + 1; i < n - 1; i++) {
        if (2 * dist[idx][i] * b >= (i - idx + 1) * a) ret = min(ret, f(i + 1) + 1);
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

    FOR(10101) dp[i] = -1;

	input();

    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < n - 1; i++) {
        dist[i][i + 1] = (arr[i] == arr[i + 1]);
    }

    for (int len = 3; len <= n; len++) {
        for (int l = 0, r; r = l + len - 1, r < n; l++) {
            if (arr[l] == arr[r]) dist[l][r] = dist[l + 1][r - 1] + 1;
        }
    }

    cout << (f(0) < INF ? f(0) : 0);

	return 0;
}

// solution 2: worst case time complexity O(n^3)
/*#define _USE_MATH_DEFINES
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

int n, a, b;
vt<int> arr;
int dp[10101];

void input() {
    cin >> n >> a >> b;
    string s1; cin >> s1;

    EACH(i, s1) arr.push_back(i - 'a');
}

int isP(int s, int e) {
    int len = min<ll>((e - s + 1) >> 1, (a * (e - s + 1) + (2 * b) - 1) / (2 * b));
    if (2 * len * b < (e - s + 1) * a) return 0;
    for (int i = 0; i < len; i++) {
        if (arr[i + s] != arr[e - i]) return 0;
    }
    return 1;
}

int f(int idx) {
    int& ret = dp[idx];
    if (ret != -1) return ret;
    if (idx == n) return ret = 0;

    ret = INF;
    
    if (isP(idx, n - 1)) return ret = 1;

    for (int i = idx + 1; i < n - 1; i++) {
        if (isP(idx, i)) ret = min(ret, f(i + 1) + 1);
    }
    //cout << idx << ' ' << ret << '\n';
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

    memset(dp, -1, sizeof(dp));

	input();

    cout << (f(0) < INF ? f(0) : 0);

	return 0;
}*/