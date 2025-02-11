#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second

const int MAXN = 1010, MAXW = 1010;
const int INF = 1e9 + 7;

int N, W;
pii a[MAXW], b[MAXW];
int dp[MAXW][MAXW];

void init() {
    for (int i = 0; i < MAXW; i++) {
        for (int j = 0; j < MAXW; j++) {
            dp[i][j] = INF;
        }
    }
}

void input() {
    cin >> N >> W;
    a[0] = { 1, 1 };
    b[0] = { N, N };
    for (int i = 1; i <= W; i++) {
        cin >> a[i].fr >> a[i].sc;
        b[i] = a[i];
    }
}

int dist(pii st, pii en) { return abs(st.fr - en.fr) + abs(st.sc - en.sc); }

void bottomup() {
    // base case
    dp[1][0] = dist(a[0], a[1]);
    dp[0][1] = dist(b[0], b[1]);

    // inductive step
    for (int x = 2; x <= W; x++) {
        int p = -1, q = -1;
        
        p = x - 1;
        for (q = 0; q <= x - 2; q++) {
            dp[x][q] = min(dp[x][q], dp[p][q] + dist(a[p], a[x]));
            dp[p][x] = min(dp[p][x], dp[p][q] + dist(b[q], b[x]));
        }

        q = x - 1;
        for (p = 0; p <= x - 2; p++) {
            dp[x][q] = min(dp[x][q], dp[p][q] + dist(a[p], a[x]));
            dp[p][x] = min(dp[p][x], dp[p][q] + dist(b[q], b[x]));
        }
    }
}

void printAnswer() {
    int ans = INF;
    pii pos = { 0, 0 };
    for (int i = 0; i <= W - 1; i++) {
        if (dp[W][i] < ans) {
            ans = dp[W][i];
            pos = { W, i };
        }
        if (dp[i][W] < ans) {
            ans = dp[i][W];
            pos = { i, W };
        }
    }

    // dp backtracking
    vector<int> ans2(W + 1);

    for (int x = W; x >= 1; x--) {
        if (pos.fr == x) ans2[x] = 1;
        if (pos.sc == x) ans2[x] = 2;

        if (x == 1) break;

        if (abs(pos.fr - pos.sc) == 1) {
            int nans = INF;
            pii npos = { 0, 0 };

            if (pos.fr == x - 1) {
                for (int i = 0; i <= x - 2; i++) {
                    if (dp[x - 1][i] + dist(b[i], b[x]) < nans) {
                        nans = dp[x - 1][i] + dist(b[i], b[x]);
                        npos = { x - 1, i };
                    }
                }
            }
            if (pos.sc == x - 1) {
                for (int i = 0; i <= x - 2; i++) {
                    if (dp[i][x - 1] + dist(a[i], a[x]) < nans) {
                        nans = dp[i][x - 1] + dist(a[i], a[x]);
                        npos = { i, x - 1 };
                    }
                }
            }

            pos = npos;
        }
        else {
            if (pos.fr == x) pos.fr--;
            if (pos.sc == x) pos.sc--;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= W; i++)
        cout << ans2[i] << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    input();

    bottomup();

    printAnswer();
}