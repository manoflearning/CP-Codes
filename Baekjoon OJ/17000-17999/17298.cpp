#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int arr[MAX];
int ans[MAX];
stack<int> nge;

int main() {
	memset(ans, -1, sizeof(ans));

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		while (!nge.empty() && arr[nge.top()] < arr[i]) {
			ans[nge.top()] = arr[i];
			nge.pop();
		}

		nge.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ������ Ȱ��. ���� ���� ������ ������������ ���ĵ�.
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////