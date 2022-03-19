#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const string open("(["), close(")]");

int main() {
	char word[31];
	scanf("%s", word);

	stack<char> pare;
	int sum = 0, tmp = 1;

	int len = strlen(word);
	bool right = true;

	for (int i = 0; i < len; i++) {
		if (open.find(word[i]) != -1) {
			tmp *= open.find(word[i]) + 2;
			pare.push(word[i]);
		}
		else {
			if (!pare.empty() && open.find(pare.top()) == close.find(word[i])) {
				if(open.find(word[i - 1]) == close.find(word[i]))
					sum += tmp;
				tmp /= close.find(word[i]) + 2;
				pare.pop();
			}
			else {
				right = false;
				break;
			}
		}
	}

	if (right && pare.empty()) printf("%d", sum);
	else printf("0");

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ������ Ȱ��. ��ȣ�� ���� ������ ���� ������ �������ִ� sum�� tmp ������ ��.
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////