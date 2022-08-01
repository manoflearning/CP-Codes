#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 32000;

int N;
vector<int> adj[MAXV + 5], indeg(MAXV + 5), result;

void topological_sort();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}

	topological_sort();

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	return 0;
}

void topological_sort() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int v = 1; v <= N; v++)
		if (indeg[v] == 0) pq.push(v);

	for (int i = 0; i < N; i++) {
		int v = pq.top();
		pq.pop();

		result.push_back(v);

		for (int next : adj[v]) {
			indeg[next]--;
			if (indeg[next] == 0) pq.push(next);
		}
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���� ����
������ ������		: ť ��� �켱����ť�� Ȱ���Ͽ� ���� ������ �����Ѵ�.
�ð����⵵		: O(|E|lg|E|)
���� ����		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////