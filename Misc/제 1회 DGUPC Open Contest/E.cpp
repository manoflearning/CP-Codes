// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

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
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const int MAXN = 4040404;
ll fac[MAXN], inv[MAXN], facInv[MAXN];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, d, p;
    cin >> n >> d >> p;

    // Preprocessing in O(N)
	fac[0] = fac[1] = inv[1] = 1;
	facInv[0] = facInv[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		fac[i] = i * fac[i - 1] % MOD;
		inv[i] = -(MOD / i) * inv[MOD % i] % MOD;
		if (inv[i] < 0) inv[i] += MOD;
		facInv[i] = facInv[i - 1] * inv[i] % MOD;
	}

    ll ans = 1;

    vector<int> prv(d, 1);
    for (int i = 0; i <= p; i++) {
        vector<int> now(d, n);
        if (i < p) for (auto& j : now) cin >> j;

        ll sum = 0;
        vector<int> each;
        for (int j = 0; j < d; j++) {
            sum += now[j] - prv[j];
            each.push_back(now[j] - prv[j]);
        }

        prv = now;

        ans = (ans * fac[sum]) % MOD;
        for (auto& j : each) ans = (ans * facInv[j]) % MOD;
    }

    cout << ans;
}