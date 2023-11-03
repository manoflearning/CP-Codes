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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == ans + 1) ans++;
        else if (x < ans + 1) ans = x;
    }

    cout << ans;
}