#include <iostream>
using namespace std;

int main() {
	int l, a, b, c, d;
	
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	int day1 = (a % c == 0) ? a / c : a / c + 1;
	int day2 = (b % d == 0) ? b / d : b / d + 1;
	
	printf("%d", l - ((day1 > day2) ? day1 : day2));

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