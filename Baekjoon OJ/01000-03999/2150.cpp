// Tarjan's strongly connected components algorithm
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 101010;

int n, m, label[MAXV], labelCnt;
int SCCnum[MAXV], SCCcnt, finished[MAXV];
vector<int> adj[MAXV];
stack<int> stk;
vector<vector<int>> SCC;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

int dfs(int v) {
	label[v] = labelCnt++;
	stk.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		// Unvisited node.
		if (label[next] == -1) ret = min(ret, dfs(next));
		// Visited but not yet classified as SCC. In other words, edge { v, next } is back edge.
		else if (!finished[next]) ret = min(ret, label[next]);
	}
	
	// If there is no edge to the ancestor node among itself and its descendants, find scc.
	if (ret == label[v]) {
		vector<int> vSCC;
		while (1) {
			int t = stk.top();
			stk.pop();

			vSCC.push_back(t);
			SCCnum[t] = SCCcnt;
			finished[t] = 1;

			if (t == v) break;
		}

		SCC.push_back(vSCC);
		SCCcnt++;
	}

	return ret;
}

void getSCC() {
	memset(label, -1, sizeof(label));

	for (int v = 1; v <= n; v++)
		if (label[v] == -1) dfs(v);
}

void print() {
	for (int i = 0; i < (int)SCC.size(); i++) 
		sort(SCC[i].begin(), SCC[i].end());

	sort(SCC.begin(), SCC.end());

	cout << (int)SCC.size() << '\n';

	for (int i = 0; i < (int)SCC.size(); i++) {
		for (auto& j : SCC[i]) cout << j << ' ';
		cout << -1 << '\n';
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	// Enter the absolute path of the local file input.txt, output.txt
	// Or just enter the "input.txt", "output.txt"
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	input();

	getSCC();

	print();

	return 0;
}