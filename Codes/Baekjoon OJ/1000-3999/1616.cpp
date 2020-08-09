#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAXV = 5 * 1e6;

int K, M, KpowM, res[2 * MAXV + 5], rTop;
int** adj, aTop[MAXV + 5];

void DFS(int v);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K >> M;
	
	//���� ó��
	if (M == 1) {
		for (int v = 0; v < K; v++)
			cout << v << ' ';
		return 0;
	}
	
	KpowM = pow(K, M);

	//�׷��� ���� �Ҵ�
	adj = new int*[KpowM / K + 5];
	for (int i = 0; i < KpowM / K + 5; i++)
		adj[i] = new int[K];
	
	//�׷��� �����: k���� ����
	for (int UtoV = 0; UtoV < KpowM; UtoV++) {
		int u = UtoV / K, v = UtoV % (KpowM / K);
		
		adj[u][aTop[u]++] = v;
	}

	//���Ϸ� ȸ�� ã��
	DFS(0);

	//���� ó��
	if (rTop - 1 != KpowM) {
		cout << -1;
		return 0;
	}
	
	//���
	for (int v = rTop - 2; v >= 0; v--)
		cout << res[v] % K << ' ';

	//�Ҵ� ����
	for (int i = 0; i < KpowM / K + 5; i++)
		delete[] adj[i];
	delete[] adj;

	return 0;
}

void DFS(int v) {
	while (aTop[v] > 0) {
		DFS(adj[v][--aTop[v]]);
	}
	res[rTop++] = v;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���Ϸ� ȸ��, k���� ����
������ ������		:
�ð����⵵		:
���� ����		: 1.
				  2.
*/////////////////////////////////////////////////////////////////////