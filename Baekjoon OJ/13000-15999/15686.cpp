/*
���� �ع�		: ���� Ž��
���� ���		: 
������ ������	: 
���� ����		: 1. 
				  2.
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
vector< vector<int> > city;
//ġŲ���� ��
int chiCount;
//ġŲ �Ÿ��� �ּڰ�
int ans = INT_MAX;

//����� ġŲ�� ����
void chooseChicken(int count = 0, int f1 = 0, int f2 = -1);
//����� ġŲ���� ������ ������ ġŲ �Ÿ� ���
void calMin();
//�ϳ��� ���� �������� ġŲ �Ÿ� ���
int findNearChicken(int y, int x);

int main() {
	scanf("%d %d", &n, &m);

	city.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			cin >> city[i][l];

			if (city[i][l] == 2) chiCount++;
		}

	chooseChicken();

	printf("%d", ans);

	return 0;
}

//����� ġŲ�� ����
void chooseChicken(int count, int f1, int f2) {
	if (count == chiCount - m) {
		calMin();
	}
	
	for(int l = f2 + 1; l < n; l++)
		if (city[f1][l] == 2) {
			city[f1][l] = 0;
			chooseChicken(count + 1, f1, l);
			city[f1][l] = 2;
		}
	for (int i = f1 + 1; i < n; i++)
		for (int l = 0; l < n; l++) {
			if (city[i][l] == 2) {
				city[i][l] = 0;
				chooseChicken(count + 1, i, l);
				city[i][l] = 2;
			}
		}
}

//����� ġŲ���� ������ ������ ġŲ �Ÿ� ���
void calMin() {
	int Sans = 0;
	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			if (city[i][l] == 1) 
				Sans += findNearChicken(i, l);
		}

	ans = min(ans, Sans);
}
//�ϳ��� ���� �������� ġŲ �Ÿ� ���
int findNearChicken(int y, int x) {
	int dista = INT_MAX;
	for (int i = 0; i < n; i++)
		for (int l = 0; l < n; l++) {
			if (city[i][l] == 2)
				dista = min(dista, abs(i - y) + abs(l - x));
		}

	return dista;
}



