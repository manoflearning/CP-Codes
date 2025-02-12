#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

struct Seg {
	int flag;  // array size
	vector<ll> t;

	void build(int N) {
		for (flag = 1; flag < N; flag <<= 1);
		t.resize(2 * flag);

		for (int i = flag; i < flag + N; i++) t[i] = 1;
		for (int i = flag - 1; i >= 1; i--) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void modify(int p) {  // set value at position p
		for (t[p += flag - 1] = 0; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, flag);
	}
	ll query(int l, int r, int n, int nl, int nr) {  // sum on interval [l, r]
		if (r < nl || nr < l) return 0;
		if (l <= nl && nr <= r) return t[n];

		int mid = (nl + nr) / 2;
		return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
	}
	
	int findKey(int sum) {
	    return findKey(1, 1, flag, sum);
	}
	int findKey(int n, int nl, int nr, int sum) {
	    if (nl == nr) return nl;
	    
	    int mid = (nl + nr) / 2;
	    if (t[n << 1] >= sum) return findKey(n << 1, nl, mid, sum);
	    else return findKey(n << 1 | 1, mid + 1, nr, sum - t[n << 1]);
	}
}seg;

int n, k;
vector<int> ans;

void input() {
    cin >> n >> k;
}

void init() {
    seg.build(n);
}

void procedure() {
    int idx = 0;
	
	for (int i = 0; i < n; i++) {
	    int sum = seg.query(1, idx), left = seg.query(idx + 1, n);
	    
	    if (k <= left) sum += k;
	    if (k > left) {
	        sum = k - left;
	        
	        if (sum > n - i) sum %= (n - i);
	        if (sum == 0) sum = (n - i);
	    }
        
        int key = seg.findKey(sum);
	    
	    ans.push_back(key);
	    
	    seg.modify(key);
	    
	    idx = key;
	}
}

void output() {
    cout << '<';
	for (int i = 0; i < n; i++) {
	    cout << ans[i];
	    if (i < n - 1) cout << ", ";
	}
	cout << '>';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();
	
	init();
	
	procedure();
	
	output();
	
	return 0;
}
