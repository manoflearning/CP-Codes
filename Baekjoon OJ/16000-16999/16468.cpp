#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 100030001;

int n, l;
ll dp[303][303];

ll f(int cnt, int h) {
    ll& ret = dp[cnt][h];
    if (ret != -1) return ret;

    ll mx = (h <= 30 ? (1 << h) - 1 : 1000);
    if (cnt > mx) return ret = 0;
    if (cnt == mx || cnt == 0 || cnt == 1) return ret = 1;

    ret = 0;
    for (int l = 0; l < cnt; l++) {
        int r = cnt - l - 1;
        ret = (ret + f(l, h - 1) * f(r, h - 1)) % MOD;
    }

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 303; i++) {
        for (int j = 0; j < 303; j++) {
            dp[i][j] = -1;
        }
    }

    cin >> n >> l;

    ll ans = f(n, l);
    if (l > 1) ans = (ans - f(n, l - 1) + MOD) % MOD;
    cout << ans;

	return 0;
}