#include <iostream>
using namespace std;

int main() {
	while (true) {
		int a[3];
		for (int i = 0; i < 3; i++)
			scanf("%d", &a[i]);

		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

		if (a[2] - a[1] == a[1] - a[0])
			printf("AP %d\n", a[2] + (a[2] - a[1]));
		else if (a[2] / a[1] == a[1] / a[0])
			printf("GP %d\n", a[2] * (a[2] / a[1]));
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