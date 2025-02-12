#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> odd(int n) {
    vector<vector<int>> ret(n, vector<int>(n));
    
    ret[n - 1][n / 2] = 1;
    int py = n - 1, px = n / 2;

    for (int v = 2; v <= n * n; v++) {
        int y = py + 1, x = px + 1;
        if (n <= y || n <= x) {
            if (y < n) {
                for (int i = 0; i < n; i++) {
                    if (!ret[y][i]) { x = i; break; }
                }
            }
            else if (x < n) {
                for (int i = 0; i < n; i++) {
                    if (!ret[i][x]) { y = i; break; }
                }
            }
            else y = py - 1, x = px;
        }
        else if (ret[y][x]) y = py - 1, x = px;
        
        if (y >= n || x >= n) break;

        ret[y][x] = v;
        py = y, px = x;
    }

    return ret;
}

vector<vector<int>> evenMul4(int n) {
    vector<vector<int>> ret(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = n * i + j + 1;
        }
    }

    int bo = n / 4;
    vector<vector<int>> fixed(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int bi = (i < bo || 3 * bo <= i);
            int bj = (j < bo || 3 * bo <= j);
            if (bi && bj) fixed[i][j] = 1;
            if (!bi && !bj) fixed[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fixed[i][j]) continue;
            int p = n - i - 1, q = n - j - 1;
            swap(ret[i][j], ret[p][q]);
            fixed[i][j] = fixed[p][q] = 1;
        }
    }

    return ret;
}

vector<vector<int>> evenNotMul4(int n) {
    vector<vector<int>> ret(n, vector<int>(n));

    int cnt = n / 4;

    for (int i = 0; i < n / 2; i++) {
        for (int j = (i == n / 4), k = 0; k < cnt; j++, k++) {
            ret[i][j] = 3;
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (ret[i - n / 2][j] == 0) ret[i][j] = 3;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = n - 1, k = 0; k < cnt - 1; j--, k++) {
            ret[i][j] = 1;
        }
        for (int j = n / 2; j < n; j++) {
            if (ret[i][j] == 0) ret[i][j] = 2;
        }
    }

    for (int i = n / 2; i < n; i++) {
        for (int j = n / 2; j < n; j++) {
            if (ret[i - n / 2][j] == 1) ret[i][j] = 2;
            if (ret[i - n / 2][j] == 2) ret[i][j] = 1;
        }
    }

    auto res = odd(n / 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] *= n * n / 4;
            ret[i][j] += res[i % (n / 2)][j % (n / 2)];
        }
    }

    return ret;
}

int isItMagicSquare(int n, const vector<vector<int>>& a) {
    int sum = (1 + n * n) * n / 2;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) res += a[i][j];
        if (res != sum) return 0;
    }
    for (int j = 0; j < n; j++) {
        int res = 0;
        for (int i = 0; i < n; i++) res += a[i][j];
        if (res != sum) return 0;
    }
    int res = 0;
    for (int i = 0; i < n; i++) res += a[i][i];
    if (res != sum) return 0;
    res = 0;
    for (int i = 0; i < n; i++) res += a[i][n - i - 1];
    if (res != sum) return 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) s.insert(a[i][j]);
    }
    return s.size() == n * n;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    vector<vector<int>> ans;

    if (n & 1) ans = odd(n);
    else {
        if (n % 4 == 0) ans = evenMul4(n);
        else ans = evenNotMul4(n);
    }

    assert(isItMagicSquare(n, ans));

    for (auto& i : ans) {
        for (auto& j : i) 
            cout << j << ' ';
        cout << '\n';
    }
}