// 풀이: 그리디 알고리즘
// 핵심 아이디어는 길이 len의 수열을 만들고자 할 때, 같은 종류의 음식을 판매하는 식당이 최대 (len + 1) / 2개여야 한다는 것이다.
// len이 짝수일 때, (len + 1) / 2개의 식당이 있는 종류의 음식이 2개라면 지금 하나를 소비해야 한다.
// len이 홀수일 때, (len + 1) / 2개의 식당이 있는 종류의 음식이 존재한다면 지금 하나를 소비해야 한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)(x).size()

int n, a[303030];
set<int> cnt[303030], notDone;
set<int> cnt2[303030];
vector<int> ans;

void del(int idx, int coIdx, int co) {
    ans.push_back(idx);
    notDone.erase(idx);
    cnt[co].erase(idx);

    cnt2[coIdx].erase(co);
    cnt2[coIdx - 1].insert(co);
}

void f(int v, int prv) {
    if (v == n + 1) return;
    
    int len = (n - v + 1);
    int ub = (len + 1) / 2;
    
    if (!(len & 1) && sz(cnt2[ub]) == 2) {
        int co = -1;
        for (auto& i : cnt2[ub]) {
            if (i == prv) continue;

            if (co == -1 || *cnt[i].begin() < *cnt[co].begin()) co = i;
        }

        auto it = cnt[co].begin();
        del(*it, ub, co);
        
        f(v + 1, co);
    }
    else if ((len & 1) && sz(cnt2[ub])) {
        int co = *cnt2[ub].begin();
        
        auto it = cnt[co].begin();
        del(*it, ub, co);
        
        f(v + 1, co);
    }
    else {
        for (auto& i : notDone) {
            int co = a[i];
            if (co == prv) continue;

            del(i, sz(cnt[co]), co);

            f(v + 1, co);
            break;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // input
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]].insert(i);
    }

    // 불가능 판별
    for (int i = 1; i <= n; i++) {
        if (sz(cnt[i]) > (n + 1) / 2) {
            cout << -1;
            return 0;
        }
    }

    // solve
    for (int i = 1; i <= n; i++) {
        notDone.insert(i);
        cnt2[sz(cnt[i])].insert(i);
    }

    f(1, 0);

    for (auto& i : ans) 
        cout << i << ' ';
}