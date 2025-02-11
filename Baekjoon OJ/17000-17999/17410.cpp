#include <bits/stdc++.h>
using namespace std;

const int sq = 404;

int n, a[101010];
vector<int> arr[101010 / sq + 1];

void del(int idx, int v) {
    auto& it = arr[idx];
    for (int i = 0; i < it.size(); i++) {
        if (it[i] == v) {
            it.erase(it.begin() + i);
            break;
        }
    }
}
void add(int idx, int v) {
    auto& it = arr[idx];
    for (int i = 0; i < it.size(); i++) {
        if (v <= it[i]) {
            it.resize(it.size() + 1);
            for (int j = it.size() - 2; j >= i; j--) it[j + 1] = it[j];
            it[i] = v;
            return;
        }
    }
    it.push_back(v);
}
int query(int idx, int v) {
    auto& it = arr[idx];
    return it.size() - (upper_bound(it.begin(), it.end(), v) - it.begin());
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        arr[i / sq].push_back(a[i]);

    for (int i = 0; i < 101010; i += sq)
        sort(arr[i / sq].begin(), arr[i / sq].end());
    
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int i, v;
            cin >> i >> v;
            del(i / sq, a[i]);
            add(i / sq, a[i] = v);
        }
        if (op == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            
            int ans = 0;

            int L = (l + sq - 1) / sq * sq, R = r / sq * sq;
            if (L >= R) {
                for (int i = l; i <= r; i++) if (k < a[i]) ans++;
            }
            else {
                for (int i = l; i < L; i++) if (k < a[i]) ans++;
                for (int i = L; i < R; i += sq) ans += query(i / sq, k);
                for (int i = R; i <= r; i++) if (k < a[i]) ans++;
            }
            
            cout << ans << '\n';
        }
    }
}