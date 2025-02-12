#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, deg[2020202];
ll sum;
queue<int> q1, q2;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> deg[i];
        sum += deg[i];
        if (deg[i] == 1) q1.push(i);
        else q2.push(i);
    }

    if (sum != 2 * (n - 1)) {
        cout << "BRAK";
        return 0;
    }

    while (!q1.empty() && !q2.empty()) {
        int v1 = q1.front(), v2 = q2.front();
        q1.pop(); q2.pop();
        cout << v1 << ' ' << v2 << '\n';
        deg[v1]--, deg[v2]--;
        if (deg[v2] == 1) q1.push(v2);
        else q2.push(v2);
    }

    int v1 = q1.front(); q1.pop();
    int v2 = q1.front(); q1.pop();
    cout << v1 << ' ' << v2 << '\n';
}