// 한 행 또는 열에 최대 한 번의 연산만을 한다. 따라서 답의 upper bound는 N + M이다.
// 첫 행에 더해지는 값을 v_1, 둘째 행에 더해지는 값을 v_2라고 하자.
// v_1 - v_2 = a[1][1] - a[1][2]다. v_i - v_j = a[1][i] - a[1][j]다.

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int N, M;
vector<vector<int>> A;
int ansR[505050], ansC[505050];

void input() {
    cin >> N >> M;
    A.resize(N + 5, vector<int>(M + 5));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> A[r][c];
        }
    }
}

bool isAnswerExist() {
    for (int r = 1; r + 1 <= N; r++) {
        for (int c = 1; c + 1 <= M; c++) {
            if (A[r][c] - A[r][c + 1] != A[r + 1][c] - A[r + 1][c + 1]) return 0;
        }
    }
    return 1;
}

void getAnsR() {
    for (int r = 1; r <= N; r++) ansR[r] = A[r][1];
}

void getAnsC() {
    for (int c = 1; c <= M; c++) ansC[c] = A[1][c] - ansR[1];
}

void optimize() {
    map<int, int> mp;
    for (int r = 1; r <= N; r++) mp[ansR[r]]++;
    for (int c = 1; c <= M; c++) mp[-ansC[c]]++;

    int add = 0, optVal = -1;
    for (auto& i : mp) {
        if (optVal < i.sc) {
            add = i.fr;
            optVal = i.sc;
        }
    }
    
    for (int r = 1; r <= N; r++) ansR[r] -= add;
    for (int c = 1; c <= M; c++) ansC[c] += add;
}

void print() {
    int cnt = 0;
    for (int r = 1; r <= N; r++) if (ansR[r]) cnt++;
    for (int c = 1; c <= M; c++) if (ansC[c]) cnt++;

    cout << cnt << '\n';
    for (int r = 1; r <= N; r++) if (ansR[r]) 
        cout << 1 << ' ' << r << ' ' << ansR[r] << '\n';
    for (int c = 1; c <= M; c++) if (ansC[c]) 
        cout << 2 << ' ' << c << ' ' << ansC[c] << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    if (!isAnswerExist()) {
        cout << -1;
        return 0;
    }

    getAnsR();

    getAnsC();

    optimize();

    print();
}