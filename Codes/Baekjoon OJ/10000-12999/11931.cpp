#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int arr[MAX];

bool compare(int a, int b);

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}

bool compare(int a, int b) {
	return a > b;
}
/*/////////////////////////////////////////////////////////////////////
문제 해법		: 
접근 방식		: 
결정적 깨달음		:
오답 원인		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////