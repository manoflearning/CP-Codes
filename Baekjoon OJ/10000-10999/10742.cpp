#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

int n, k;
vector<double> a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    double l = 1, r = 1e6;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        vector<double> psum(n + 1);
        for (int i = 1; i <= n; i++) {
            psum[i] = a[i] - mid + psum[i - 1];
        }
        
        int res = 0;
        double mn = psum[0];
        for (int i = k; i <= n; i++) {
            mn = min(mn, psum[i - k]);
            if (mn <= psum[i]) res = 1;
        }
        
        if (res) l = mid;
        else r = mid;
    }

    cout << fixed;
    cout.precision(6);
    cout << l;
}