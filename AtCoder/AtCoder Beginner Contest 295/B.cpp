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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    vector<pair<pii, int>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ('1' <= a[i][j] && a[i][j] <= '9') {
                b.push_back({ { i, j }, a[i][j] - '0' });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' || ('1' <= a[i][j] && a[i][j] <= '9')) cout << '.';
            else {
                int bit = 1;
                for (auto& k : b) {
                    int d = abs(k.fr.fr - i) + abs(k.fr.sc - j);
                    if (d <= k.sc) bit = 0;
                }
                cout << (bit ? a[i][j] : '.');
            }
        }
        cout << '\n';
    }

	return 0;
}