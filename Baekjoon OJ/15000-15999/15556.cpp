#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

struct wv {
    ll w; int v;
    bool operator<(const wv& rhs) const {
        return w > rhs.w;
    }
};

int n, m, st1, en1, st2, en2;
vector<wv> adj[101010];

void input() {
    cin >> n >> m >> st1 >> en1 >> st2 >> en2;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u });
    }
}

ll dist[101010];
void dijkstra(int st, int en) {
    for (int i = 1; i <= n; i++) dist[i] = INF;

    priority_queue<wv> pq;
    pq.push({ 0, st });
    dist[st] = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (dist[v] < w) continue;

        for (auto& i : adj[v]) {
            if (dist[i.v] > w + i.w) {
                pq.push({ w + i.w, i.v });
                dist[i.v] = w + i.w;
            }
        }
    }
}

int vi[101010];
void backtrack(int st, int en) {
    queue<int> q;
    q.push(en);
    vi[en] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto& i : adj[v]) {
            if (dist[v] - dist[i.v] == i.w && !vi[i.v]) {
                q.push(i.v);
                vi[i.v] = 1;
            }            
        }
    }
}

struct wvbit {
    ll w; int v, bit;
    bool operator<(const wvbit& rhs) const {
        return w > rhs.w;
    }
};

ll ans = INF;

void dijkstra2(int st, int en) {
    vector<vector<ll>> dist2(101010, vector<ll>(3, INF));

    priority_queue<wvbit> pq;
    pq.push({ 0, st, 0 });
    dist2[st][0] = 0;

    while (!pq.empty()) {
        auto [w, v, bit] = pq.top();
        pq.pop();

        if (dist2[v][bit] < w) continue;

        if (v == en) ans = min(ans, w);

        for (auto& i : adj[v]) {
            ll nw = -1; int nbit = -1;
            if (bit == 0) {
                if (i.w == dist[i.v] - dist[v] && vi[v] && vi[i.v]) nbit = 1, nw = w;
                else nbit = 0, nw = w + i.w;

                if (nbit == 1 && dist2[i.v][0] > w + i.w) {
                    pq.push({ w + i.w, i.v, 0 });
                    dist2[i.v][0] = w + i.w;
                }
            }
            if (bit == 1) {
                if (i.w == dist[i.v] - dist[v] && vi[v] && vi[i.v]) nbit = 1, nw = w;
                else nbit = 2, nw = w + i.w;
            }
            if (bit == 2) {
                nbit = 2, nw = w + i.w;
            }

            if (dist2[i.v][nbit] > nw) {
                pq.push({ nw, i.v, nbit });
                dist2[i.v][nbit] = nw;
            }
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

    dijkstra(st1, en1);

    backtrack(st1, en1);

    dijkstra2(st2, en2);
    dijkstra2(en2, st2);
    
    cout << ans;
}