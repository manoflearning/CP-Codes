#include <iostream>
#include <map>
using namespace std;

map<string, string> BST;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		BST.insert(make_pair(word, word));
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;

		map<string, string>::iterator it = BST.lower_bound(word);

		if (word == it->first) count++;
	}

	cout << count;

	return 0;
}
/*/////////////////////////////////////////////////////////////////////
���� �ع�		: map �ڷᱸ�� Ȱ��. ���� Ž�� Ʈ��
���� ���		: 
������ ������		:
���� ����		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////