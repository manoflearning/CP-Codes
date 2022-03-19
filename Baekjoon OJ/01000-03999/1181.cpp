#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20000;

string word[MAX + 1];

bool compare(string a, string b);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> word[i];

	sort(word, word + n, compare);

	for (int i = 0; i < n; i++) {
		if (word[i] == word[i + 1]) continue;

		cout << word[i] << '\n';
	}
		

	return 0;
}

bool compare(string a, string b) {
	if (a.size() != b.size()) {
		if (a.size() < b.size()) return true;
		else return false;
	}

	return a < b;
}
/*/////////////////////////////////////////////////////////////////////
���� �ع�		: sort �Լ��� �̿��� ���ڿ� ����
���� ���		: bool������ ���ǵ� compare �Լ� ���.
������ ������		:
���� ����		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////