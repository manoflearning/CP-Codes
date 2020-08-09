#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int MAX = 1e5;

map<string, int> mp;
int p[MAX + 1];

int find(int x);
void merge(int a, int b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		mp.clear();
		memset(p, -1, sizeof(p));

		int n; cin >> n;

		int flag = 1;

		for (int i = 0; i < n; i++) {
			string s0, s1;
			cin >> s0 >> s1;

			map<string, int>::iterator it0 = mp.find(s0);
			map<string, int>::iterator it1 = mp.find(s1);

			if (it0 == mp.end()) {
				mp.insert({ s0, flag });
				flag++; 
				it0 = mp.find(s0);
			}
			if (it1 == mp.end()) {
				mp.insert({ s1, flag });
				flag++;
				it1 = mp.find(s1);
			}

			merge(it0->second, it1->second);

			cout << -p[find(it0->second)] << '\n';
		}
	}

	return 0;
}

int find(int x) {
	if (p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[B] += p[A];
	p[A] = B;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���Ͽ� ���ε�, map
���� ���		: map�� O(logn)�ð� Ž�� ����� Ȱ���Ͽ� �̸� ����. �̸��� �ϴ��� �����Ǵ� ���ڷ� ���� �����. ���Ͽ� ���ε带 ����Ͽ� ������ ��ġ��, ������ ũ�⸦ ����.
������ ������		:
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////