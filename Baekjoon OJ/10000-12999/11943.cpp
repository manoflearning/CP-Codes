#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	int ans = (a + d < b + c) ? a + d : b + c;

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