// 4 1
// 1221
// 2211

// step 0
// 121
// 21
// 

// step 1
// 121
// 21
// 

#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
#define pii pair<int, int>
#define fr first
#define sc second

int n, p;
vector<int> a, b;

void init() {
    a.clear();
    b.clear();
}

void input() {
    cin >> n >> p;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < sz(s1); i++) {
        if (i == 0 || (i > 0 && s1[i - 1] != s1[i])) a.push_back(s1[i] - '0');
        if (i == 0 || (i > 0 && s2[i - 1] != s2[i])) b.push_back(s2[i] - '0');
    }
}

vector<pii> solve() {
    // 11..11
    // 22..22
    // (empty)
    vector<pii> ret;
    int aidx = sz(a) - 1, bidx = sz(b) - 1;

    int alb = (a[0] == 1 ? 1 : 0);
    int blb = (b[0] == 2 ? 1 : 0);

    int co3 = 0;
    while (aidx >= alb && bidx >= blb) {
        if (a[aidx] == 1 && b[bidx] == 1) {
            ret.push_back({ 1, 2 });
            aidx--;
        }
        else if (a[aidx] == 2 && b[bidx] == 2) {
            ret.push_back({ 2, 1 });
            bidx--;
        }
        else if (a[aidx] == 1 && b[bidx] == 2) {
            if (co3 != 1) {
                if (co3 == a[aidx]) ret.push_back({ 3, 1 });
                if (co3 == b[bidx]) ret.push_back({ 3, 2 });
                co3 = 0;
            }
            aidx--;
            ret.push_back({ 1, 3 });
            co3 = 1;
        }
        else if (a[aidx] == 2 && b[bidx] == 1) {
            if (co3 != 1) {
                if (co3 == a[aidx]) ret.push_back({ 3, 1 });
                if (co3 == b[bidx]) ret.push_back({ 3, 2 });
                co3 = 0;
            }
            bidx--;
            ret.push_back({ 2, 3 });
            co3 = 1;
        }
    }

    if (aidx >= alb) {
        if (co3 == 2) {
            co3 = 0;
            ret.push_back({ 3, 2 });
        }
        while (aidx >= alb) {
            if (a[aidx] == 1) { ret.push_back({ 1, 3 }); co3 = 1; }
            else ret.push_back({ 1, 2 });
            aidx--;
        }
    }
    if (bidx >= blb) {
        if (co3 == 1) {
            co3 = 0;
            ret.push_back({ 3, 1 });
        }
        while (bidx >= blb) {
            if (b[bidx] == 2) { ret.push_back({ 2, 3 }); co3 = 2; }
            else ret.push_back({ 2, 1 });
            bidx--;
        }
    }

    if (co3 != 0) {
        if (co3 == 1) ret.push_back({ 3, 1 });
        if (co3 == 2) ret.push_back({ 3, 2 });
    }

    // cout << "------\n";
    // for (auto& i : a) cout << i << ' ';
    // cout << '\n';
    // for (auto& i : b) cout << i << ' ';
    // cout << '\n';
    // for (auto& i : ret)
    //     cout << i.fr << ' ' << i.sc << '\n';
    // cout << "------\n";

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        init();

        input();

        vector<pii> ans1 = solve();
        for (auto& i : a) i = (i == 1 ? 2 : 1);
        for (auto& i : b) i = (i == 1 ? 2 : 1);
        vector<pii> ans2 = solve();

        vector<pii> ans = (sz(ans1) <= sz(ans2) ? ans1 : ans2);
        cout << sz(ans) << '\n';
        if (p != 1) {
            for (auto& i : ans)
                cout << i.fr << ' ' << i.sc << '\n';
        }
        
    }
}
