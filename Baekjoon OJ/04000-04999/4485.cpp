#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 125;

struct bb {
	int y;
	int x;
	int v;
};

struct cmp {
	bool operator() (bb a, bb b) {
		return a.v > b.v;
	}
};

int n;
int graph[MAX][MAX];
int path[MAX][MAX];

void shortestPath();

int main() {
	for (int test = 1; ; test++) {
		//reset
		for (int i = 0; i < MAX; i++) {
			for (int l = 0; l < MAX; l++) {
				path[i][l] = INT_MAX;
			}
		}
		//
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int l = 0; l < n; l++) {
				cin >> graph[i][l];
			}
		}
		//
		shortestPath();

		cout << "Problem " << test << ": " << path[n - 1][n - 1] << '\n';
	}

	return 0;
}

void shortestPath() {
	priority_queue<bb, vector<bb>, cmp> pq;

	pq.push({ 0, 0, graph[0][0] });

	while (!pq.empty()) {
		int y = pq.top().y, x = pq.top().x, v = pq.top().v;

		if (v < path[y][x]) {
			path[y][x] = v;

			if (y > 0) pq.push({ y - 1, x, v + graph[y - 1][x] });
			if (x > 0) pq.push({ y, x - 1, v + graph[y][x - 1] });
			if (y < n - 1) pq.push({ y + 1, x, v + graph[y + 1][x] });
			if (x < n - 1) pq.push({ y, x + 1, v + graph[y][x + 1] });
		}

		pq.pop();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �������, ���ͽ�Ʈ�� �˰�����
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////