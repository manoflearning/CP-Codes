#include <iostream>
using namespace std;

int main() {
	int a[10], b[10];
	int win_a = 0, win_b = 0;

	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &b[i]);

		if (a[i] > b[i]) win_a++;
		else if (a[i] < b[i]) win_b++;
	}

	if (win_a > win_b) printf("A");
	else if (win_a < win_b) printf("B");
	else printf("D");

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