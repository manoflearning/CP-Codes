#include <iostream>
using namespace std;

int main() {
	int a[3];

	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i]);

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		int sam;
		scanf("%d", &sam);

		if (a[i] < sam) ans += sam - a[i];
	}

	printf("%d", ans);

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