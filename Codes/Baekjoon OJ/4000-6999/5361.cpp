#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int a, b, c, d, e;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

		double sum = 0;
		sum += 350.34 * a;
		sum += 230.90 * b;
		sum += 190.55 * c;
		sum += 125.30 * d;
		sum += 180.90 * e;

		printf("$%.2lf\n", sum);
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