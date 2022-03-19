#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long int> country;

int main() {
	//input
	scanf("%d", &n);
	country.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &country[i]);
	}
	scanf("%d", &m);
	//
	sort(country.begin(), country.end());
	for (int i = 1; i < n; i++) {
		country[i] += country[i - 1];
	}
	//
	bool flag = true;
	if (m >= country[n - 1]) {
		printf("%d", country[n - 1] - country[n - 2]);
		flag = false;
	}
	if (flag) {
		for (int i = n - 2; i >= 1; i--) {
			if (m >= country[i] + (n - 1 - i) * (country[i] - country[i - 1])) {
				printf("%d", (m - country[i]) / (n - 1 - i));
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		if ((double)m / n > country[0]) 
			printf("%d", (m - country[0]) / (n - 2));
		else
			printf("%d", m / n);
	}
	
	return 0;
}

/*
���� �ع�		: ������ ������ ���� �ð� ���ѿ� �ɸ��� �ʴ� ���� Ž��
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/