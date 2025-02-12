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
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m, cnt[11];
vector<int> a[11];
int ans = INF;

void bt(int v, int res) {
    if (v == m + 1) {
        int bit = 1;
        for (int i = 1; i <= n; i++)
            if (!cnt[i]) bit = 0;
        if (bit) ans = min(ans, res);
        return;
    }

    bt(v + 1, res);

    for (auto& i : a[v]) cnt[i]++;
    bt(v + 1, res + 1);
    for (auto& i : a[v]) cnt[i]--;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        a[i].resize(x);
        for (auto& j : a[i]) cin >> j;
    }

    bt(1, 0);

    cout << (ans == INF ? -1 : ans);

	return 0;
}