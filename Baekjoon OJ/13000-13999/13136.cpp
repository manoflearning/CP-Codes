#include <iostream>
using namespace std;

int main() {
	int x, y, flag;

	scanf("%d %d %d", &x, &y, &flag);

	long long ans = 1;

	if (x % flag != 0) ans *= x / flag + 1;
	else ans *= x / flag;
	
	if (y % flag != 0) ans *= y / flag + 1;
	else ans *= y / flag;

	printf("%lld", ans);

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