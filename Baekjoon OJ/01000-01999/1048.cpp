#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int n, m, l;
string s;
vector<string> a;
int dp[55][303][303][4];

void init() {
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 303; j++) {
            for (int k = 0; k < 303; k++) {
                for (int u = 0; u < 4; u++) {
                    dp[i][j][k][u] = -1;
                }
            }
        }
    }
}

void input() {
    cin >> n >> m >> l;
    cin >> s;
    a.resize(n);
    for (auto& i : a) cin >> i;
}

const int dy[] = { 1, 1, -1, -1 };
const int dx[] = { 1, -1, 1, -1 };

int f(int idx, int y, int x, int d) {
    if (y < 0 || n <= y || x < 0 || m <= x) return 0;

    int& ret = dp[idx][y][x][d];
    if (ret != -1) return ret;
    if (idx == sz(s) - 1) return ret = 1;

    ret = 0;

    int ny = y + 2 * dy[d], nx = x + 3 * dx[d];
    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (a[ny][nx] == s[idx + 1]) {
            if (idx == sz(s) - 2) ret = (ret + 1) % MOD;
            else {
                ret = (ret + f(idx + 1, ny, nx, 0)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 1)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 2)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 3)) % MOD;
            }
        }
    }
    ny = y + 3 * dy[d], nx = x + 2 * dx[d];
    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (a[ny][nx] == s[idx + 1]) {
            if (idx == sz(s) - 2) ret = (ret + 1) % MOD;
            else {
                ret = (ret + f(idx + 1, ny, nx, 0)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 1)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 2)) % MOD;
                ret = (ret + f(idx + 1, ny, nx, 3)) % MOD;
            }
        }
    }
    ny = y + 3 * dy[d], nx = x + 3 * dx[d];
    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (a[ny][nx] == s[idx + 1]) {
            if (idx == sz(s) - 2) ret = (ret - 1) % MOD;
            else {
                ret = (ret - f(idx + 1, ny, nx, 0)) % MOD;
                ret = (ret - f(idx + 1, ny, nx, 1)) % MOD;
                ret = (ret - f(idx + 1, ny, nx, 2)) % MOD;
                ret = (ret - f(idx + 1, ny, nx, 3)) % MOD;
            }
        }
    }

    ret = (ret + f(idx, y, x + dx[d], d)) % MOD;
    ret = (ret + f(idx, y + dy[d], x, d)) % MOD;
    ret = (ret - f(idx, y + dy[d], x + dx[d], d)) % MOD;

    ret = (ret + MOD) % MOD;

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    init();

	input();

    if (sz(s) == 1) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == s[0]) ans++;
            }
        }
        cout << ans;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == s[0]) {   
                int res = 0;
                res = (res + f(0, i, j, 0)) % MOD;
                res = (res + f(0, i, j, 1)) % MOD;
                res = (res + f(0, i, j, 2)) % MOD;
                res = (res + f(0, i, j, 3)) % MOD;
                //cout << i << ' ' << j << ' ' << res << '\n';
                ans = (ans + res) % MOD;
            }
        }
    }

    cout << ans;

	return 0;
}