//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Node {
    int w, s, e;
};

int n, k;
vector<Node> a;

int sum = 0, vi[6][11];
int bt(int v) {
    if (v == sz(a)) {
        return sum == k;
    }
    if (sum > k) return 0;

    if (a[v].w == 5) return bt(v + 1);
    
    int ret = 0;

    int bit = 1;
    for (int i = a[v].s; i <= a[v].e; i++) {
        if (vi[a[v].w][i]) bit = 0;
    }

    if (bit) {
        for (int i = a[v].s; i <= a[v].e; i++) {
            vi[a[v].w][i] = 1;
        }
        sum += a[v].e - a[v].s + 1;
        ret += bt(v + 1);
        for (int i = a[v].s; i <= a[v].e; i++) {
            vi[a[v].w][i] = 0;
        }
        sum -= a[v].e - a[v].s + 1;
    }

    ret += bt(v + 1);

    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
    a.resize(n);
    for (auto& i : a) 
        cin >> i.w >> i.s >> i.e;

    cout << bt(0);

	return 0;
}