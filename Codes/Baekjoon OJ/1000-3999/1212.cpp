#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char num[333335];

	scanf("%s", num);

	if (num[0] == '0') printf("0");
	else if (num[0] == '1') printf("1");
	else if (num[0] == '2') printf("10");
	else if (num[0] == '3') printf("11");
	else if (num[0] == '4') printf("100");
	else if (num[0] == '5') printf("101");
	else if (num[0] == '6') printf("110");
	else if (num[0] == '7') printf("111");

	int len = strlen(num);
	for (int i = 1; i < len; i++) {
		if (num[i] == '0') printf("000");
		else if (num[i] == '1') printf("001");
		else if (num[i] == '2') printf("010");
		else if (num[i] == '3') printf("011");
		else if (num[i] == '4') printf("100");
		else if (num[i] == '5') printf("101");
		else if (num[i] == '6') printf("110");	
		else if (num[i] == '7') printf("111");
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