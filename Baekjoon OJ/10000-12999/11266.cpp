#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int MAXV = 1e4;

int dfsn[MAXV + 5], dCnt;
vector<int> adj[MAXV + 5];
map<int, int> aPoint;

int dfs(int v, int prv = -1);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dfsn, -1, sizeof(dfsn));

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//dfs Ʈ��
	for (int v = 1; v <= N; v++)
		if (dfsn[v] == -1) dfs(v);

	//���
	cout << aPoint.size() << '\n';

	for (map<int, int>::iterator v = aPoint.begin(); v != aPoint.end(); v++) 
		cout << v->second << ' ';

	return 0;
}

int dfs(int v, int prv) {
	int ret = dfsn[v] = ++dCnt;
	
	int child = 0;
	for (int next : adj[v]) {
		if (next == prv) continue;

		//Ʈ�� ����
		if (dfsn[next] == -1) {
			child++;
			int nRet = dfs(next, v);

			if (prv == -1 && child >= 2)
				aPoint.insert({ v, v });
			else if (prv != -1 && nRet >= dfsn[v])
				aPoint.insert({ v, v });
			ret = min(ret, nRet);
		}
		//������ ����
		else ret = min(ret, dfsn[next]);
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���� ���� ���, ������
������ ������		: 
�ð����⵵		: O(|V| + |E|)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////