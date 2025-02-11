#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

struct Edge { int v; ll w; int co; };

int n, m;
ll X;
vector<Edge> adj[202020];

void input() {
    cin >> n >> m >> X;
    for (int i = 0; i < m; i++) {
        int u, v; ll w; int co;
        cin >> u >> v >> w >> co;
        adj[u].push_back({ v, w, co });
        adj[v].push_back({ u, w, co });
    }
}

ll dijkstra(ll w1, ll w2) {
    struct wv {
        ll w; int v;
        bool operator<(const wv& rhs) const {
            return w > rhs.w;
        }
    };
    priority_queue<wv> pq;
    vector<ll> dist(n + 1, INF);
    pq.push({ 0, 1 });
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();
        
        if (dist[v] < w) continue;

        for (auto& i : adj[v]) {
            ll nw = w + i.w + (i.co == 0 ? 0 : (i.co == 1 ? w1 : w2));
            if (dist[i.v] <= nw) continue;
            pq.push({ nw, i.v });
            dist[i.v] = nw;
        }
    }

    return dist[n];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    ll l = 0, r = X;
    while (3 <= r - l) {
        ll m1 = (2 * l + r) / 3;
        ll m2 = (l + 2 * r) / 3;
        ll res1 = dijkstra(m1, X - m1), res2 = dijkstra(m2, X - m2);
        if (res1 <= res2) l = m1;
        else r = m2;
    }

    ll ans = 0;
    for (int i = l; i <= r; i++)
        ans = max(ans, dijkstra(i, X - i));
    cout << ans;
}