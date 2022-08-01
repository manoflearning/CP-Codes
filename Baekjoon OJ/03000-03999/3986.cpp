#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	
	int sum = 0;

	for (int test = 0; test < t; test++) {
		string word;
		cin >> word;

		stack<char> AandB;

		for (int i = 0; i < word.length(); i++) {
			if (!AandB.empty() && AandB.top() == word[i]) AandB.pop();
			else AandB.push(word[i]);
		}

		if (AandB.empty()) sum++;
	}

	printf("%d", sum);

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ���� Ȱ��
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////