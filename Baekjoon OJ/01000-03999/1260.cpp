#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;

vector<int> graph[MAX + 1];
bool visited[MAX + 1];

void dfs(int node);
void bfs(int node);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//�Է�
	int n, m, v;
	cin >> n >> m >> v;
	//�Է� �� �׷��� ����
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//���� ��ȣ�� ���� ���� ���� �湮�ϱ� ����, ����
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	//dfs
	dfs(v);
	cout << '\n';
	//bfs
	memset(visited, 0, sizeof(visited));
	bfs(v);

	return 0;
}

void dfs(int node) {
	visited[node] = true;
	cout << node << ' ';

	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) continue;

		dfs(graph[node][i]);
	}
}
void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		cout << q.front() << ' ';

		for (int i = 0; i < graph[q.front()].size(); i++)
			if (!visited[graph[q.front()][i]]) {
				q.push(graph[q.front()][i]);
				visited[graph[q.front()][i]] = true;
			}

		q.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: dfs�� bfs
���� ���		: dfs�� bfs�� �����Ѵ�
������ ������		:
���� ����		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////