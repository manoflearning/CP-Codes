#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> people;

int main() {
	scanf("%d %d", &n, &k);

	people.resize(n);

	for (int i = 0; i < n; i++)
		people[i] = i + 1;

	int flag = -1;

	printf("<");
	while (true) {
		for (int i = 0; i < k; i++) {
			if (flag == people.size() - 1) flag = 0;
			else flag++;
		}
		
		printf("%d", people[flag]);
		people.erase(people.begin() + flag);
		flag--;

		if (people.empty()) break;

		printf(", ");
	}
	printf(">");

	return 0;
}
/*
���� �ع�		: ���� ť
���� ���		:
������ ������	:
���� ����		: 1.
				  2.
*/
//////////////////////////////////////////////////////////////////////