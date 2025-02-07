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

int N, M;
int X[202020];
ll psum[202020], base = 0;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> X[i];

    for (int i = 1; i + 1 <= M; i++) {
        int u = X[i], v = X[i + 1];
        if (u > v) swap(u, v);
        
        ll w1 = v - u, w2 = (u - 1) + (N + 1 - v);
        if (w1 <= w2) {
            base += w1;
            psum[u] += w2 - w1;
            psum[v] -= w2 - w1;
        }
        else {
            base += w2;
            psum[1] += w1 - w2;
            psum[u] -= w1 - w2;
            psum[v] += w1 - w2;
            psum[N + 1] -= w1 - w2;
        }
    }

    for (int i = 2; i <= N + 1; i++)
        psum[i] += psum[i - 1];

    ll ans = 1e18;
    for (int i = 1; i <= N; i++)
        ans = min(ans, base + psum[i]);
    cout << ans;
}