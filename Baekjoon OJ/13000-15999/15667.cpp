#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; ; i++) {
		if (1 + i + i * i == n) {
			printf("%d", i);
			break;
		}
	}

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