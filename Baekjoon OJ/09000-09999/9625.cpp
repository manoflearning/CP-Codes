#include <iostream>
using namespace std;

int k;

void count(long long int a, long long int b, int buttoner);

int main() {
	scanf("%d", &k);

	count(1, 0, 0);
}

void count(long long int a, long long int b, int buttoner) {
	//base case
	if (buttoner == k) {
		printf("%lld %lld", a, b);
		return;
	}
	//
	long long int s_a = a, s_b = b;

	a = 0;

	a += s_b;
	b += s_a;

	count(a, b, buttoner + 1);
}

/*
���� �ع�		:
���� ���		:
������ ������	:
���� ����		: 1. base case�� ���� ��� �Լ��� ȣ���� �Ͼ
				  2.
*/
//////////////////////////////////////////////////////////////////////