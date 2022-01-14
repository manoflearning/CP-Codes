#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

const int MAXN = 1e5 + 5;

int n, ans, adj[MAXN], a[MAXN], b[MAXN];

void init() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> adj[i];
    }
}

void dfs(int v) {
    a[v] = 1;
    
    int u = adj[v];
    
    if (a[u] && !b[u]) {
        for (int i = u; i != v; i = adj[i]) ans--;
        ans--;
    }
    if (!a[u]) dfs(u);
    
    b[v] = 1;
}

void f() {
    for (int i = 1; i <= n; i++) {
        if (!a[i]) dfs(i);
    }
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tc; cin >> tc;
	
	while (tc--) {
	    init();
	    
	    input();
	    
	    ans = n;
	    
	    f();
	    
	    cout << ans << '\n';
	}
	
	return 0;
}
