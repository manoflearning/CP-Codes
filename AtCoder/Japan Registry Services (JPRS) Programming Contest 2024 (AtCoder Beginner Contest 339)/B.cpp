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
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, w, n;
    cin >> h >> w >> n;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        a[i].resize(w, '.');
    }

    int x = 0, y = 0, d = 0;
    while (n--) {
        if (a[y][x] == '.') {
            a[y][x] = '#';
            d = (d + 1) % 4;
        }
        else {
            a[y][x] = '.';
            d = (d + 3) % 4;
        }

        int ny = (y + dy[d] + h) % h;
        int nx = (x + dx[d] + w) % w;
        y = ny, x = nx;
    }

    for (auto& i : a) cout << i << '\n';
}