#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int line[100];

	for (int i = 0; i < n; i++) {
		int flag;
		scanf("%d", &flag);

		for (int l = i - 1; l >= flag; l--)
			line[l + 1] = line[l];

		line[flag] = i + 1;
	}

	for (int i = n - 1; i >= 0; i--)
		printf("%d ", line[i]);

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