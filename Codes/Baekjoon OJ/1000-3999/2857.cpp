#include <iostream>
#include <cstring>
using namespace std;

int main() {
	bool check = false;
	for (int i = 0; i < 5; i++) {
		char name[11];
		scanf("%s", name);

		for (int l = strlen(name) - 1; l >= 2; l--) {
			if (name[l] == 'I' && name[l - 1] == 'B' && name[l - 2] == 'F') {
				printf("%d ", i + 1);

				check = true;
				break;
			}
		}
	}

	if (!check) printf("HE GOT AWAY!");
	
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