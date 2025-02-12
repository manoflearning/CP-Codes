#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> a;
double mn = 2, mx = -1;

void input() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    for (auto& i : a) {
        mn = min(mn, i);
        mx = max(mx, i);
    }

    for (auto& i : a) i = i / mn;
    mx /= mn;

    int ans = -1;
    double ansDiff = 2;
    for (int x = 1; (int)(x * mx + 0.5) <= 10000; x++) {
        double diff = 0;
        for (auto& i : a) {
            int y = (x * i + 0.5);
            diff = max(diff, abs(y - x * i));
        }
        if (diff < ansDiff) { ans = x, ansDiff = diff; }
    }

    for (auto& i : a) {
        cout << (int)(ans * i + 0.5) << '\n';
    }
}