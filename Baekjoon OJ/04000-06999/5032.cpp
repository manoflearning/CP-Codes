#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	scanf("%d %d %d", &e, &f, &c);

	int empty = e + f;
	int ans = 0;
	while (empty >= c) {
		int flag = empty / c;

		empty %= c;
		empty += flag;
		ans += flag;
	}

	printf("%d", ans);

	return 0;
}
/*
���� �ع�		: 
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////