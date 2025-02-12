#include <bits/stdc++.h>
using namespace std;

map<pair<char, char>, int> mp;

void init() {
    mp[{ 'A', 'A' }] = 10;
    mp[{ 'A', 'B' }] = mp[{ 'B', 'A' }] = 8;
    mp[{ 'A', 'C' }] = mp[{ 'C', 'A' }] = 7;
    mp[{ 'A', 'D' }] = mp[{ 'D', 'A' }] = 5;
    mp[{ 'A', 'F' }] = mp[{ 'F', 'A' }] = 1;

    mp[{ 'B', 'B' }] = 6;
    mp[{ 'B', 'C' }] = mp[{ 'C', 'B' }] = 4;
    mp[{ 'B', 'D' }] = mp[{ 'D', 'B' }] = 3;
    mp[{ 'B', 'F' }] = mp[{ 'F', 'B' }] = 1;

    mp[{ 'C', 'C' }] = 3;
    mp[{ 'C', 'D' }] = mp[{ 'D', 'C' }] = 2;
    mp[{ 'C', 'F' }] = mp[{ 'F', 'C' }] = 1;

    mp[{ 'D', 'D' }] = 2;
    mp[{ 'D', 'F' }] = mp[{ 'F', 'D' }] = 1;

    mp[{ 'F', 'F' }] = 0;
}

int N, M, mxbit;
vector<string> a;
vector<int> dp1(1 << 14), dpmx1(1 << 14); // 가로
vector<int> dp2(1 << 14), dpmx2(1 << 14); // 세로

void input() {
    cin >> N >> M;
    a.resize(N);
    for (auto& i : a) cin >> i;
}

void backtracking1(int v, int bit, int bit2, int score, const string& s) {
    if (M == v) {
        dp1[bit] = max(dp1[bit], score + dpmx2[bit2]);
        return;
    }
    
    backtracking1(v + 1, bit, bit2, score, s);

    backtracking1(v + 1, bit | (1 << v), bit2 | (1 << v), score, s);

    if (v <= M - 2)
        backtracking1(v + 2, 
        bit | (1 << v) | (1 << (v + 1)), 
        bit2, 
        mp[{ s[v], s[v + 1] }] + score, 
        s);
}

void backtracking2(int v, int bit, int score, const string& s1, const string& s2) {
    if (v == M) {
        dp2[bit] = score + dpmx1[mxbit - 1 - bit];
        return;
    }

    int nbit = bit;
    backtracking2(v + 1, nbit, score, s1, s2);

    nbit |= (1 << v);
    score += mp[{ s1[v], s2[v] }];
    backtracking2(v + 1, nbit, score, s1, s2);
}

void findMaximumDP(const vector<int>& dp, vector<int>& dpmx) {
    for (int bit = 0; bit < mxbit; bit++) {
        dpmx[bit] = dp[bit];
        for (int i = 0; i < M; i++) {
            if (!(bit & (1 << i))) continue;
            dpmx[bit] = max(dpmx[bit], dpmx[bit - (1 << i)]);
        }
    }
}

void print(const vector<int>& dp, vector<int>& dpmx) {
    for (int bit = 0; bit < mxbit; bit++) {
        cout << bit << ' ' << dp[bit] << ' ' << dpmx[bit] << '\n';
    }
    cout << "\n\n";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    init();

    input();

    mxbit = (1 << M);

    backtracking1(0, 0, 0, 0, a[N - 1]);
    findMaximumDP(dp1, dpmx1);

    for (int y = N - 2; y >= 0; y--) {
        backtracking2(0, 0, 0, a[y + 1], a[y]);
        findMaximumDP(dp2, dpmx2);

        backtracking1(0, 0, 0, 0, a[y]);
        findMaximumDP(dp1, dpmx1);
    }
    
    cout << dpmx1[mxbit - 1];
}