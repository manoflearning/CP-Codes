#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int b[100];

	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	printf("%d ", b[0]);
	for (int i = 1; i < n; i++)
		printf("%d ", b[i] * (i + 1) - b[i - 1] * i);

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