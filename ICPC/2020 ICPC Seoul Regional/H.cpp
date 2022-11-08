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

const int MAX = 30000;

vector<ll> a(MAX << 1), b(MAX << 1), c(MAX << 1);

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif
    
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int na; cin >> na;
    for (int i = 0; i < na; i++) {
        int x; cin >> x;
        a[x + MAX] = 1;
    }
    int nb; cin >> nb;
    for (int i = 0; i < nb; i++) {
        int x; cin >> x;
        b[x + MAX] = 1;
    }
    int nc; cin >> nc;
    for (int i = 0; i < nc; i++) {
        int x; cin >> x;
        c[x + MAX] = 1;
    }

    vector<ll> d = multiply(a, c);

    ll ans = 0;
    for (int i = 0; i < (MAX << 1); i++) {
        ans += b[i] * d[i << 1];
    }

    cout << ans;

    return 0;
}