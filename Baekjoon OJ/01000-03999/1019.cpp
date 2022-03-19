#include <iostream>
#include <cmath>
using namespace std;

int cnt[10];

void count_1to9(int num, int flag);
long long int sum_count(int num);

int main() {
	int n;
	scanf("%d", &n);

	int flag;
	for (flag = 0; pow(10, flag) <= n; flag++);

	count_1to9(n, --flag);

	long long int cnt0 = sum_count(n);
	for (int i = 1; i < 10; i++)
		cnt0 -= cnt[i];
	cnt[0] = cnt0;

	for (int i = 0; i < 10; i++)
		printf("%d ", cnt[i]);

	return 0;
}

void count_1to9(int num, int flag) {
	//base case
	if (flag == 0) {
		for (int i = 1; i <= num; i++)
			cnt[i]++;
		return;
	}
	//
	int key = pow(10, flag);
	int n = num / key;

	if (n == 0) count_1to9(num, flag - 1);
	else {
		for (int i = 1; i < n; i++)
			cnt[i] += key;
		cnt[n] += num - n * key + 1;

		int sam = n * key / 10 * flag;
		for (int i = 1; i < 10; i++)
			cnt[i] += sam;

		count_1to9(num - n * key, flag - 1);
	}
}

long long int sum_count(int num) {
	//base case
	if (num <= 9) return num;
	//
	int flag;
	for (flag = 0; pow(10, flag) <= num; flag++);
	flag--;

	long long int sum = sum_count(pow(10, flag) - 1) + ((long long int)flag + 1) * (num - (pow(10, flag) - 1));

	return sum;
}
/*
���� �ع�		: 1 ~ 99...999������ �� 1���� 9������ ����Ƚ���� ���ϴ� ���� �ͳ������� ������. 0 ~ 99...999�� �������� ���� �����ϰ�, ���ȣ���� ����� n������ �� �� 1 ~ 9 ������ ���� Ƚ���� ����. ��ü ���� ���� Ƚ���� ���ϴ� �Լ��� ���� ���� ��, ��ü ����Ƚ������ 1~9������ ���� Ƚ���� �� -> 0�� ���� Ƚ�� ����.
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
//O(n)�� ���α׷�, ����� X, ���ڵ� ¥�� ���� ����� �ڵ� O
/*
#include <iostream>
using namespace std;

long long int sum_count(int num);

int main() {
	while (true) {
		int n;
		scanf("%d", &n);

		int cnt[10];
		for (int i = 0; i < 10; i++)
			cnt[i] = 0;

		for (int i = 1; i <= n; i++) {
			for (int l = 1; l <= i; l *= 10) {
				cnt[i % (l * 10) / l]++;
			}
		}

		int sum = 0;
		for (int i = 0; i < 10; i++) {
			printf("%d ", cnt[i]);
			sum += cnt[i];
		}
		printf("\n%d %lld\n", sum, sum_count(n));
	}

	return 0;
}

long long int sum_count(int num) {
	//base case
	if (num <= 9) return num;
	//
	int flag;
	for (flag = 0; pow(10, flag) <= num; flag++);
	flag--;

	int sum = sum_count(pow(10, flag) - 1) + (flag + 1) * (num - (pow(10, flag) - 1));

	return sum;
}
*/