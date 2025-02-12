// solution 1: fft
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

typedef complex<double> base;
void fft(vector<base> &a, bool inv) {
	int n = a.size(), j = 0;
	vector<base> roots(n / 2);
	for (int i = 1; i < n; i++){
		int bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for (int i = 0; i < n / 2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	for (int i = 2; i <= n; i <<= 1){
		int step = n / i;
		for (int j = 0; j < n; j += i){
			for (int k = 0; k < i / 2; k++) {
				base u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}
void multiply(const vector<ll> &v, const vector<ll> &w, vector<ll>& res) {
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while (n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for (int i = 0; i < n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	res.resize(n);
	for (int i = 0; i < n; i++) res[i] = (ll)round(fv[i].real());
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
    vector<ll> a(202020);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = 1;
    }

    vector<ll> res;
    multiply(a, a, res);

    int q; cin >> q;
    int ans = 0;
    while (q--) {
        int x; cin >> x;
        if (a[x] || res[x]) ans++;
    }

    cout << ans;

	return 0;
}

// solution 2: naive
//#pragma GCC optimize("O3")
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

int n, m;
vector<int> a;
int vi[202020], dp[202020];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

	cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    a.erase(unique(all(a)), a.end());

    for (auto& i : a) {
        dp[i] = vi[i] = 1;
        if (i * 2 < 202020) dp[i * 2] = 1;
    }

    cin >> m;
    int ans = 0;
    while (m--) {
        int v; cin >> v;
        if (dp[v] != -1) {
            ans += dp[v];
            continue;
        }

        int bit = 0;
        for (int i = upper_bound(all(a), v) - a.begin() - 1; i >= 0; i--) {
            int x = a[i];
            if (x < v - x) break;
            if (vi[v - x]) { bit = 1; break; }
        }
        dp[v] = bit;
        ans += dp[v];
    }

    cout << ans;

	return 0;
}*/