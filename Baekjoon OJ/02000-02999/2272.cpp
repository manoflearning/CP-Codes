#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(n);
    for (auto& i : a) cin >> i;
    
    for (int x = 0; x <= 29; x++) {
        if (!(m & (1 << x))) continue;

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            int idx = ((i - (1 << x)) % n + n) % n;
            b[idx] = a[i];
        }
        for (int i = 0; i < n; i++)
            a[i] = b[i] ^ a[i];
    }

    for (auto& i : a)
        cout << i << '\n';
}