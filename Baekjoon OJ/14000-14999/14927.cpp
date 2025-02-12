#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int dy[] = { 0, 0, 1, 0, -1 };
const int dx[] = { 0, 1, 0, -1, 0 };

int n;
vector<vector<int>> a;

void modify(int y, int x, vector<vector<int>>& b) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        b[ny][nx] = !b[ny][nx];
    }
}

int isEmpty(vector<vector<int>>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j]) return 0;
        }
    }
    return 1;
}

int f() {
    vector<vector<int>> b = a;
    int ret = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i - 1][j]) {
                modify(i, j, b);
                ret++;
            }
        }
    }

    return isEmpty(b) ? ret : INF;
}

int bt(int v) {
    if (v == n) return f();

    int ret = INF;

    // a[0][v] := 0
    if (a[0][v] == 1) {
        modify(0, v, a);
        ret = min(ret, 1 + bt(v + 1));
        modify(0, v, a);
    }
    else ret = min(ret, bt(v + 1));

    // a[0][v] := 1
    if (a[0][v] == 0) {
        modify(0, v, a);
        ret = min(ret, 1 + bt(v + 1));
        modify(0, v, a);
    }
    else ret = min(ret, bt(v + 1));

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n, vector<int>(n));
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    int ans = bt(0);
    cout << (ans == INF ? -1 : ans);
}