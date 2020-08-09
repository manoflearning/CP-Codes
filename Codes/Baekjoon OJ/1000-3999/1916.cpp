#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 1000;

vector<pair<int, int>> bus[MAX + 1];
int path[MAX + 1];

void shortestPath(int start, int end);

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;

		bus[s].push_back({ v, e });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++)
		path[i] = INT_MAX;

	shortestPath(start, end);

	return 0;
}

void shortestPath(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int v = pq.top().first, e = pq.top().second;

		if (e == end) {
			cout << v;
			break;
		}

		if (v < path[e]) {
			path[e] = v;

			for (int i = 0; i < bus[e].size(); i++)
				pq.push({ v + bus[e][i].first, bus[e][i].second });
		}

		pq.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���ͽ�Ʈ�� �˰���
���� ���		: ���� �ƴ� ����ġ�� �׷������� �� �������κ��� ����� ��� ���������� �ִܰŸ��� ���� �� �ִ�.
������ ������		:
���� ����		: 1. ��Ÿ�ӿ���. �迭�� ũ�⸦ MAX + 1�� �����ؾ� ����
				  2.
*/////////////////////////////////////////////////////////////////////