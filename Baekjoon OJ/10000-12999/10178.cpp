#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a % b);
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