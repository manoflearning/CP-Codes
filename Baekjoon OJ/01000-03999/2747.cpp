/*
���� �ع�		: ���� ���α׷���
���� ���		: 
������ ������	: 
���� ����		: 1. 
				  2.
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> dp;

int fibonacci(int x);

int main() {
	int n;
	scanf("%d", &n);

	dp.resize(n + 1, -1);

	printf("%d", fibonacci(n));
}

int fibonacci(int x) {
	if (dp[x] != -1) return dp[x];

	if (x == 1) return 1;
	if (x == 2) return 1;

	dp[x] = fibonacci(x - 1) + fibonacci(x - 2);

	return dp[x];
}