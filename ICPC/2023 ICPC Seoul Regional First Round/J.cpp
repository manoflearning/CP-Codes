#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a).size()

const int MAXN = 1010;
const int MAXK = 5050;

int n, k;
ll a[MAXN][MAXN];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

ll dp[MAXN][MAXN / 3 + 5];
ll dp2[MAXK];

// int flag;
// struct Seg {
//     vector<ll> t;
//     void build(int n) {
//         for (flag = 1; flag < n; flag <<= 1);
//         t.resize(flag << 1);
//     }
//     void modify(int p, ll val) {
//         t[p + flag - 1] = max(t[p + flag - 1], val);
//         for (p += flag - 1; p > 1; p >>= 1) {
//             t[p >> 1] = max(t[p], t[p ^ 1]);
//         }
//     }
//     ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {
//         if (nr < l || r < nl) return 0;
//         if (l <= nl && nr <= r) return t[n];
//         int mid = (nl + nr) >> 1;
//         return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
//     }
// }seg;

void bottomup() {
    // first dp
    for (int r = 1; r <= n; r++) {
        vector<ll> lazy1(n / 3 + 5);
        vector<ll> lazy2(n / 3 + 5);
        vector<ll> dpRow(n / 3 + 5);

        for (int c = 3; c <= n; c++) {
            int ub = c / 3;
            ll sum = a[r][c - 2] + a[r][c - 1] + a[r][c];
            for (int k = 1; k <= ub; k++) {
                dpRow[k] = sum + dp[r][k - 1];
            }

            for (int i = 1; i < sz(lazy1); i++) {
                if (lazy1[i] == 0) break;
                dp[r][i] = max(dp[r][i], lazy1[i]);
            }
            lazy1 = lazy2;
            lazy2 = dpRow;
        }

        for (int i = 1; i < sz(lazy1); i++) {
            if (lazy1[i] == 0) break;
            dp[r][i] = max(dp[r][i], lazy1[i]);
        }
        for (int i = 1; i < sz(lazy2); i++) {
            if (lazy2[i] == 0) break;
            dp[r][i] = max(dp[r][i], lazy2[i]);
        }
        for (int i = 1; i < sz(dpRow); i++) {
            if (dpRow[i] == 0) break;
            dp[r][i] = max(dp[r][i], dpRow[i]);
        }
    }

    // for (int r = 1; r <= n; r++) {
    //     for (int k = 1; k <= n / 3 + 5; k++) {
    //         cout << dp[r][k] << ' ';
    //     }
    //     cout << '\n';
    // }

    // second dp
    for (int r = 1; r <= n; r++) {
        vector<ll> tmp(MAXK);
        for (int i = 1; i < MAXN / 3 + 5; i++) {
            if (dp[r][i] == 0) break;
            for (int j = 0; j + i < MAXK; j++) {
                tmp[j + i] = max(tmp[j + i], dp[r][i] + dp2[j]);
            }
        }
        for (int i = 0; i < MAXK; i++) {
            dp2[i] = max(dp2[i], tmp[i]);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    bottomup();

    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp2[i]);
    }
    cout << ans;
}