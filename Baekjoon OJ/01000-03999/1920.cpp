#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
int m, sam;

bool binary_search(int left, int right, int ans);

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &sam);

		if (binary_search(0, n - 1, sam)) printf("1");
		else printf("0");
		printf("\n");
	}


	return 0;
}

bool binary_search(int left, int right, int ans) {
	//base case
	if (left > right) return false;
	//
	int flag = (left + right) / 2;

	if (arr[flag] == ans) return true;
	if (arr[flag] > ans) return  binary_search(left, flag - 1, ans);
	if (arr[flag] < ans) return  binary_search(flag + 1, right, ans);
}

/*
���� �ع�		: �̺� Ž��
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/