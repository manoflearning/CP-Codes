#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()

int n, a[101010];
vector<int> t[101010];
int minTime = 0;
int hasPotion[101010], leafCnt[101010];
int ans = 0;

void dfs(int v, int prv) {
    if (v != 1 && sz(t[v]) == 1) leafCnt[v]++;

    for (auto& i : t[v]) {
        if (i != prv) { 
            dfs(i, v);
            leafCnt[v] += leafCnt[i];
        }
    }
    
    int score = min(leafCnt[v], hasPotion[v]);
    leafCnt[v] -= score, ans += score;
}

int main() {
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    for (int v = 2; v <= n; v++) {
        if (sz(t[v]) == 1) minTime++;
    }
    for (int i = 1; i <= minTime; i++) {
        hasPotion[a[i]]++;
    }

    dfs(1, 0);

    cout << ans;
}