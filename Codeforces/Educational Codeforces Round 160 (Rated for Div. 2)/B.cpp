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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        string s; cin >> s;

        int cnt0 = 0, cnt1 = 0;
        for (auto& c : s) {
            if (c == '0') cnt0++;
            else cnt1++;
        }

        int pcnt0 = 0, pcnt1 = 0;
        int ans = sz(s);
        for (auto& c : s) {
            if (c == '0') pcnt0++;
            else pcnt1++;

            if (pcnt0 <= cnt1 && pcnt1 <= cnt0) {
                ans = min(ans, sz(s) - (pcnt0 + pcnt1));
            }
        }

        cout << ans << '\n';
    }
}