#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll a[505], sum;
vector<int> ans;

ll getMax(int l, int r) {
    ll ret = 0;
    for (int i = l; i <= r; i++) ret = max(ret, a[i]);
    return ret;
}

int isValid(int x) {
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (i == x) continue;
        if (a[i] > 0) cnt++;
    }
    for (int i = 1; i <= n + 1; i++) {
        if (i == x) continue;
        if (!(0 <= a[i] && a[i] <= cnt - 1)) return 0;
    }
    return 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i]; sum += a[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        if (!isValid(i)) continue;

        ll left = sum - a[i];
        if (left & 1) continue;

        if (getMax(1, i - 1) > left / 2) continue;
        if (getMax(i + 1, n + 1) > left / 2) continue;

        ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto& i : ans)
        cout << i << '\n';
}