#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 100;
const ll INF = 1e11 + 7;

struct dv {
	ll d; int v;
};
struct vvd {
	int v1, v2; ll d;
};

int N, M, st, en;
vvd Q[MAX + 5];
ll VW[MAX + 5];
vector<ll> upper(MAX + 5, -INF);
vector<dv> adj[MAX + 5];
bool canGo[MAX + 5], cycle[MAX + 5];

void DFS(int v, bool arr[]);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> st >> en >> M;

	for (int i = 0; i < M; i++)
		cin >> Q[i].v1 >> Q[i].v2 >> Q[i].d;

	for (int i = 0; i < N; i++)
		cin >> VW[i];

	for (int i = 0; i < M; i++) {
		//�� ������ ����Ÿ��� ���ϴ� �����̹Ƿ� ���� -�� �ٿ� �ִܰŸ��� ���ϴ� ������ �ٲ�
		//������ ����ġ�� ���� ������ ����ġ�� ����.
		adj[Q[i].v1].push_back({ -Q[i].d + VW[Q[i].v2], Q[i].v2 });
	}

	upper[st] = VW[st];

	bool update;
	for (int i = 0; i < N ; i++) {
		update = false;
		for (int now = 0; now < N; now++) {
			for (dv next : adj[now]) {
				if (upper[now] != -INF && upper[next.v] < upper[now] + next.d) {
					upper[next.v] = upper[now] + next.d;
					update = true;

					//���� ����Ŭ���� en ���������� ��ΰ� �����ϴ°� ?
					if (i == N - 1) DFS(now, cycle);
				}
			}
		}

		if (!update) break;
	}

	//���������� en ���������� ��ΰ� �����ϴ°�?
	if (upper[en] == -INF) cout << "gg";
	//���� ����Ŭ���� en ���������� ��ΰ� �����ϴ°�?
	else if (cycle[en]) cout << "Gee";
	else cout << upper[en];

	return 0;
}

void DFS(int v, bool arr[]) {
	arr[v] = true;
	for (dv next : adj[v]) {
		if (arr[next.v]) continue;
		DFS(next.v, arr);
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����-���� �˰�����
������ ������		: ������ ����ġ�� �־��� ��Ȳ���� �ִܰŸ��� ���� ��, ������ ����ġ�� ������ ����ġ�� ����, ��ġ ������ ����ġ�� ���� ��ó�� �ִ� �Ÿ� �˰������� ������ �� �ִ�.
�ð����⵵		: O(|V||E|)
���� ����		: 1. ���� ����� ��, ���������� ������������ ��� ���θ� ���� ���� Ȯ���ؾ� ��. �� ���� ���� ����Ŭ���� ������������ ��� ���θ� Ȯ���ؾ� ��.
				  2. ������ ���� 1�� ��츦 �������� ����
				  3.
*/////////////////////////////////////////////////////////////////////