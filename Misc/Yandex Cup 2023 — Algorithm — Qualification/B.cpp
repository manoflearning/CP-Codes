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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto& i : a) cin >> i;

    auto b = a;
    sort(all(b));

    ll ub = b[m - 1];

    int l = INF, r = -INF, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < ub) {
            l = min(l, i);
            r = max(r, i);
            cnt++;
        }
    }

    vector<int> cand;
    for (int i = 0; i < n; i++) {
        if (a[i] != ub) continue;
        if (l <= i && i <= r) cnt++;
        else cand.push_back(i);
    }

    int left = m - cnt;
    if (left <= 0) {
        cout << r - l + 1;
        return 0;
    }

    int ans = INF;
    for (int i = 0; i + left - 1 < sz(cand); i++) {
        int s = min(l, cand[i]);
        int e = max(r, cand[i + left - 1]);
        ans = min(ans, e - s + 1);
    }

    cout << ans;
}