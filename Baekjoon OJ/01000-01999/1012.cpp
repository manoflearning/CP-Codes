#include <iostream>
#include <algorithm>

using namespace std;

int M, N, K;
bool land[51][51] = { 0, };
bool visitp[51][51] = { 0, }; //visitp �迭�� ������� �ʴ� �迭������, �� �迭�� ������ ��� "�¾ҽ��ϴ�"�� �߰�, �׷��� ���� ��� "��Ÿ�� ����"�� ��.

int moveX[4] = { 1, 0, -1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

void DFS(int x, int y) {
    if (land[x][y] == 1) {
        land[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int nx = moveX[i] + x;
            int ny = moveY[i] + y;

            if (x >= 0 && y >= 0 && x < M && y < N) { //������ �� ��尡 �ƴ϶�, ���� ����� ������ Ȯ���ϴ� �ڵ�
                DFS(nx, ny);
            }
        }
    }
}

int main(void) {
    int T, cnt;
    int x, y;
    land[-1][0]; //������ �迭 �ε��� ������ ���
    cin >> T;

    while (T--) {
        cnt = 0;
        cin >> M >> N >> K;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                land[i][j] = 0;
            }
        }

        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            land[x][y] = 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (land[i][j] == 1) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}