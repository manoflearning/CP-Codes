#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

const int MAXV = 50 * 50;

int N, en;
map<string, int> mp;
vector<int> adj[MAXV + 5];

//scc
int label[MAXV + 5], lCnt;
stack<int> stk;
bool finished[MAXV + 5];
vector<vector<int>> SCC;
int sNum[MAXV + 5], sCnt;

//scc �׷���
vector<int> sAdj[MAXV + 5];
int indeg[MAXV + 5];
ll dist[MAXV + 5];

void scan(int cnt);
void multiCheck(map<string, int>::iterator& it, string s);
int DFS(int v);
void topological_sort();

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(label, -1, sizeof(label));
	fill(dist, dist + MAXV + 5, sizeof(dist));

	//�Է� �� �׷��� ����
	int cnt; cin >> cnt; 
	scan(cnt);

	//scc ã��: dfs ���д� Ʈ��
	for (int v = 1; v <= N; v++)
		if (label[v] == -1) DFS(v);

	//scc �׷��� ����
	for (int v = 1; v <= N; v++) {
		int sV = sNum[v];
		for (int next : adj[v]) {
			int sNext = sNum[next];
			if (sV == sNext) continue;
			sAdj[sV].push_back(sNext);
			indeg[sNext]++;
		}
	}

	//���� ����
	topological_sort();
	
	//���
	cout << dist[en] << '\n';
	
	return 0;
}

void scan(int cnt) {
	N = 1;

	for (int i = 0; i < cnt; i++) {
		string s; cin >> s;
		map<string, int>::iterator v = mp.find(s);

		multiCheck(v, s);

		int x; cin >> x;
		while (x--) {
			cin >> s;
			map<string, int>::iterator u = mp.find(s);
			multiCheck(u, s);
			adj[u->second].push_back(v->second);
		}
	}
	
	string s; cin >> s;
	map<string, int>::iterator it = mp.find(s);
	multiCheck(it, s);
	en = it->second;
	
	N--;
}

void multiCheck(map<string, int>::iterator& it, string s) {
	if (it == mp.end()) {
		mp.insert({ s, N++ });
		it = mp.find(s);
	}
}

int DFS(int v) {
	label[v] = lCnt++;
	stk.push(v);

	int ret = label[v];
	for (int next : adj[v]) {
		if (label[next] == -1) ret = min(ret, DFS(next));
		else if (!finished[next]) ret = min(ret, label[next]);
	}

	if (ret == label[v]) {
		vector<int> vSCC;
		while (true) {
			int t = stk.top();
			stk.pop();

			vSCC.push_back(t);
			sNum[t] = sCnt;
			finished[t] = true;

			if (t == v) break;
		}

		SCC.push_back(vSCC);
		sCnt++;
	}

	return ret;
}

void topological_sort() {
	queue<int> q;

	for (int v = 1; v <= N; v++)
		dist[v] = 1;
	
	for (int sV = 0; sV < sCnt; sV++) {
		if (indeg[sV] == 0) {
			for (int v : SCC[sV]) q.push(v);
		}
	}

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		
		for (int next : adj[n]) {
			if (sNum[n] == sNum[next]) continue;
			
			dist[next] += dist[n];

			int sV = sNum[n], sNext = sNum[next];
			if (--indeg[sNext] == 0) {
				for (int v : SCC[sNext]) q.push(v);
			}
		}
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: scc + ���� ����
������ ������		: ť�� SCC ������ ������ ���� �ƴ϶�, ���� �׷����� ���� ������ ������. ������ ������ SCC ������ �Ѵ�.
�ð����⵵		: O(|V| + |E|)
���� ����		: 1. ���� ���������� ������ �� �ֱ� ������, int�� ������ �Ѿ �� ����
				  2.
*/////////////////////////////////////////////////////////////////////