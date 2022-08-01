#include <iostream>
#include <vector>
using namespace std;

const int MAX = 500;

vector<int> graph[MAX + 1];
bool visitedNode[MAX + 1], visitedLink[MAX + 1][MAX + 1];

bool isThisTree(int root);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int test = 1; ; test++) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (isThisTree(i)) count++;

			for (int l = 1; l <= n; l++) visitedNode[i] = false;
		}
			

		cout << "Case " << test << ": ";
		if (count == 0) cout << "No trees.\n";
		else if (count == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << count << " trees.\n";

		//�ʱ�ȭ
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
			visitedNode[i] = false;
		}
	}

	return 0;
}

bool isThisTree(int root) {
	if (visitedNode[root]) return false;

	visitedNode[root] = true;

	bool ret = true;

	for (int i = 0; i < graph[root].size(); i++) {
		int go = graph[root][i];

		if (visitedLink[root][go]) continue;

		visitedLink[root][go] = true;
		visitedLink[go][root] = true;
		
		if (!isThisTree(go)) ret = false;
		
		visitedLink[root][go] = false;
		visitedLink[go][root] = false;
	}

	return ret;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: 
���� ���		: �� ������ Ʈ���� ��Ʈ�� �����ϰ�, ��Ʈ�� �������� ����� ��忡 ��� �湮. �ѹ� �����Դ� ���� �ٽ� �������� ����, �ѹ� �湮�� ��忡 �ٽ� �湮�ϰ� �Ǹ� �� ������ ��Ʈ�� �� �׷����� Ʈ���� �ƴ�. �̸� ��� ������ ����.
������ ������		: 
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////