#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        vector<int> a(5);
        for (auto& i : a) cin >> i;

        if (a[0] + a[1] + a[2] == 0) {
            if (a[3] & 1) cout << "geometry";
            else cout << "number_theory";
        }
        else if (a[0] + a[1] + a[2] == 1) {
            if (a[3] & 1) {
                cout << (a[0] || a[2] ? "geometry" : "number_theory");
            }
            else {
                cout << (a[0] || a[2] ? "number_theory" : "geometry");
            }
        }
        else {
            cout << "hanbyeol";
        }

        cout << '\n';
    }
}