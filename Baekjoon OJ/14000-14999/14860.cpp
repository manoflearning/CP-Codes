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

const int MAX = 15151515;

int n, m;
bool isPrime[MAX];

void getPrime() {
	fill(isPrime + 2, isPrime + MAX, 1);

	for (ll i = 4; i < MAX; i += 2) isPrime[i] = 0;
	for (ll i = 3; i < MAX; i++) {
		for (ll j = i * i; j < MAX; j += i * 2) isPrime[j] = 0;
	}
}


ll p(ll x, ll y) {
    if (y == 1) return x;
    ll res = p(x, y / 2);
    return (res * res % MOD) * (y & 1 ? x : 1) % MOD; 
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
    
    getPrime();

	cin >> n >> m;

    if (n > m) swap(n, m);

    ll ans = 1;
    FOR(i, 2, n + 1) {
        if (!isPrime[i]) continue;

        for (ll j = i; j <= n; j *= i) {
            ll cnt = (n / j) * (m / j);
            ans = (ans * p(i, cnt)) % MOD;
        }
    }

    cout << ans;

	return 0;
}