#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char S[101];

int main() {
	scanf("%s", S);

	int sum = 0;

	for (int i = strlen(S) - 1; i >= 0; i--) {
		static int digit = 0;

		if (S[i] == ',') digit = 0;
		else {
			sum += (S[i] - '0') * pow(10, digit);
			digit++;
		}
	}

	printf("%d", sum);

	return 0;
}
/*
���� �ع�		: 
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////