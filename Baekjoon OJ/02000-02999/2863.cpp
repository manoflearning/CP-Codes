#include <iostream>
using namespace std;

int main() {
	double num[2][2];

	scanf("%lf %lf %lf %lf", &num[0][0], &num[0][1], &num[1][0], &num[1][1]);

	double max_num = 0;
	int flag;

	for (int i = 0; i < 4; i++) {
		if (num[0][0] / num[1][0] + num[0][1] / num[1][1] > max_num) {
			max_num = num[0][0] / num[1][0] + num[0][1] / num[1][1];
			flag = i;
		}

		int tmp = num[0][0];
		num[0][0] = num[1][0];
		num[1][0] = num[1][1];
		num[1][1] = num[0][1];
		num[0][1] = tmp;
	}

	printf("%d", flag);

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