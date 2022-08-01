#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXV = 2 * 1e4;

int N, color[MAXV + 5];
vector<int> adj[MAXV + 5];
bool YES;

void dfs(int now, bool c = false);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	while (T--) {
		YES = true;
		memset(color, -1, sizeof(color));
		for (int i = 0; i < MAXV + 5; i++)
			adj[i].clear();

		//����
		int M;
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		//dfs
		for (int v = 1; v <= N; v++)
			if (color[v] == -1) dfs(v);

		//���
		if (YES) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

void dfs(int now, bool c) {
	color[now] = c;

	for (int next : adj[now]) {
		//���� ������ ���� ������ ���ؼ��� dfs ����
		if (color[next] == -1) dfs(next, !c);
		//������ �ִٸ� �ߺ� ���� Ȯ��
		else if (color[next] == color[now]) YES = false;
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: dfs
������ ������		: 
�ð����⵵		: O(|V| + |E|)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////