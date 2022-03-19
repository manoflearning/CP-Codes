#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int n;
vector<int> tree[MAX + 1];
int dp[MAX + 1][2];

int min_adapt(int node, int last, bool lAda);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	cout << min_adapt(1, 0, true);
	
	return 0;
}

int min_adapt(int node, int last, bool lAda) {
	int& ret = dp[node][lAda];
	//memoization
	if (ret != -1) return ret;
	//cout << node << "\n";
	int ans1 = MAX + 1, ans2 = 1;

	if (lAda) {
		ans1 = 0;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] == last) continue;

			ans1 += min_adapt(tree[node][i], node, false);
		}
	}
	
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == last) continue;
		
		ans2 += min_adapt(tree[node][i], node, true);
	}
	
	return ret = min(ans1, ans2);
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ������ȹ��, Ʈ��
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////