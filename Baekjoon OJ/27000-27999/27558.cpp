#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

const int MAX = 52;

int n;
vector<int> a, b;
int dest[MAX], vi[MAX];
int ans = 0;

void init() {
    a.clear();
    b.clear();
    memset(dest, 0, sizeof(dest));
    memset(vi, 0, sizeof(vi));
    ans = 0;
}

void input() {
    string s, t;
    cin >> s >> t;
    n = sz(s);
    for (auto& c : s)
        a.push_back(c <= 'Z' ? c - 'A' : c - 'a' + 26);
    for (auto& c : t)
        b.push_back(c <= 'Z' ? c - 'A' : c - 'a' + 26);
}

int isDone() {
    for (int i = 0; i < MAX; i++) {
        if (vi[i] && i != dest[i]) return 0;
    }
    return 1;
}

int oneMove() {
    int ret = 0;
    for (int i = 0; i < MAX; i++) {
        if (!vi[i] || (vi[i] && dest[i] == i)) continue;
        if (!vi[dest[i]] || (vi[dest[i]] && dest[i] == dest[dest[i]])) {
            vi[i] = 0;
            vi[dest[i]] = 1;
            dest[dest[i]] = dest[i];
            ans++;
            ret = 1;
            continue;
        }
        for (int j = 0; j < MAX; j++) {
            if (vi[j] && dest[j] == dest[i]) {
                vi[i] = 0;
                ans++;
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int twoMove() {
    int ret = 0;
    for (int i = 0; i < MAX; i++) {
        if (!vi[i] || (vi[i] && dest[i] == i)) continue;
        for (int tmp = 0; tmp < MAX; tmp++) {
            if (vi[tmp]) continue;

            vi[i] = 0;
            vi[tmp] = 1;
            dest[tmp] = dest[i];
            ans++;
            return 1;
        }
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        init();

        input();

        int isAnsExist = 1;
        for (int i = 0; i < n; i++) {
            if (vi[a[i]] && dest[a[i]] != b[i]) {
                isAnsExist = 0;
                break;
            }
            dest[a[i]] = b[i];
            vi[a[i]] = 1;
        }

        if (!isAnsExist) {
            cout << -1 << '\n';
            continue;
        }

        while (!isDone()) {
            int isMoved = 0;
            for (int i = 0; i < MAX; i++) {
                isMoved |= oneMove();
                if (isDone()) break;
            }
            isMoved |= twoMove();
            if (isDone()) break;

            if (!isMoved) break;
        }

        cout << (isDone() ? ans : -1) << '\n';
    }
}