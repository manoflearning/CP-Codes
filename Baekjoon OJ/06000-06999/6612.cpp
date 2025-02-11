#include <bits/stdc++.h>
using namespace std;

int len, n;
vector<pair<int, char>> a;
vector<int> R, L;
int psumR[101010], psumL[101010];

int ans1 = 0;
vector<int> ans2;

void init() {
    a.clear();
    R.clear(); L.clear();
    for (int i = 0; i < n; i++)
        psumR[i] = psumL[i] = 0;
    ans1 = 0;
    ans2.clear();
}

int input() {
    cin >> len;
    if (cin.eof()) return 1;
    cin >> n;
    a.resize(n);
    for (auto& i : a)
        cin >> i.first >> i.second;
    return 0;
}

void preprocessing() {
    R.push_back(-1);
    for (int i = 0; i < n; i++) 
        if (a[i].second == 'R') 
            R.push_back(len - a[i].first);
    L.push_back(-1);
    for (int i = n - 1; i >= 0; i--) 
        if (a[i].second == 'L') 
            L.push_back(a[i].first);

    psumR[0] = (a[0].second == 'R');
    for (int i = 1; i < n; i++)
        psumR[i] = (a[i].second == 'R') + psumR[i - 1];
    psumL[n - 1] = (a[n - 1].second == 'L');
    for (int i = n - 2; i >= 0; i--)
        psumL[i] = (a[i].second == 'L') + psumL[i + 1];
}

int get_ith_R(int i) { return R[i]; }
int get_ith_L(int i) { return L[i]; }

int get_cntR(int i) { return (0 <= i - 1 ? psumR[i - 1] : 0); }
int get_cntL(int i) { return (i + 1 < n ? psumL[i + 1] : 0); }

void getAns() {
    for (int i = 0; i < n; i++) {
        auto [x, dir] = a[i];

        int cntR = get_cntR(i), cntL = get_cntL(i);
        int res = -1;

        if (dir == 'R') {
            if (cntR >= cntL) {
                res = get_ith_R(cntR - cntL + 1);
            }
            if (cntR < cntL) {
                res = get_ith_L(cntL - (cntR + 1) + 1);
            }
        }
        if (dir == 'L') {
            if (cntR <= cntL) {
                res = get_ith_L(cntL - cntR + 1);
            }
            if (cntR > cntL) {
                res = get_ith_R(cntR - (cntL + 1) + 1);
            }
        }

        if (ans1 < res) {
            ans1 = res;
            ans2.clear();
            ans2.push_back(x);
        }
        else if (ans1 == res) {
            ans2.push_back(x);
        }
    }
}

void print() {
    cout << "The last ant will fall down in " << ans1 << " seconds - started at ";
    if (ans2.size() == 1) {
        cout << ans2[0] << ".";
    }
    if (ans2.size() == 2) {
        cout << ans2[0] << " and " << ans2[1] << ".";
    }
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {
        init();

        if (input()) break;
        
        sort(a.begin(), a.end());

        preprocessing();

        getAns();

        print();
    }
}