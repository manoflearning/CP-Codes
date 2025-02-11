// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

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

const int MAXN = 252525;

int N, M;
ll A[MAXN];
vector<int> candNum;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
}

bool isAnswerExist() {
    ll p = M, q = (N - 1) * N / 2;
    for (int i = 1; i <= N; i++) q -= A[i];
    q = (q % N + N) % N;

    for (int x = 0; x < N; x++) {
        if (p * x % N == q) {
            candNum.push_back(x);
        }
    }

    return !candNum.empty();
}

vector<int> arr;
ll lbAns = 0;

void solve() {
    vector<int> cnt(MAXN), dp(2 * MAXN);
    for (int i = 1; i <= N; i++) cnt[A[i]]++;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < 2 * N; i++) {
        while (cnt[i]--) pq.push(i);
        
        if (dp[i]) continue;

        if (pq.empty()) continue;
        else {
            if (i > pq.top())
                arr.push_back(i - pq.top());
            pq.pop();
            dp[i] = 1;
            if (i < N) dp[i + N] = 1;
        }
    }
    
    sort(all(arr));

    ll sum = 0;
    for (auto& i : arr) sum += i;

    
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

    solve();
}