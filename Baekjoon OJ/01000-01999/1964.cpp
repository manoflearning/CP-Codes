#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	 
	if (n == 1) printf("5");
	else printf("%d", ((long long int)3 * n * n + 5 * n + 2) / 2 % 45678);

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