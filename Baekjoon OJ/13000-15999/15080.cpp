#include <iostream>
using namespace std;

int main() {
	int h1, m1, s1, h2, m2, s2;
	char pass;
	scanf("%d %c %d %c %d %d %c %d %c %d", &h1, &pass, &m1, &pass, &s1, &h2, &pass, &m2, &pass, &s2);

	int ans = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);

	if (ans < 0) ans += 24 * 3600;

	printf("%d", ans);

	return 0;
}
/*
���� �ع�		: 
���� ���		:
������ ������		:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////