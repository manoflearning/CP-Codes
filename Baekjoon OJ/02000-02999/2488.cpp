#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

const int MAXN = 30303;

int n, m;
int a[MAXN], b[MAXN];
int pa[MAXN], pb[MAXN];
pii dp_left[101], dp_right[101];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pa[i] = a[i] + pa[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        pb[i] = b[i] + pb[i - 1];
    }
}

int suma(int l, int r) { return pa[r] - pa[l - 1]; }
int sumb(int l, int r) { return pb[r] - pb[l - 1]; }

void left_right() {
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (j < m && pb[j] + 50 < pa[i]) j++;
        for (int k = 0; k < 5; k++) {
            if (j + k > m) break;
            int diff = pa[i] - pb[j + k];
            if (50 < abs(diff)) break;
            if (dp_left[diff + 50] == make_pair(0, 0)) {
                dp_left[diff + 50] = { i, j + k };
            }
        }
    }

    j = m;
    for (int i = n; i >= 1; i--) {
        while (j > 1 && sumb(j, m) + 50 < suma(i, n)) j--;
        for (int k = 0; k > -5; k--) {
            if (j + k < 0) break;
            int diff = suma(i, n) - sumb(j + k, m);
            if (50 < abs(diff)) break;
            if (dp_right[diff + 50] == make_pair(0, 0)) {
                dp_right[diff + 50] = { i, j + k };
            }
        }
    }
}

bool is_pos = 0;
vector<int> ans1(3);
vector<int> ans2(3);

void solve() {
    int mn = INF;
    for (int i = 0; i < 101; i++) {
        if (dp_left[i] == make_pair(0, 0)) continue;
        for (int j = 0; j < 101; j++) {
            if (dp_right[j] == make_pair(0, 0)) continue;

            if (dp_left[i].fr + 1 >= dp_right[j].fr) continue;
            if (dp_left[i].sc + 1 >= dp_right[j].sc) continue;

            int res = 0;
            res = max(res, abs(i - 50));
            res = max(res, abs(j - 50));
            res = max(res, abs(
                suma(dp_left[i].fr + 1, dp_right[j].fr - 1)
                - sumb(dp_left[i].sc + 1, dp_right[j].sc - 1)
                ));

            if (res < mn) {
                is_pos = 1;
                mn = res;
                ans1 = { dp_left[i].fr, dp_right[j].fr - dp_left[i].fr - 1, n - dp_right[j].fr + 1 };
                ans2 = { dp_left[i].sc, dp_right[j].sc - dp_left[i].sc - 1, m - dp_right[j].sc + 1 };
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    left_right();

    solve();

    if (is_pos) {
        for (auto& i : ans1) cout << i << ' ';
        cout << '\n';
        for (auto& i : ans2) cout << i << ' ';
        cout << '\n';
    }
    else cout << -1;
}