#include <iostream>
#include <cstring>
using namespace std;

char name[101];

int main() {
	scanf("%s", name);

	for (int i = 0; i < strlen(name); i++) {
		if (65 <= name[i] && name[i] <= 90)
			printf("%c", name[i]);
	}

	return 0;
}

/*
���� �ع�		: ���ڿ� ó��
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/