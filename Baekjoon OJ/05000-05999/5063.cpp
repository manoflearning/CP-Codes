#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int r, e, c;
		scanf("%d %d %d", &r, &e, &c);

		if (e - c > r) printf("advertise\n");
		else if (e - c < r) printf("do not advertise\n");
		else printf("does not matter\n");
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