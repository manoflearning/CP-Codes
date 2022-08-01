#include <iostream>
#include <list>
#include <cstring>
using namespace std;

list<char> word;

int main() {
	char arr[100001];
	scanf("%s", arr);

	int len = strlen(arr);
	for (int i = 0; i < len; i++)
		word.push_back(arr[i]);

	int n;
	scanf("%d", &n);

	list<char>::iterator it = word.end();
	for (int test = 0; test < n; test++) {
		char com;
		scanf(" %c", &com);

		if (com == 'L') {
			if (it != word.begin()) it--;
		}
		else if (com == 'D') {
			if (it != word.end()) it++;
		}
		else if (com == 'B') {
			if (it != word.begin()) {
				it = word.erase(--it);
				len--;
			}
		}
		else {
			char sam;
			scanf(" %c", &sam);

			word.insert(it, sam);
			len++;
		}
	}

	it = word.begin();
	for (int i = 0; i < len; i++) {
		printf("%c", *it);
		it++;
	}

	return 0;
}
/*
���� �ع�		: ���� ����Ʈ�� Ȱ��
���� ���		: ������ ������ä ���԰� ������ �ſ� ����� �Ͼ�� ������. ���� ���� ����Ʈ�� ���.
������ ������		: 
���� ����		: 1. Ŀ���� �Ǵ��ϴ� ������ �߸��� (������ Ŀ���� �� ���� ���̿� �δ� ���� �ƴ϶�, ��Ģ�� ���� ����� ȯ���� �����س��� ���̱� ����)
				  2. 
*/
//////////////////////////////////////////////////////////////////////