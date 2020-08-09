#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);

		int win_a = 0, win_b = 0;
		for (int i = 0; i < n; i++) {
			char a, b;
			scanf(" %c %c", &a, &b);

			if (a == 'R') {
				if (b == 'S') win_a++;
				else if (b == 'P') win_b++;
			}
			else if (a == 'S') {
				if (b == 'R') win_b++;
				else if (b == 'P') win_a++;
			}
			else if (a == 'P') {
				if (b == 'R') win_a++;
				else if (b == 'S') win_b++;
			}
		}

		if (win_a > win_b) printf("Player 1\n");
		else if (win_a < win_b) printf("Player 2\n");
		else printf("TIE\n");
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