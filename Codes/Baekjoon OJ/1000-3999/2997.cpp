#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + 3);

	if (arr[2] - arr[1] == arr[1] - arr[0])
		printf("%d", arr[2] + (arr[2] - arr[1]));
	else if (2 * (arr[2] - arr[1]) == arr[1] - arr[0])
		printf("%d", (arr[1] + arr[0]) / 2);
	else if (arr[2] - arr[1] == 2 * (arr[1] - arr[0]))
		printf("%d", (arr[2] + arr[1]) / 2);

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