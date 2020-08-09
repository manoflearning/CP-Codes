#include <iostream>
using namespace std;

int n;


int main() {
	scanf("%d", &n);

	char room[100][100];
	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			scanf(" %c", &room[i][l]);
			//cin >> room[i][l];
		}

	int ans_x = 0, ans_y = 0;

	for (int i = 0; i < n; i++) {
		bool swit = true;
		int count = 0;

		for (int l = 0; l < n; l++) {
			if (room[i][l] == '.') count++;
			else if (room[i][l] == 'X') {
				count = 0;
				swit = true;
			}

			if (count >= 2 && swit) {
				ans_x++;
				swit = false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		bool swit = true;
		int count = 0;

		for (int l = 0; l < n; l++) {
			if (room[l][i] == '.') count++;
			else if (room[l][i] == 'X') {
				count = 0;
				swit = true;
			}

			if (count >= 2 && swit) {
				ans_y++;
				swit = false;
			}
		}
	}

	printf("%d %d", ans_x, ans_y);

	return 0;
}
/*
문제 해법		: 
접근 방식		:
결정적 깨달음	: 
오답 원인		: 1. 버퍼
				  2.
*/
//////////////////////////////////////////////////////////////////////
