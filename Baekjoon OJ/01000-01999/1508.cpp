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

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(k);
    for (auto& i : arr) cin >> i;

    if (m == 0) {
        for (int i = 0; i < k; i++) cout << 0;
        return 0;
    }
    if (m == 1) {
        for (int i = 0; i < k - 1; i++) cout << 0;
        cout << 1;
        return 0;
    }

    vector<int> ans(k);

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        vector<int> res(k);
        res[0] = 1;
        int prv = 0, cnt = 1;
        for (int i = 1; i < k; i++) {
            if (arr[i] - arr[prv] >= mid) {
                prv = i;
                cnt++;
                res[i] = 1;
            }
            if (cnt == m) break;
        }

        if (cnt == m) {
            l = mid;
            ans = res;
        }
        else r = mid - 1;
    }

    for (auto& i : ans)
        cout << i;

	return 0;
}