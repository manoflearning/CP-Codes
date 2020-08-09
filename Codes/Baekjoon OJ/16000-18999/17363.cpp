#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int N, M;
char arr[105][105], arr2[105][105];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x] == '.' || arr[y][x] == 'O') arr2[x][y] = arr[y][x];
			else if (arr[y][x] == '-') arr2[x][y] = '|';
			else if (arr[y][x] == '|') arr2[x][y] = '-';
			else if (arr[y][x] == '/') arr2[x][y] = '\\';
			else if (arr[y][x] == '\\') arr2[x][y] = '/';
			else if (arr[y][x] == '^') arr2[x][y] = '<';
			else if (arr[y][x] == '<') arr2[x][y] = 'v';
			else if (arr[y][x] == 'v') arr2[x][y] = '>';
			else if (arr[y][x] == '>') arr2[x][y] = '^';
		}
	}

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cout << arr2[M - y - 1][x];
		}
		cout << '\n';
	}

	return 0;
}