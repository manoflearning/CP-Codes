#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p2[33];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    p2[0] = 1;
    for (int i = 1; i < 33; i++) p2[i] = 2 * p2[i - 1]; 

    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        ll ans = 0;
        int bit = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') ans += (bit ? 1 : -1) * (p2[i + 1] - 1), bit = !bit;
        }
        cout << ans << '\n';
    }
}