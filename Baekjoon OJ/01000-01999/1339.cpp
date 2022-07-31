#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char word[10][9];
int abc_count[26];

bool compare(int a, int b);

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);

		int len = strlen(word[i]);

		for (int l = 0; l < len; l++)
			abc_count[word[i][l] - 65] += pow(10, len - l - 1);
	}

	sort(abc_count, abc_count + 26, compare);

	int ans = 0;
	for (int i = 0; i < 9; i++)
		ans += abc_count[i] * (9 - i);
	printf("%d", ans);

	return 0;
}

bool compare(int a, int b) {
	return a > b;
}
/*
���� �ع�		: �Է��� ������ ���ÿ� �� ���ĺ��� ��� ���Ǵ����� ���, �������� ����
���� ���		:
������ ������	:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

char word[10][11];
char word_len[10];

vector<char> abc;
int abc_value[26];

int ans;

void count_value(int count, int value);
void word_sum();

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
		word_len[i] = strlen(word[i]);
	}
	
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < word_len[i]; l++) {
			char sam = word[i][l];

			bool check = true;
			for (int j = 0; j < flag; j++)
				if (abc[j] == sam) {
					check = false;
					break;
				}
			
			if (check) {
				abc.push_back(sam);
				flag++;
			}
		}
	}
	
	count_value(flag, 9);

	printf("%d", ans);

	return 0;
}

void count_value(int count, int value) {
	//base case
	if (count == 0) word_sum();
	//
	for (int i = 0; i < count; i++) {
		abc_value[(int)abc[i] - 65] = value;

		int tmp = abc[i];
		abc.erase(abc.begin() + i);
		count_value(count - 1, value - 1);
		abc.insert(abc.begin() + i, tmp);
	}
}
void word_sum() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int l = 0; l < word_len[i]; l++)
			sum += abc_value[word[i][l] - 65] * pow(10, strlen(word[i]) - l - 1);
	}

	ans = max(ans, sum);
}
*/
/*
���� �ع�		: ���� Ž��(�־��� ���ĺ����� ������ ��� ������ ���� Ž��)
���� ���		:
������ ������	:
���� ����		: 1. strlen�� �ݺ����� �������� ���� �� ��
				  2.
*/
//////////////////////////////////////////////////////////////////////