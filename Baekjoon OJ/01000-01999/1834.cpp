#include <iostream>
using namespace std;

int main() {
	long long int n;
	scanf("%lld", &n);

	long long int sum = 0;

	for (int flag = 1; flag < n; flag++)
		sum += flag * n + flag;

	printf("%lld", sum);

	return 0;
}
/*
���� �ع�		: ���� ����
���� ���		:
������ ������		:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////