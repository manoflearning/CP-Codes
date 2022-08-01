#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001][2];

int bfs(int s_y, int s_x);

int main() {
	cin >> n >> m;

	for (int y = 1; y <= n; y++) {
		string v;
		cin >> v;

		for (int x = 1; x <= m; x++)
			if (v[x - 1] == '1') map[y][x] = 1;
	}

	cout << bfs(1, 1);

	return 0;
}

int bfs(int s_y, int s_x) {
	struct b {
		int y;
		int x;
		bool crash;
		int c;
	};

	queue<b> q;
	q.push({ s_y, s_x, true, 1 });
	visited[s_y][s_x][true] = true;

	int ret = -1;
	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, c = q.front().c;
		bool crash = q.front().crash;

		if (y == n && x == m) {
			ret = c;
			break;
		}

		if (crash) {
			if (y > 1 && map[y - 1][x] == 1 && !visited[y - 1][x][false]) {
				q.push({ y - 1, x, false, c + 1 });
				visited[y - 1][x][false] = true;
			}
			if (y < n && map[y + 1][x] == 1 && !visited[y + 1][x][false]) {
				q.push({ y + 1, x, false, c + 1 });
				visited[y + 1][x][false] = true;
			}
			if (x > 1 && map[y][x - 1] == 1 && !visited[y][x - 1][false]) {
				q.push({ y, x - 1, false, c + 1 });
				visited[y][x - 1][false] = true;
			}
			if (x < m && map[y][x + 1] == 1 && !visited[y][x + 1][false]) {
				q.push({ y, x + 1, false, c + 1 });
				visited[y][x + 1][false] = true;
			}
		}
		if (y > 1 && map[y - 1][x] == 0 && !visited[y - 1][x][crash]) {
			q.push({ y - 1, x, crash, c + 1 });
			visited[y - 1][x][crash] = true;
		}
		if (y < n && map[y + 1][x] == 0 && !visited[y + 1][x][crash]) {
			q.push({ y + 1, x, crash, c + 1 });
			visited[y + 1][x][crash] = true;
		}
		if (x > 1 && map[y][x - 1] == 0 && !visited[y][x - 1][crash]) {
			q.push({ y, x - 1, crash, c + 1 });
			visited[y][x - 1][crash] = true;
		}
		if (x < m && map[y][x + 1] == 0 && !visited[y][x + 1][crash]) {
			q.push({ y, x + 1, crash, c + 1 });
			visited[y][x + 1][crash] = true;
		}

		q.pop();
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: bfs�� �ִܰŸ� ���ϱ�
���� ���		: ť�� ����ü������ ����. ����ü���� ��ǥ��, ���� �μ� ���� �ִ��� ����, ���ݱ��� �󸶳� �Դ����� ���ΰ� ���ڿ���� ����.
������ ������		: 
���� ����		: 1. visited �迭�� crash �������� �����ؾ� ��. crash�� ����ؼ� Ư�� ������ �ִܰŸ��� ���� ��, crash�� ������� �ʰ����� (n, m)�� �������� ���ϴ� �� ���� �κ� ������ �������� ���ϱ� ����.
				  2.
*/////////////////////////////////////////////////////////////////////