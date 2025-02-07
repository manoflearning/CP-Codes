//#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Fenwick {
    int flag;
    vector<ll> t;
    void build(int N) {
        flag = N;
        t.resize(flag + 1);
    }
    void modify(int l, int r, int val) {
        for (; l <= flag; l += l & -l) t[l] += val;
        for (r++; r<= flag; r += r & -r) t[r] -= val;
    }
    ll query(int x) {
        ll ret = 0;
		for (; x; x ^= x & -x) ret += t[x];
		return ret;
    }
} fw[1515];

int N;
vector<vector<ll>> a, dp;

void input() {
    cin >> N;
    a.resize(N + 1, vector<ll>(N + 1));
    dp.resize(N + 1, vector<ll>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
}

ll f(int y, int x) { 
    if (y < 1 || x < 1) return 0;
    return fw[y].query(x);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    input();

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        fw[i].build(N);
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            fw[i].modify(j, j, dp[i][j]);
            ans += dp[i][j];
        }
    }

    cout << ans << '\n';

    for (int q = 0; q < N; q++) {
        char op; int y, x;
        cin >> op >> y >> x;

        if (op == 'U') {
            a[y][x]++;

            int s = x, e = x;
            for (; e < N; e++) {
                if (f(y, e) + 1 + a[y][e + 1] <= f(y, e + 1)) break;
            }
            fw[y].modify(s, e, 1);
            ans += e - s + 1;

            for (int i = y + 1; i <= N; i++) {
                for (; s <= e; s++) {
                    if (f(i - 1, s) + a[i][s] > f(i, s)) break;
                }
                if (e < s) break;
                for (; e < N; e++) {
                    if (f(i, e) + 1 + a[i][e + 1] <= f(i, e + 1)) break;
                }
                fw[i].modify(s, e, 1);
                ans += e - s + 1;
            }
        }
        if (op == 'D') {
            a[y][x]--;

            int s = x, e = x;
            for (; e < N; e++) {
                if (f(y - 1, e + 1) + a[y][e + 1] == f(y, e + 1)) break;
            }
            fw[y].modify(s, e, -1);
            ans -= e - s + 1;

            for (int i = y + 1; i <= N; i++) {
                for (; s <= e; s++) {
                    if (f(i, s - 1) + a[i][s] < f(i, s)) break;
                }
                if (e < s) break;
                for (; e < N; e++) {
                    if (f(i - 1, e + 1) + a[i][e + 1] == f(i, e + 1)) break;
                }
                fw[i].modify(s, e, -1);
                ans -= e - s + 1;
            }
        }

        cout << ans << '\n';
    }
}