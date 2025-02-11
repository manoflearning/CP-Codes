#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (auto& i : a) {
        int x; cin >> x;
        i = to_string(x);
        reverse(i.begin(), i.end());
        for (auto& j : i)
            if (j == '6') j = '9';
            else if (j == '9') j = '6';
    }

    sort(a.begin(), a.end(), [&](const string& p1, const string& p2) {
        return p1 + p2 > p2 + p1;
    });

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (a[idx].size() < a[i].size()) idx = i;
        else if (a[idx].size() == a[i].size() && a[idx] < a[i]) idx = i;
    }

    reverse(a.begin(), a.end());
    idx = n - idx - 1;
    for (auto& i : a) {
        reverse(i.begin(), i.end());
        for (auto& j : i)
            if (j == '6') j = '9';
            else if (j == '9') j = '6';
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i == idx) cout << a[i];
    }
}