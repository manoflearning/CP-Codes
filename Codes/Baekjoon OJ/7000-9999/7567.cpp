#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char plate[51];
	scanf("%s", plate);

	int sum = 10;

	int len = strlen(plate);
	for (int i = 1; i < len; i++) {
		if (plate[i] == plate[i - 1]) sum += 5;
		else sum += 10;
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