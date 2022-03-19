#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int n, k;
		scanf("%d %d", &n, &k);

		queue<int> soldiers;

		for (int i = 2; i <= n; i++)
			soldiers.push(i);
		
		int count = 0;
		while (soldiers.size() > 2) {
			count++;
			
			if (count % k != 0) soldiers.push(soldiers.front());
			
			soldiers.pop();
		}

		if (soldiers.front() <= soldiers.back())
			printf("%d %d\n", soldiers.front(), soldiers.back());
		else
			printf("%d %d\n", soldiers.back(), soldiers.front());
	}

	return 0;
}
/*
���� �ع�		: ť�� ���԰� ������ ����ð��� �����ϴٴ� ���� �̿�.
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////