#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int n;
ll x0, a, b;
int l[1010], r[1010];

int qcnt;
vector<int> q;

void init() {
    for (int i = 0; i < 1010; i++) r[i] = MOD;
}

void input() {
    cin >> n >> x0 >> a >> b;
    cin >> qcnt;
    q.resize(qcnt);
    for (auto& i : q) cin >> i;
}

void pbs() {
    while (1) {
        vector<pii> arr;
        for (int i = 0; i < qcnt; i++) {
            if (l[i] == r[i]) continue;
            int mid = (l[i] + r[i]) >> 1;
            arr.push_back({ mid, i });
        }

        if (arr.empty()) break;

        sort(arr.begin(), arr.end());

        vector<int> psum(sz(arr) + 1);
        for (ll x = x0, i = 0; i < n; x = (x * a + b) % MOD, i++) {
            int idx = lower_bound(arr.begin(), arr.end(), pii(x, -1)) - arr.begin();
            psum[idx]++;
        }
        for (int i = 1; i < sz(arr); i++) psum[i] += psum[i - 1];

        for (int i = 0; i < sz(arr); i++) {
            int qidx = arr[i].sc, mid = arr[i].fr;
            if (psum[i] <= q[qidx]) l[qidx] = mid + 1;
            else r[qidx] = mid;
        }
    }
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

    pbs();

    ll ans = 0;
    for (int i = 0; i < qcnt; i++) ans += l[i];

    cout << ans;

    return 0;
}