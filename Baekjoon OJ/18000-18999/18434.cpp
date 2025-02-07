#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll INF = 1e17;

const int MAXN = 202;
const int MAXM = 50505;

struct Edge { int u, v, id; ll c, d; };
int n, m;
vector<Edge> e;

struct wv {
    ll w; int v, id;
    bool operator<(const wv& rhs) const {
        return w > rhs.w;
    }
};
vector<vector<wv>> g, rg;

void input() {
    cin >> n >> m;
    g.resize(n + 1);
    rg.resize(n + 1);
    e.resize(m);
    int idCnt = 0;
    for (auto& i : e) {
        cin >> i.u >> i.v >> i.c >> i.d;
        i.id = ++idCnt;
        g[i.u].push_back({ i.c, i.v, i.id });
        rg[i.v].push_back({ i.c, i.u, i.id });
    }
}

vector<ll> dist_1, dist_N;
vector<ll> rdist_1, rdist_N;
void dijkstra(int st, vector<ll>& dist, const vector<vector<wv>>& g) {
    dist.resize(n + 1, INF);

    priority_queue<wv> pq;
    pq.push({ 0, st, 0 });
    dist[st] = 0;

    while (!pq.empty()) {
        ll w = pq.top().w;
        int v = pq.top().v;
        pq.pop();

        if (dist[v] < w) continue;

        for (auto& i : g[v]) {
            if (w + i.w < dist[i.v]) {
                pq.push({ w + i.w, i.v, 0 });
                dist[i.v] = w + i.w;
            }
        }
    }
}

vector<vector<int>> dag_1, dag_N;
vector<int> in_dag_1(MAXM), in_dag_N(MAXM);

void buildDAG(const vector<ll>& dist, vector<vector<int>>& dag, vector<int>& in_dag) {
    dag.resize(MAXN);
    for (auto& i : e) {
        if (dist[i.u] + i.c == dist[i.v]) {
            dag[i.u].push_back(i.v);
            in_dag[i.id] = 1;
        }
    }
}



ll get(const Edge& i, int en, const vector<ll>& dist, const vector<ll>& rdist, const vector<int>& in_dag, const set<pii>& aEdge) {
    ll ret = 0;
    if (in_dag[i.id] && dist[i.u] + i.c + rdist[i.v] == dist[en] && aEdge.count({ min(i.u, i.v), max(i.u, i.v) })) {
        ll res = INF;
        for (auto& j : e) {
            if (!in_dag[j.id]) {
                res = min(res, dist[i.u] + i.c + rdist[i.v]);
            }
        }
        ret = min(res, dist[i.v] + i.c + rdist[i.u]);
    }
    else {
        ret = min(dist[en], dist[i.v] + i.c + rdist[i.u]);

        if (i.id == 4) {
            cout << (en == n ? "1 to N" : "N to 1") << '\n';
            cout << ret << '\n';
        }
    }

    /*if (i.id == 4) {
        cout << (en == n ? "1 to N" : "N to 1") << '\n';
        cout << ret << '\n';
    }*/

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    dijkstra(1, dist_1, g);
    dijkstra(n, dist_N, g);
    dijkstra(1, rdist_1, rg);
    dijkstra(n, rdist_N, rg);

    buildDAG(dist_1, dag_1, in_dag_1);
    buildDAG(dist_N, dag_N, in_dag_N);

    getBCC(dag_1, aEdge_1);
    getBCC(dag_N, aEdge_N);

    for (auto& i : aEdge_N)
        cout << i.first << ' ' << i.second << '\n';

    ll ans = dist_1[n] + dist_N[1];

    for (auto& i : e) {
        ll res = i.d;
        res += get(i, n, dist_1, rdist_N, in_dag_1, aEdge_1);
        res += get(i, 1, dist_N, rdist_1, in_dag_N, aEdge_N);
        if (i.id == 4) {
            //cout << get(i, n, dist_1, rdist_N, in_dag_1, aEdge_1) << '\n';
            //cout << get(i, 1, dist_N, rdist_1, in_dag_N, aEdge_N) << '\n';
        }
        ans = min(ans, res);
    }

    cout << (ans < INF ? ans : -1);
}