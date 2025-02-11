#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Query { int x, y, r; };
struct wv { int w, v; };

int K, N;
vector<Query> q;
int dist[44][44];

void input() {
    cin >> K >> N;
    q.resize(N);
    for (auto& i : q) {
        cin >> i.x >> i.y >> i.r;
    }
}

void constructGraph() {
    for (int i = 0; i < 44; i++) {
        for (int j = 0; j < 44; j++) {
            if (i ^ j) dist[i][j] = INF;
        }
    }

    for (int i = 0; i < K; i++) {
        dist[i + 1][i] = 0; // psum[i + 1] - psum[i] >= 0
        dist[i][i + 1] = 1; // psum[i + 1] - psum[i] <= 1
    }

    for (auto& i : q) {
        dist[i.x - 1][i.y] = min(dist[i.x - 1][i.y], i.r);
        dist[i.y][i.x - 1] = min(dist[i.y][i.x - 1], -i.r);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    input();

    constructGraph();

    for (int k = 0; k <= K; k++) {
        for (int u = 0; u <= K; u++) {
            for (int v = 0; v <= K; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    for (int i = 0; i <= K; i++) {
        if (dist[i][i] < 0) {
            cout << "NONE";
            return 0;
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << (dist[0][i] - dist[0][i - 1] ? '#' : '-');
    }
}