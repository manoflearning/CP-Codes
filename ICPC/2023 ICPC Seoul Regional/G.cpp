#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second
#define sz(x) (int)(x).size()

int N, K, M, F;
unordered_map<int, vector<int>> cards;
unordered_map<string, vector<int>> mp;

void input() {
    cin >> N >> K >> M >> F;
    for (int i = 1; i <= K; i++) {
        int cnt = M;
        while (cnt--) {
            int x; cin >> x;
            cards[x].push_back(i);
        }
    }
}

void buildMap() {
    for (int x = 1; x <= N; x++) {
        string res(K, 'N');
        for (auto& i : cards[x]) res[i - 1] = 'Y';
        mp[res].push_back(x);
    }
}

void solve() {
    for (int i = 0; i < F; i++) {
        string s; cin >> s;
        if (sz(mp[s]) == 1) cout << mp[s][0] << '\n';
        else cout << 0 << '\n';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    buildMap();

    solve();
}