#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int l = 0; l <= i; l++) sum += i + l;
	}

	printf("%d", sum);

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