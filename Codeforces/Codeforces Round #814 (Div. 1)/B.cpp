#define _USE_MATH_DEFINES
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

vt<ll> fibo, psum;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    fibo.push_back(1);
    fibo.push_back(1);
    psum.push_back(1);
    psum.push_back(2);

    while (psum.back() <= 100 * (ll)1e9) {
        fibo.push_back(fibo[sz(fibo) - 1] + fibo[sz(fibo) - 2]);
        psum.push_back(psum[sz(psum) - 1] + fibo.back());
    }

	int tc; cin >> tc;
	FOR(tt, 1, tc + 1) {
		int n; cin >> n;

        vt<ll> a(n);
        ll sum = 0;
        EACH(i, a) {
            cin >> i;
            sum += i;
        }

        int idx = lower_bound(all(psum), sum) - psum.begin();

        if (psum[idx] != sum) {
            cout << "NO\n";
            continue;
        }

        priority_queue<ll> pq;
        EACH(i, a) pq.push(i);

        int ans = 1;
        FOR(i, idx, -1, -1) {
            if (pq.empty()) { ans = 0; break; }

            ll val = pq.top();
            pq.pop();

            if (val < fibo[i]) { ans = 0; break; }
            if (sz(pq) && val - fibo[i] > pq.top()) { ans = 0; break; }
            if (pq.empty() && i > 0) { ans = 0; break; }

            if (val > fibo[i]) pq.push(val - fibo[i]);
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
	}

	return 0;
}