#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int MAXN = 1010101;

int n;
vector<ll> a, b;
vector<ll> dpa, dpb;
ll ans = INF;

void input() {
    cin >> n;
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x) {
            a.push_back(i);
            b.push_back(n - i + 1);
        }
    }
    b.push_back(0);
}

struct Line {
    ll p, q;
    double s;
    Line(): Line(1, 0) {}
    Line(ll sp, ll sq): p(sp), q(sq), s(0) {}
};
double cross(const Line& u, const Line& v) {
    return (double)(v.q - u.q) / (u.p - v.p);
}

Line ch[MAXN];

void linearDP(const vector<ll>& dist, vector<ll>& dp) {
    dp.resize(sz(dist));

    dp[0] = dist[0] + dist[0];

    int top = 1, opt = 0;
    for (int i = 1; i < sz(dist); i++) {
        // let x := dist[i], then opt := argmin_j(y) (y = -jx + dp[j], j < i)
        Line g(-(i - 1), dp[i - 1]);

        while (top > 1) {
            g.s = cross(ch[top - 1], g);
            if (ch[top - 1].s < g.s) break;
            --top;
        }
        ch[top++] = g;
        
        while (opt + 1 < top && ch[opt].p * dist[i] + ch[opt].q >= ch[opt + 1].p * dist[i] + ch[opt + 1].q) opt++;
        dp[i] = ch[opt].q + (i + ch[opt].p) * dist[i] + dist[i];
    }
}

void solve() {
    linearDP(a, dpa);
    reverse(all(b));
    linearDP(b, dpb);
    reverse(all(b));
    reverse(all(dpb));
    for (int i = 0; i < sz(dpa); i++) {
        ans = min(ans, dpa[i] + dpb[i]);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    solve();

    cout << ans;
}