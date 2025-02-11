#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second
#define ll long long

int flag;  // array size
struct Seg {  // 1-indexed
	vector<ll> t;

	void build(int n) {
		for (flag = 1; flag < n; flag <<= 1);
		t.resize(2 * flag);

		//for (int i = flag; i < flag + n; i++) cin >> t[i];
		//for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void modify(int p, ll value) {  // set value at position p
        p += flag - 1;
		for (t[p] = max(value, t[p]); p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}
	ll query(int l, int r, int n = 1, int nl = 1, int nr = flag) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return max(query(l, r, n << 1, nl, mid), query(l, r, n << 1 | 1, mid + 1, nr));
	}
}seg;

const int MAX = 1e5 + 1;

struct Node {
    int sy, ey, idx;
};

int n, dp[MAX + 1];
vector<Node> open[MAX + 1], close[MAX + 1];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx++, sy++, ex++, ey++;
        open[sx].push_back({ sy, ey, i });
        close[ex].push_back({ sy, ey, i });
    }

    seg.build(MAX);

    for (int x = 1; x <= MAX; x++) {
        for (auto& i : open[x]) {
            dp[i.idx] = seg.query(1, i.sy - 1) + 1;
        }

        for (auto& i : close[x]) {
            seg.modify(i.ey, dp[i.idx]);
        }
    }

    cout << seg.query(1, MAX);

    return 0;
}