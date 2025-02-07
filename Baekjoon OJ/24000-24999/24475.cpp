//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

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

const int MAXN = 303030;

int n;
ll m, a[MAXN], b[MAXN];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        
        int isPossible = 1;

        vector<ll> rem(n + 1, mid);
        ll cntSaved = 0;
        for (int i = 1; i <= n; i++) {
            ll mx = max(a[i], b[i]);
            ll cnt = (rem[i] + mx - 1) / mx;
            if (cnt <= m) { rem[i] = 0; cntSaved += m - cnt; }
            else rem[i] -= mx * m;
        }

        for (int i = 1; i <= n; i++) {
            if (!rem[i]) continue;
            ll cnt = (rem[i] + b[i] - 1) / b[i];
            if (cnt <= cntSaved) { rem[i] = 0; cntSaved -= cnt; }
            else { isPossible = 0; break; }
        }

        if (isPossible) l = mid;
        else r = mid - 1;
    }

    cout << l;
}