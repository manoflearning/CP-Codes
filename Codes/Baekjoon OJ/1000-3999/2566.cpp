#include <iostream>
using namespace std;

int main() {
	int arr[9][9];
	int flag_y, flag_x, max_num = 0;

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++) {
			scanf("%d", &arr[y][x]);

			if (arr[y][x] > max_num) {
				max_num = arr[y][x];
				flag_y = y + 1;
				flag_x = x + 1;
			}
		}

	printf("%d\n%d %d", max_num, flag_y, flag_x);

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