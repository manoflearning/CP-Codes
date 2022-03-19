#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

struct xy {
	ll x; ll y;
};

int N;
double total;
xy dot[10000];

ll CCW(xy a, xy b, xy c);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(1);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> dot[i].x >> dot[i].y;

	for (int i = 1; i < N - 1; i++) {
		total += CCW(dot[i], dot[i + 1], dot[0]);
	}

	if (total < 0) total = -total;
	cout << total / 2;

	return 0;
}

ll CCW(xy a, xy b, xy c) {
	xy A = { b.x - a.x, b.y - a.y }, B = { c.x - a.x, c.y - a.y };
	ll flag = A.x * B.y - A.y * B.x;
	return flag;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: CCW. �� ���� �߽�����, �� ���� �������� ���� ��� ������ �������� ������ ���� ���ؼ� ���� ������ ���ϸ�, �ٰ����� ũ�⸦ �� �� �ִ�. 
������ ������		: 
�ð����⵵		: 
���� ����		: 1.  
				  2.
*/////////////////////////////////////////////////////////////////////