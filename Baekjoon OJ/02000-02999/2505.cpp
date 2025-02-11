#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<pair<int, int>> ans;

void flip(vector<int>& b) {
    int loc = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] == i) continue;
        if (loc == -1 || b[i] < b[loc]) loc = i;
    }

    if (loc != -1)
        ans.push_back({ b[loc], loc });
    
    for (int i = b[loc], j = loc; i < j; i++, j--) {
        swap(b[i], b[j]);
    }
}

int simul() {
    ans.clear();

    vector<int> b = a;

    flip(b);
    flip(b);

    for (int i = 1; i <= n; i++)
        if (i != b[i]) return 0;

    return 1;
}

void print() {
    while (ans.size() < 2) ans.push_back({ 1, 1 });
    for (auto& i : ans)
        cout << i.first << ' ' << i.second << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (simul()) print();
    else {
        for (int i = 1, j = n; i <= j; i++, j--) {
            swap(a[i], a[j]);
            a[i] = n - a[i] + 1;
            if (i ^ j) a[j] = n - a[j] + 1;
        }

        simul();
        for (auto& i : ans) {
            i.first = n - i.first + 1;
            i.second = n - i.second + 1;
            swap(i.first, i.second);
        }
        print();
    }
}