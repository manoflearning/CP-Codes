#include <iostream>
using namespace std;

int main() {
	printf("n e\n- -----------\n");
	
	double flag = 1, sum = 1;
	printf("0 1\n1 2\n2 2.5\n3 2.666666667\n4 2.708333333\n");
	for (int i = 1; i < 10; i++) {
		flag *= i;
		sum += 1 / flag;

		if (i >= 5) printf("%d %.9lf\n", i, sum);
	}

	return 0;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음		: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////