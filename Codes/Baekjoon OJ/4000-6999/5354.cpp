#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			if (i == 0 || i == n - 1)
				for (int l = 0; l < n; l++) printf("#");
			else {
				printf("#");
				for (int l = 0; l < n - 2; l++) printf("J");
				printf("#");
			}

			printf("\n");
		}

		printf("\n");
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