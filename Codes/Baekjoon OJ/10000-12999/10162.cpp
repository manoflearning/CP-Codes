#include <iostream>
using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	if (n % 10 != 0) printf("-1");
	else {
		int a = n / 300;
		n %= 300;

		int b = n / 60;
		n %= 60;

		int c = n / 10;
		n %= 10;

		printf("%d %d %d", a, b, c);
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