#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif
    
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    ll sum1, sum2;
    cin >> sum1 >> sum2;
    for (int i = 2; i < n; i++) {
        ll x; cin >> x;
        if (sum1 == sum2) sum1 += x;
        else if (sum1 > sum2) sum2 += x;
        else if (sum1 < sum2) sum1 += x;
    }

    ll diff = abs(sum1 - sum2), ans = 0;
    vector<ll> a = { 1, 2, 5, 10, 20, 50, 100 };
    for (int i = 6; i >= 0; i--) {
        ans += diff / a[i];
        diff %= a[i];
    }

    cout << ans;
}