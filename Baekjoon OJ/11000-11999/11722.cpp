#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

vector<int> dp(1);

int main() {
	scanf("%d", &n);

	arr.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = 1;

	for (int i = 0; i < n; i++) {
		for (int l = 0; l < i; l++) {
			if (arr[i] < arr[l])
				dp[i] = max(dp[i], dp[l]);
		}

		dp[i]++;

		ans = max(ans, dp[i]);
	}

	printf("%d", ans);

	return 0;
}

/*
���� �ع�		: ���� ���α׷���(bottom up)
���� ���		:
������ ������	:
���� ����		: 1.
				  2.
*/
////////////////////////////////////////////////////////////////////////////////