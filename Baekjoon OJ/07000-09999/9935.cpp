#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000000;

string word, bomb;
char stack[MAX + 1];
int top = 0;

int main() {
	cin >> word >> bomb;

	for (int i = 0; i < word.length(); i++) {
		stack[top] = word[i], top++;

		bool check = true;
		if (top - bomb.length() < 0) check = false;
		else {
			for (int i = top - bomb.length(); i < top; i++)
				if (stack[i] != bomb[i - top + bomb.length()]) {
					check = false;
					break;
				}
		}

		if (check) top -= bomb.length();
	}

	if (top == 0) printf("FRULA");
	for (int i = 0; i < top; i++)
		printf("%c", stack[i]);

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ���� ������ ������ Ȱ��(���̺귯������ �����Ǵ� ������ ���� ������ �ڷᱸ���� �ƴϱ� ����!). ���� ���� ���ڿ��� ������ ���ڸ� ������, ���ڿ� ���� -> ����.
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////