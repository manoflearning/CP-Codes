#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define pii pair<int, int>
#define fr first
#define sc second

const int INF = 1e9 + 7;

int n;
vector<int> a[1010];
vector<int> all;
pii Hash[1010101];
map<pii, int> order;

vector<int> buildsa(const vector<int>& s) {
    int n = sz(s);
    vector<int> sa(n), r(n + 1), nr(n + 1);
    for (int i = 0; i < n; i++) sa[i] = i, r[i] = s[i];
    for (int d = 1; d < n; d <<= 1) {
        auto cmp = [&](int i, int j) {
            if (r[i] ^ r[j]) return r[i] < r[j];
            return r[i + d] < r[j + d];
        };
        sort(sa.begin(), sa.end(), cmp);
        nr[sa[0]] = 1;
        for (int i = 1; i < n; i++)
            nr[sa[i]] = nr[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        r = nr;
    }
    return sa;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i].resize(x);
        for (auto& j : a[i]) cin >> j;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(a[i]); j++) {
            Hash[sz(all)] = { i, j };
            all.push_back(a[i][j]);
        }
        Hash[sz(all)] = { i, sz(a[i]) };
        all.push_back(INF);
    }

    vector<int> sa = buildsa(all);
    for (int i = 0; i < sz(sa); i++) {
        order[Hash[sa[i]]] = i;
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({ order[{ i, 0 }], { i, 0 } });
    }

    while (sz(pq)) {
        auto [i, j] = pq.top().sc;
        pq.pop();

        cout << a[i][j] << ' ';
        if (j + 1 < sz(a[i])) {
            pq.push({ order[{ i, j + 1 }], { i, j + 1 }});
        }
    }
}