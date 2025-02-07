#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

int n;
ll a[404][808], psum[404][808];

void init() {
    for (int i = 0; i < 404; i++) {
        for (int j = 0; j < 808; j++) {
            a[i][j] = psum[i][j] = 0;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int tt = 1; ; tt++) {
        init();

        cin >> n;
        if (n == 0) break;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * i - 1; j++) {
                cin >> a[i][j];
                psum[i][j] = a[i][j] + psum[i][j - 1];
            }
        }

        ll ans = -INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * i - 1; j += 2) {
                ll sum = 0;
                for (int k = i; k <= n; k++) {
                    int len = 2 * (k - i + 1) - 1;
                    sum += psum[k][j + len - 1] - psum[k][j - 1];
                    ans = max(ans, sum);
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= 2 * i - 1; j += 2) {
                ll sum = 0;
                for (int k = i; k >= 1; k--) {
                    int len = 2 * (i - k + 1) - 1;
                    if (j - len < 0) break;
                    if (j > 2 * k - 1) break;
                    sum += psum[k][j] - psum[k][j - len];
                    ans = max(ans, sum);
                }
            }
        }
        
        cout << tt << ". ";
        cout << ans << '\n';
    }

    return 0;
}