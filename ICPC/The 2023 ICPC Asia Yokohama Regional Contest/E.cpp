#include <bits/stdc++.h>
using namespace std;

const int MOD = 998'244'353;

int n, m;
vector<tuple<int, int, int>> a;
int cnt[24];

void input() {
    cin >> n >> m;
    a.resize(m);
    for (auto& i : a) {
        cin >> get<0>(i) >> get<1>(i) >> get<2>(i);

        if (get<0>(i) > get<2>(i))
            swap(get<0>(i), get<2>(i));

        get<0>(i)--;
        get<1>(i)--;
        get<2>(i)--;
    }
}

void removeDuplicates() {
    set<tuple<int, int, int>> s;
    for (auto& i : a) s.insert(i);
    a.clear();
    for (auto& i : s) {
        a.push_back(i);
        cnt[get<0>(i)]++;
        cnt[get<2>(i)]++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();

    removeDuplicates();
}