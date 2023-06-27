// dp 최적화 혹은 파라메트릭 서치?
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

int n, m;
ll a[8080], psum[8080];
ll dp[808][8080];

void f(int gr, int l, int r, int nl, int nr) {
    int mid = (l + r) >> 1, idx = -1;
    ll& res = dp[gr][mid];
    res = INF;
    for (int i = nl; i <= min(mid, nr); i++) {
        assert(i <= mid);
        ll val = dp[gr - 1][i] + (mid - i) * (psum[mid] - psum[i]);
        if (res > val) {
            res = val, idx = i;
        }
    }
    if (l < r) {
        f(gr, l, mid, nl, idx);
        f(gr, mid + 1, r, idx, nr);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // input
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // build prefix sum
    for (int i = 1; i <= n; i++) 
        psum[i] = a[i] + psum[i - 1];

    // dp (dnc opt)
    for (int i = 1; i <= n; i++)
        dp[1][i] = i * psum[i];

    for (int i = 2; i <= m; i++) {
        f(i, 0, n, 0, n);
    }

    // output
    cout << dp[m][n];
}