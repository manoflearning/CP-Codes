#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int ans[26] = { 0, };

	char word[101];
	scanf("%s", word);

	int len = strlen(word);
	for (int i = 0; i < len; i++)
		ans[word[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		printf("%d ", ans[i]);

	return 0;
}
/*
���� �ع�		: 
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/
//////////////////////////////////////////////////////////////////////