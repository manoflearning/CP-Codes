#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef complex<double> base;

void fft(vector<base> &a, bool inv){
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
	if (inv) for (int i = 0; i < n; i++) a[i] /= n; // skip for OR convolution.
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while (n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for (int i = 0; i < n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for (int i = 0; i < n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

int n, l, m;
ll w, sum[13131];

vector<ll> P[101], T[101];

void input() {
    cin >> n >> l >> m >> w;
    for (int i = 0; i < m; i++) {
        P[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> P[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        T[i].resize(l);
        for (int j = l - 1; j >= 0; j--) {
            cin >> T[i][j];
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

	input();

    for (int i = 0; i < m; i++) {
        vector<ll> res = multiply(P[i], T[i]);
        //cout << res.size() << ' ' << n + l - 1 << '\n';
        for (int j = l - 1; j < n; j++) {
            sum[j] += res[j];
        }
    }

    int ans = 0;
    for (int i = l - 1; i < n; i++) {
        if (sum[i] > w) ans++;
    }

    cout << ans;

	return 0;
}