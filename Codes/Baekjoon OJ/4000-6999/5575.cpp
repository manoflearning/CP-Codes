#include <iostream>
using namespace std;

int main() {
	for (int test = 0; test < 3; test++) {
		int s_h, s_m, s_s;
		scanf("%d %d %d", &s_h, &s_m, &s_s);

		int e_h, e_m, e_s;
		scanf("%d %d %d", &e_h, &e_m, &e_s);

		int sum = (e_h * 3600 + e_m * 60 + e_s) - (s_h * 3600 + s_m * 60 + s_s);

		printf("%d %d %d\n", sum / 3600, sum % 3600 / 60, sum % 60);
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