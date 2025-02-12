#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tc; cin >> tc;
    while (tc--) {
        int n, k, m;
        string s;
        cin >> n >> k >> m >> s;

        vector<bool> vis(m + 1);
        for (int i = 0; i < sz(s); i++) {
            if (k < s[i] - 'a') vis[i] = 1;
        }

        char opt2 = '*';
        string ans;
        while (sz(ans) < n) {
            vector<int> lm(26, -1);

            char opt = '*';
            for (int i = 0; i < sz(s); i++) {
                if (vis[i]) continue;
                if (lm[s[i] - 'a'] == -1) {
                    lm[s[i] - 'a'] = i;
                    opt = s[i];
                }
            }

            for (int i = 0; i < k; i++) {
                if (lm[i] == -1) {
                    opt2 = i + 'a';
                    break;
                }
            }
            if (opt2 != '*') break;

            ans.push_back(opt);
            for (int i = 0; i <= lm[opt - 'a']; i++) vis[i] = 1;
        }

        if (sz(ans) == n) cout << "YES\n";
        else {
            while (sz(ans) < n) ans.push_back(opt2);
            cout << "NO\n" << ans << '\n';   
        }
    }
}