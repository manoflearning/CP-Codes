#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		char num[62];

		scanf("%s", num);

		if ((num[strlen(num) - 1] - '0') % 2 == 0) printf("even\n");
		else printf("odd\n");
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