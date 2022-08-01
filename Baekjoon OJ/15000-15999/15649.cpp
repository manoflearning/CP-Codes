#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9];
vector<int> arr;

void backtrack();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	
	backtrack();

	return 0;
}

void backtrack() {
	//base case
	if (arr.size() == m) {
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		arr.push_back(i);

		backtrack();

		visited[i] = false;
		arr.pop_back();
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ��Ʈ��ŷ
���� ���		: ������ ù��° ���� ���ϰ�, ù��° ���� �����ϰ�(�ߺ� ����), �ι�° ���� ���ϰ�, �� ��������� �ݺ�
������ ������		: 
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////