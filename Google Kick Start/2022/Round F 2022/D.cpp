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
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const int sq = 360;

struct plr {
    int p, l, r;
};

int n, k, x, d;
int m; 
vt<plr> a;
vt<int> l[101010], r[101010];
int ans = INF;
int cnt[101010];
ll bu[404], sum[404], cnt2[101010];

void init() {
    a.clear();
    FOR(101010) {
        l[i].clear();
        r[i].clear();
        cnt[i] = cnt2[i] = 0;
    }
    FOR(404) bu[i] = sum[i] = 0;
    ans = INF;
}

void input() {
    cin >> n >> k >> x >> d;
    
    cin >> m;
    a.resize(m);
    EACH(i, a) {
        cin >> i.p >> i.l >> i.r;
        l[i.l].push_back(i.p);
        r[i.r].push_back(i.p);
    }
}

void add(int idx) {
    EACH(i, l[idx - 1]) {
        bu[cnt[i] / sq]--;
        sum[cnt[i] / sq] -= cnt[i];
        cnt2[cnt[i]]--;
        
        cnt[i]++;
        
        bu[cnt[i] / sq]++;
        sum[cnt[i] / sq] += cnt[i];
        cnt2[cnt[i]]++;
    }
}

void del(int idx) {
	EACH(i, r[idx + 1]) {
        bu[cnt[i] / sq]--;
        sum[cnt[i] / sq] -= cnt[i];
        cnt2[cnt[i]]--;
        
        cnt[i]--;
        
        bu[cnt[i] / sq]++;
        sum[cnt[i] / sq] += cnt[i];
        cnt2[cnt[i]]++;
    }
}

int query() {
	int ret = 0, peo = 0;
    for (int i = 0; i < 404; i++) {
        if (!bu[i]) continue;

        if (peo + bu[i] > k) {
            for (int j = i * sq; j < (i + 1) * sq; j++) {
                if (peo + cnt2[j] > k) { return ret += (k - peo) * j; }
                
                ret += cnt2[j] * j;
                peo += cnt2[j];
            }
        }
        else peo += bu[i], ret += sum[i];
    }
    return ret;
}

void f() {
	int s = 0;
    bu[0] = n; cnt2[0] = n;
	EACH(i, a) {
        if (i.r <= s || s + x <= i.l) continue;
        bu[cnt[i.p] / sq]--;
        sum[cnt[i.p] / sq] -= cnt[i.p];
        cnt2[cnt[i.p]]--;
        
        cnt[i.p]++;
        
        bu[cnt[i.p] / sq]++;
        sum[cnt[i.p] / sq] += cnt[i.p];
        cnt2[cnt[i.p]]++;
    }
	ans = min(ans, query());

	for (s = 1; s + x <= d; s++) {
        add(s + x);
		del(s - 1);
		ans = min(ans, query());
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	FOR(tt, 1, tc + 1) {
		cout << "Case #" << tt << ": ";

        init();

        input();

        f();

        cout << ans << '\n';
	}

	return 0;
}