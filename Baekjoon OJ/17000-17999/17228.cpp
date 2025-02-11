#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

const int INF = 1e9 + 7;
const int MAXN = 505050;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int D = 26;

int n;
struct Edge { int w, v; };
vector<Edge> t[MAXN];
vector<int> a;

void input() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        t[u].push_back({ c - 'a', v });
    }
    string s; cin >> s;
    for (auto& c : s) {
        a.push_back(c - 'a');
    }
}

ll ah1, ah2;
ll p1[MAXN], p2[MAXN];

void get_hash() {
    ah1 = ah2 = a[0];
    for (int i = 1; i < sz(a); i++) {
        ah1 = (D * ah1 + a[i]) % MOD1;
        ah2 = (D * ah2 + a[i]) % MOD2;
    }

    p1[0] = p2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p1[i] = D * p1[i - 1] % MOD1;
        p2[i] = D * p2[i - 1] % MOD2;
    }
}

int len;
ll h1[MAXN], h2[MAXN];
ll ans = 0;

void dfs(int v) {
    if (len >= sz(a)) {
        ll res1 = (h1[len] - h1[len - sz(a)] * p1[sz(a)]) % MOD1;
        ll res2 = (h2[len] - h2[len - sz(a)] * p2[sz(a)]) % MOD2;
        res1 = (res1 + MOD1) % MOD1;
        res2 = (res2 + MOD2) % MOD2;

        if (res1 == ah1 && res2 == ah2) ans++;

        // cout << v << ' ' << res1 << ' ' << res2 << ' ' << ah1 << ' ' << ah2 << '\n';
    }

    for (auto& i : t[v]) {
        h1[len + 1] = (D * h1[len] + i.w) % MOD1;
        h2[len + 1] = (D * h2[len] + i.w) % MOD2;
        len++;
        dfs(i.v);
        len--;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    get_hash();

    dfs(1);

    cout << ans;
}