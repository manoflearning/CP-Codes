#include <iostream>
using namespace std;

int main() {
	int y, m, d;
	int fy, fm, fd;

	scanf("%d %d %d", &y, &m, &d);
	scanf("%d %d %d", &fy, &fm, &fd);

	int ans1 = fy - y;
	if (fm == m && fd < d) ans1--;
	else if (fm < m) ans1--;

	int ans2 = fy - y + 1;
	int ans3 = ans2 - 1;
	
	printf("%d\n%d\n%d", ans1, ans2, ans3);

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