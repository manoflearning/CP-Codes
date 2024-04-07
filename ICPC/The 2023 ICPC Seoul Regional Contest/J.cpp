#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

ll k;
string l, r;
struct State { int cnt2, cnt3, cnt5, cnt7; };
State a[11], cntk;
ll dp[22][2][67][45][23][23];

void preprocessing() {
    a[1] = { 0, 0, 0, 0 };
    a[2] = { 1, 0, 0, 0 };
    a[3] = { 0, 1, 0, 0 };
    a[4] = { 2, 0, 0, 0 };
    a[5] = { 0, 0, 1, 0 };
    a[6] = { 1, 1, 0, 0 };
    a[7] = { 0, 0, 0, 1 };
    a[8] = { 3, 0, 0, 0 };
    a[9] = { 0, 2, 0, 0 };
}

ll f(string s) {
    reverse(s.begin(), s.end());
    memset(dp, 0, sizeof(dp));

    // base case
    for (int i = 0; i < sz(s); i++) {
        for (int x = 1; x <= 9; x++) {
            if (i == sz(s) - 1 && x > s[i] - '0') continue;
            bool isMax = (i == sz(s) - 1 && x == s[i] - '0');
            dp[i][isMax][a[x].cnt2][a[x].cnt3][a[x].cnt5][a[x].cnt7] = 1;
        }
    }

    // inductive step
    for (int i = sz(s) - 2; i >= 0; i--) {
        for (int cnt2 = 0; cnt2 <= 3 * (sz(s) - i); cnt2++) {
            for (int cnt3 = 0; cnt3 <= 2 * (sz(s) - i); cnt3++) {
                for (int cnt5 = 0; cnt5 <= sz(s) - i; cnt5++) {
                    for (int cnt7 = 0; cnt7 <= sz(s) - i; cnt7++) {
                        for (int x = 1; x <= 9; x++) {
                            State nxt = { cnt2, cnt3, cnt5, cnt7 };
                            nxt.cnt2 = min(60, a[x].cnt2 + nxt.cnt2);
                            nxt.cnt3 = min(40, a[x].cnt3 + nxt.cnt3);
                            nxt.cnt5 = min(20, a[x].cnt5 + nxt.cnt5);
                            nxt.cnt7 = min(20, a[x].cnt7 + nxt.cnt7);

                            ll& dpNot = dp[i][0][nxt.cnt2][nxt.cnt3][nxt.cnt5][nxt.cnt7];
                            ll& dpMax = dp[i][1][nxt.cnt2][nxt.cnt3][nxt.cnt5][nxt.cnt7];

                            if (x == s[i] - '0') {
                                dpNot = (dpNot + dp[i + 1][0][cnt2][cnt3][cnt5][cnt7]) % MOD;
                                dpMax = (dpMax + dp[i + 1][1][cnt2][cnt3][cnt5][cnt7]) % MOD;
                            }
                            else if (x < s[i] - '0') {
                                dpNot = (dpNot + dp[i + 1][0][cnt2][cnt3][cnt5][cnt7]) % MOD;
                                dpNot = (dpNot + dp[i + 1][1][cnt2][cnt3][cnt5][cnt7]) % MOD;
                            }
                            else if (x > s[i] - '0') {
                                dpNot = (dpNot + dp[i + 1][0][cnt2][cnt3][cnt5][cnt7]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    // get answer
    ll ret = 0;
    for (int cnt2 = cntk.cnt2; cnt2 <= 66; cnt2++) {
        for (int cnt3 = cntk.cnt3; cnt3 <= 44; cnt3++) {
            for (int cnt5 = cntk.cnt5; cnt5 <= 22; cnt5++) {
                for (int cnt7 = cntk.cnt7; cnt7 <= 22; cnt7++) {
                    ret = (ret + dp[0][0][cnt2][cnt3][cnt5][cnt7]) % MOD;
                    ret = (ret + dp[0][1][cnt2][cnt3][cnt5][cnt7]) % MOD;
                }
            }
        }
    }

    return ret;
}

ll dp0[22][2][2];

ll f0(string s) {
    reverse(s.begin(), s.end());
    memset(dp0, 0, sizeof(dp0));

    // base case
    for (int i = 0; i < sz(s); i++) {
        for (int x = 1; x <= 9; x++) {
            if (i == sz(s) - 1 && x > s[i] - '0') continue;
            bool isMax = (i == sz(s) - 1 && x == s[i] - '0');
            dp0[i][isMax][0]++;
        }
    }

    // inductive step
    for (int i = sz(s) - 2; i >= 0; i--) {
        ll& dp0Not0 = dp0[i][0][0];
        ll& dp0Not1 = dp0[i][0][1];
        ll& dp0Max0 = dp0[i][1][0];
        ll& dp0Max1 = dp0[i][1][1];

        dp0Not1 = (dp0Not1 + dp0[i + 1][0][0] + dp0[i + 1][0][1]) % MOD;
        if (0 == s[i] - '0') {
            dp0Max1 = (dp0Max1 + dp0[i + 1][1][0] + dp0[i + 1][1][1]) % MOD;
        }
        else dp0Not1 = (dp0Not1 + dp0[i + 1][1][0] + dp0[i + 1][1][1]) % MOD;

        for (int x = 1; x <= 9; x++) {
            if (x < s[i] - '0') {
                dp0Not0 = (dp0Not0 + dp0[i + 1][0][0]) % MOD;
                dp0Not1 = (dp0Not1 + dp0[i + 1][0][1]) % MOD;
                dp0Not0 = (dp0Not0 + dp0[i + 1][1][0]) % MOD;
                dp0Not1 = (dp0Not1 + dp0[i + 1][1][1]) % MOD;
            }
            else if (x == s[i] - '0') {
                dp0Not0 = (dp0Not0 + dp0[i + 1][0][0]) % MOD;
                dp0Not1 = (dp0Not1 + dp0[i + 1][0][1]) % MOD;
                dp0Max0 = (dp0Max0 + dp0[i + 1][1][0]) % MOD;
                dp0Max1 = (dp0Max1 + dp0[i + 1][1][1]) % MOD;
            }
            else if (x > s[i] - '0') {
                dp0Not0 = (dp0Not0 + dp0[i + 1][0][0]) % MOD;
                dp0Not1 = (dp0Not1 + dp0[i + 1][0][1]) % MOD;
            }
        }
    }

    // get answer
    return (dp0[0][0][1] + dp0[0][1][1]) % MOD;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    preprocessing();

    cin >> k >> l >> r;

    while (k % 2 == 0) { cntk.cnt2++; k /= 2; }
    while (k % 3 == 0) { cntk.cnt3++; k /= 3; }
    while (k % 5 == 0) { cntk.cnt5++; k /= 5; }
    while (k % 7 == 0) { cntk.cnt7++; k /= 7; }

    ll ans = 0;

    if (k == 1) {
        ans = (ans + f(r) - f(l)) % MOD;
        
        bool isValid = true;
        State now = { 0, 0, 0, 0 };
        for (auto& c : l) {
            if (c == '0') isValid = false;
            else {
                now.cnt2 += a[c - '0'].cnt2;
                now.cnt3 += a[c - '0'].cnt3;
                now.cnt5 += a[c - '0'].cnt5;
                now.cnt7 += a[c - '0'].cnt7;
            }
        }

        if (now.cnt2 < cntk.cnt2) isValid = false;
        if (now.cnt3 < cntk.cnt3) isValid = false;
        if (now.cnt5 < cntk.cnt5) isValid = false;
        if (now.cnt7 < cntk.cnt7) isValid = false;
        if (isValid) ans = (ans + 1) % MOD;
        ans = (ans + MOD) % MOD;
    }

    ans = (ans + f0(r) - f0(l)) % MOD;
    for (auto& c : l) if (c == '0') {
        ans = (ans + 1) % MOD;
        break;
    }
    ans = (ans + MOD) % MOD;

    cout << ans;
}