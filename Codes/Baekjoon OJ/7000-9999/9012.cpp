#include <iostream>
#include <vector>
using namespace std;

int top = 0;

int main() {
	int t;
	scanf("%d", &t);
	getchar();

	for (int test = 0; test < t; test++) {
		bool check = true;

		while (1) {
			char sam;
			scanf("%c", &sam);

			if (sam == '(') top++;
			else if (sam == ')') {
				if (top == 0) check = false;
				else top--;
			}
			else break;
		}

		if (check && top == 0) printf("YES\n");
		else printf("NO\n");

		top = 0;
	}

	return 0;
}
/*
문제 해법		: 
접근 방식		: 
결정적 깨달음	: 
오답 원인		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////