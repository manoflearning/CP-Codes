#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char word[10001];
	scanf("%s", word);

	int len = strlen(word);

	int ans1 = 0, ans2 = 0;
	for (int i = 1; i < len - 1; i++) {
		if (word[i] == 'O') {
			if (word[i - 1] == 'J' && word[i + 1] == 'I') ans1++;
			else if (word[i - 1] == 'I' && word[i + 1] == 'I') ans2++;
		}
	}

	printf("%d\n%d", ans1, ans2);

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