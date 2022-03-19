#include <iostream>
#include <map>
using namespace std;

long long n, p, q;
map<long long, long long> bst;

long long eterArr(long long x);

int main() {
	cin >> n >> p >> q;

	cout << eterArr(n);

	return 0;
}

long long eterArr(long long x) {
	map<long long, long long>::iterator ret = bst.find(x);
	//memoization
	if (ret != bst.end()) return ret->second;
	//base case
	if (x == 0) return 1;

	long long ans1 = eterArr(x / p), ans2 = eterArr(x / q);

	bst.insert({ x / p, ans1 });
	bst.insert({ x / q, ans2 });

	return ans1 + ans2;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ������ȹ��, ���� Ž�� Ʈ��
���� ���		: n == 10^12�� �� �޸������̼��� �迭�� �����ϱ� ���ؼ��� �迭�� ũ�⸦ 10^12�� ��ƾ� �Ѵ�. �׷��� ���� Ž�� Ʈ���� Ȱ���Ѵٸ� ��� Ž������ O(lgn)�� �ɸ��� �ϳ�, �޸� ȿ���� ũ�� ���� �� �ִ�.
������ ������		: 
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////