#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for (auto& i : a) {
        int k; cin >> k;
        i.resize(k);
        for (auto& j : i) { cin >> j; j--; }
    }

    vector<int> res(n);
    for (auto& i : res) cin >> i;

    vector<int> cur = res;
    for (int i = m - 1; i >= 0; i--) {
        auto& it = a[i];
        int bit = 0;
        for (auto& j : it) if (!cur[j]) bit = 1;
        if (bit) for (auto& j : it) cur[j] = 0;
    }

    vector<int> tmp = cur;

    for (auto& i : a) {
        int bit = 0;
        for (auto& j : i) if (cur[j]) bit = 1;
        if (bit) for (auto& j : i) cur[j] = 1;
    }

    if (cur == res) {
        cout << "YES\n";
        for (auto& j : tmp) 
            cout << j << ' ';
    }
    else cout << "NO\n";
}