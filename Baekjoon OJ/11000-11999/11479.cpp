#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

vector<int> buildsa(const string& s) {
    int n = sz(s), m = max(256, n) + 1;
    vector<int> sa(n), r(2 * n), nr(2 * n), cnt(m), idx(n);
    for (int i = 0; i < n; i++) sa[i] = i, r[i] = s[i];
    for (int d = 1; d < n; d <<= 1) {
        auto cmp = [&](int i, int j) {
            if (r[i] ^ r[j]) return r[i] < r[j];
            return r[i + d] < r[j + d];
        };
        for (int i = 0; i < m; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[r[i + d]]++;
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; ~i; i--) idx[--cnt[r[i + d]]] = i;
        for (int i = 0; i < m; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[r[i]]++;
        for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; ~i; i--) sa[--cnt[r[idx[i]]]] = idx[i];
        nr[sa[0]] = 1;
        for (int i = 1; i < n; i++) nr[sa[i]] = nr[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < n; i++) r[i] = nr[i];
        if (r[sa[n - 1]] == n) break;
    }
    return sa;
}
vector<int> buildlcp(const string& s, const vector<int>& sa) {
    int n = sz(s);
    vector<int> lcp(n), isa(n);
    for (int i = 0; i < n; i++) isa[sa[i]] = i;
    for (int k = 0, i = 0; i < n; i++) if (isa[i]) {
        for (int j = sa[isa[i] - 1]; s[i + k] == s[j + k]; k++);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    return lcp;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;

    ll ans = (ll)sz(s) * (sz(s) - 1) / 2 + sz(s);

    vector<int> sa = buildsa(s);
    vector<int> lcp = buildlcp(s, sa);

    for (int i = 1; i < sz(lcp); i++) {
        ans -= lcp[i];
    }

    cout << ans;
}
