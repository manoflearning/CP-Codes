#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a = 2001, b = 2001;

	for (int i = 0; i < 3; i++) {
		int sam;
		scanf("%d", &sam);

		a = min(a, sam);
	}
	for (int i = 0; i < 2; i++) {
		int sam;
		scanf("%d", &sam);

		b = min(b, sam);
	}

	printf("%d", a + b - 50);
}
/*
문제 해법		: 
접근 방식		:
결정적 깨달음		:
오답 원인		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////