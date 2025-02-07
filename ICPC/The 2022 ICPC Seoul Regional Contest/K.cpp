#include <bits/stdc++.h>
using namespace std;

int n, p, q;
vector<string> a, b, c;
int dp[505][505][505];

int f(int x1, int x2, int x3) {
    auto& ret = dp[x1][x2][x3];
    if (ret != -1) return ret;
    if (x1 == n) return ret = 0;

    ret = 0;
    if (x2 < p && a[x1] == b[x2]) {
        ret = max(ret, f(x1 + 1, x2 + 1, x3) + 1);
    }
    if (x3 < q && a[x1] == c[x3]) {
        ret = max(ret, f(x1 + 1, x2, x3 + 1) + 1);
    }
    ret = max(ret, f(x1 + 1, x2, x3));
    if (x2 < p) ret = max(ret, f(x1, x2 + 1, x3));
    if (x3 < q) ret = max(ret, f(x1, x2, x3 + 1));

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    for (int i = 0; i < 505; i++) {
        for (int j = 0; j < 505; j++) {
            for (int k = 0; k < 505; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

	cin >> n >> p >> q;
    a.resize(n);
    for (auto& i : a) cin >> i;
    b.resize(p);
    for (auto& i : b) cin >> i;
    c.resize(q);
    for (auto& i : c) cin >> i;

    cout << f(0, 0, 0);

	return 0;
}