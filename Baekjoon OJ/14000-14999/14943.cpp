#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[101010];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) q.push({ i, a[i] });
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            while (a[i] != 0) {
                ll mn = min(-a[i], q.front().second);
                a[i] += mn, q.front().second -= mn;
                ans += mn * abs(q.front().first - i);
                if (q.front().second == 0) q.pop();
            }
        }
    }

    cout << ans;
}