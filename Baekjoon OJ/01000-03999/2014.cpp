#include <iostream>
#include <queue>
#include <climits>
#define ll long long
using namespace std;

struct bb {
	int x;
	int fg;
};

struct cmp {
	bool operator() (bb a, bb b) {
		return a.x > b.x;
	}
};

int k, n;
int arr[100];
priority_queue<bb, vector<bb>, cmp> pq;

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		pq.push({ arr[i], i });
	}
		
	for (int i = 1; i < n; i++) {
		for (int l = pq.top().fg; l < k; l++) {
			if ((ll)pq.top().x * arr[l] > INT_MAX) break;

			pq.push({ pq.top().x * arr[l], l });
		}
		
		pq.pop();
	}

	cout << pq.top().x;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �켱���� ť
���� ���		: �켱���� ť���� pop�Ǵ� ���ڵ��� ������ �������� ������ ��µȴ�. �ű�� ��� ����� ���� �����Ѵ�.
������ ������		:  
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////