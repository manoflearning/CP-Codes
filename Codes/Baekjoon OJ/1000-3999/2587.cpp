#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[5], sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);

		sum += arr[i];
	}

	sort(arr, arr + 5);

	printf("%d\n%d", sum / 5, arr[2]);

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