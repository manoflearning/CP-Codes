#include <iostream>
using namespace std;

int main() {
	int c, k, p;
	scanf("%d %d %d", &c, &k, &p);

	long long sum = 0;
	for (int i = 0; i <= c; i++)
		sum += k * i + p * i * i;

	printf("%lld", sum);

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