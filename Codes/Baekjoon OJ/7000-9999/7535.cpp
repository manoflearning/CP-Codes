#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXV = 2 * 2 * 1e3;

int dfsn[MAXV + 5], dCnt, sNum[MAXV + 5], sCnt;
bool finished[MAXV + 5];
vector<int> adj[MAXV + 5];
stack<int> stk;

void reset();
inline int trans(int x);
int dfs(int now);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T; cin >> T;

	for (int test = 1; test <= T; test++) {
		reset();

		int N, M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			adj[trans(-a)].push_back(trans(b));
			adj[trans(-b)].push_back(trans(a));

			a = -a, b = -b;
			adj[trans(-a)].push_back(trans(b));
			adj[trans(-b)].push_back(trans(a));
		}

		//scc
		for (int i = 0; i < 2 * N; i++)
			if (dfsn[i] == -1) dfs(i);
		
		//충족 가능성 판별
		bool yes = true;
		for (int i = 0; i < 2 * N; i += 2) {
			if (sNum[i] == sNum[i + 1]) {
				yes = false;
				break;
			}
		}

		//출력
		cout << "Scenario #" << test << ":\n";
		if (yes) cout << "No suspicious bugs found!\n";
		else cout << "Suspicious bugs found!\n";
		cout << '\n';
	}

	return 0;
}

void reset() {
	memset(dfsn, -1, sizeof(dfsn));
	dCnt = sCnt = 0;
	memset(finished, 0, sizeof(finished));
	for (int i = 0; i < MAXV + 5; i++)
		adj[i].clear();
}

inline int trans(int x) {
	return (x > 0) ? 2 * (x - 1) : 2 * (-x - 1) + 1;
}

int dfs(int now) {
	int ret = dfsn[now] = ++dCnt;

	stk.push(now);

	for (int next : adj[now]) {
		if (dfsn[next] == -1) ret = min(ret, dfs(next));
		else if (!finished[next]) ret = min(ret, dfsn[next]);
	}

	if (ret >= dfsn[now]) {
		while (true) {
			int t = stk.top();
			stk.pop();

			sNum[t] = sCnt;
			finished[t] = true;

			if (t == now) break;
		}
		sCnt++;
	}
	
	return ret;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 2-SAT
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////