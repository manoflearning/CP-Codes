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

int n;
vector<string> a;
vector<int> adj[555], radj[555];
int deg[555];

void init() {
    for (int i = 0; i < 555; i++) {
        adj[i].clear(); radj[i].clear();
        deg[i] = 0;
    }
}

void input() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
}

void buildGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'W') {
                adj[i].push_back(j);
                radj[j].push_back(i);
                deg[i]++;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        init();

        input();

        buildGraph();

        vector<int> ord;
        for (int i = 0; i < n; i++) ord.push_back(i);
        sort(all(ord), [&](const int p1, const int p2) {
            return deg[p1] > deg[p2];
        });

        vector<int> ans;
        vector<int> vi(n);
        for (int i = 0; i < n; i++) {
            int v = ord[i];
            if (vi[v]) continue;
            ans.push_back(v);
            
            vi[v] = 1;
            for (auto& u : radj[v]) {
                if (vi[u]) continue;
                vi[u] = 1;
                for (auto& p : radj[u]) deg[p]--;
            }

            sort(ord.begin() + i + 1, ord.end(), 
            [&](const int p1, const int p2) {
                return deg[p1] > deg[p2];
            });
        }

        int len = 0;
        for (int i = 1; i <= n; i <<= 1, len++);

        for (int i = 0; i < len; i++) 
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
}