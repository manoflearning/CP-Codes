#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const string open("([{"), close(")]}");
string word;

bool wellMatched();

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		cin >> word;
		
		if (wellMatched()) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}

bool wellMatched() {
	stack<char> remain;

	for (int i = 0; i < word.length(); i++) {
		if (open.find(word[i]) != -1) remain.push(word[i]);
		else {
			if (remain.empty()) return false;
			else if (open.find(remain.top()) != close.find(word[i])) return false;
			
			remain.pop();
		}
	}

	return remain.empty();
}
/*
���� �ع�		: ������ Ȱ���� ����, string �ڷ����� ó�� �ẽ. string�� find �Լ��� Ȱ���� �� ������ �ܼ��ϰ� ��.
���� ���		: 
������ ������		: 
���� ����		: 1. string �ڷ����� scanf�� �Է� �޾Ƽ��� �ȵ�!!
				  2. 
*/
//////////////////////////////////////////////////////////////////////