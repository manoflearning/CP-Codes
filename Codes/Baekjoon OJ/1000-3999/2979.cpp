#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int time[101] = { 0, };

	for (int i = 0; i < 3; i++) {
		int start, end;
		scanf("%d %d", &start, &end);

		for (int l = start; l < end; l++)
			time[l]++;
	}

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (time[i] == 1) sum += a;
		else if (time[i] == 2) sum += 2 * b;
		else if (time[i] == 3) sum += 3 * c;
	}

	printf("%d", sum);

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