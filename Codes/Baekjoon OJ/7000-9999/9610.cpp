#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;

	for (int test = 0; test < t; test++) {
		int x, y;
		scanf("%d %d", &x, &y);

		if (x > 0 && y > 0) Q1++;
		else if (x < 0 && y > 0) Q2++;
		else if (x < 0 && y < 0) Q3++;
		else if (x > 0 && y < 0) Q4++;
		else AXIS++;
	}
	printf("Q1: %d\n", Q1);
	printf("Q2: %d\n", Q2);
	printf("Q3: %d\n", Q3);
	printf("Q4: %d\n", Q4);
	printf("AXIS: %d\n", AXIS);

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