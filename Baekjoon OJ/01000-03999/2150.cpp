#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXV = 1e4;

int N, cnt = 1, dfsn[MAXV + 5], cntSCC, sn[MAXV + 5];
vector<int> adj[MAXV + 5];
vector<vector<int>> SCC;
stack<int> S;
bool finished[MAXV + 5];

int dfs(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	//dfs ���д� Ʈ�� ����
	for (int v = 1; v <= N; v++)
		if (dfsn[v] == 0) dfs(v);

	sort(SCC.begin(), SCC.end());

	//���
	cout << cntSCC << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int v : SCC[i])
			cout << v << ' ';
		cout << "-1\n";
	}

	return 0;
}

int dfs(int v) {
	//�湮 ������ �������� labeled
	dfsn[v] = cnt++;
	S.push(v);

	int result = dfsn[v];
	for (int next : adj[v]) {
		//visited�� ����
		if (dfsn[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	//���� ��忡�Է� ���ϴ� ������ ���� ��, v�� ��Ʈ�� �ϴ� ����Ʈ���� SCC
	if (result == dfsn[v]) {
		vector<int> vSCC;

		while (true) {
			int t = S.top();
			S.pop();
			vSCC.push_back(t);
			finished[t] = true;
			sn[t] = cntSCC;
			if (t == v) break;
		}

		sort(vSCC.begin(), vSCC.end());

		SCC.push_back(vSCC);
		cntSCC++;
	}

	return result;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���� ���� ���
������ ������		: 
�ð����⵵		: O(|V| + |E|)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////