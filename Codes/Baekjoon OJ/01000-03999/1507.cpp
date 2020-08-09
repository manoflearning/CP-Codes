#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 20;

int N, dist[MAXV + 5][MAXV + 5], adj[MAXV + 5][MAXV + 5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int u = 1; u <= N; u++) {
		for (int v = 1; v <= N; v++) {
			cin >> dist[u][v];
			adj[u][v] = dist[u][v];
		}
	}

	bool cannot = false;

	for (int u = 1; u <= N; u++) {
		//v = u + 1�� ����: ����� �����̱⿡ u���� v������ �ִܰ�δ� v���� u������ �ִܰ�ο� ����
		for (int v = u + 1; v <= N; v++) {
			for (int k = 1; k <= N; k++) {
				if (k == u || k == v) continue;
				//� �� ����� �Ÿ��� ���� ���, �������� ���� ��ΰ� �ƴ� �������� �ִ� ��θ� ���Ѵ�. �װ��� �� ���� ���� ���� ��θ� �����ϱ� �����̴�.
				if (dist[u][v] == dist[u][k] + dist[k][v]) {
					adj[u][v] = adj[v][u] = 0;
				}
				//dist[u][v]���� dist[u][k] + dist[k][v]�� �۴ٸ�, dist[u][v]�� �ִܰŸ��� �ƴ� ��. ���� ���.
				else if (dist[u][v] > dist[u][k] + dist[k][v]) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	
	int ans = 0;
	for (int u = 1; u <= N; u++) {
		for (int v = u + 1; v <= N; v++) {
			ans += adj[u][v];
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �÷��̵� �ͼ� �˰����ΰ�..?
������ ������		: ��� ���� �ֿ� ����, �� �ִ� �Ÿ��� �ٸ� ���� ���� �ִܰŸ��� ������ ǥ�� �����ϴٸ� ������ ���� ������ �Ѵ�.
�ð����⵵		: O(|V|^3)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////