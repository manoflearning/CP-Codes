#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string cal;
	cin >> cal;

	string porm;
	vector<int> num;

	int st = 0;
	for (int i = 0; i < cal.size(); i++) {
		if (cal[i] == '+' || cal[i] == '-') {
			num.push_back(stoi(cal.substr(st, i)));
			st = i + 1;
			porm.push_back(cal[i]);
		}
	}
	num.push_back(stoi(cal.substr(st, cal.size())));

	int ans = num[0];
	int flag = 0;
	
	while (flag < porm.size() && porm[flag] == '+') {
		ans += num[flag + 1];
		flag++;
	}
	while (flag < porm.size()) {
		ans -= num[flag + 1];
		flag++;
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �׸��� �˰�����
���� ���		: - �����ڰ� ó�� ������, �� �ڷδ� ��� ���� �� ����. �� ������ ��� ���� �� ���Ѵ�
������ ������		: stoi �Լ��� Ȱ���Ͽ� ���ڿ����� ���������� �ٲ� �� �ִ�.
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////