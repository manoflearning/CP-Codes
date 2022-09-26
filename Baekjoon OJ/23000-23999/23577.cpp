#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int d[] = { 1000, 100, 10, 1 };

int n;
ll cnt[10101];
vector<string> a;
ll ans = 0;

ll res;
void bt(int idx, const string& s) {
    if (idx == 4) {
        cnt[res]++;
        return;
    }

    bt(idx + 1, s);

    res += (s[idx] - '0') * d[idx];
    bt(idx + 1, s);
    res -= (s[idx] - '0') * d[idx];
}

ll cal(int idx, int x, const string& s1, const string& s2) {
    if (idx == 4) {
        return (x & 1 ? -1 : 1) * cnt[res];
    }
    
    ll ret = 0;
    if (s1[idx] == s2[idx]) {
        res += (s1[idx] - '0') * d[idx];
        ret += cal(idx + 1, x, s1, s2);
        res -= (s1[idx] - '0') * d[idx];

        return ret;
    }
    else {        
        ret += cal(idx + 1, x, s1, s2);

        res += (s1[idx] - '0') * d[idx];
        ret += cal(idx + 1, x + 1, s1, s2);
        res -= (s1[idx] - '0') * d[idx];

        res += (s2[idx] - '0') * d[idx];
        ret += cal(idx + 1, x + 1, s1, s2);
        res -= (s2[idx] - '0') * d[idx];

        return ret;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
        bt(0, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += cal(0, 0, a[i], a[j]);
        }
    }

    cout << ans / 3;

    return 0;
}