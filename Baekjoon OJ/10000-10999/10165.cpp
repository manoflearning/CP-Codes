#include <bits/stdc++.h>
using namespace std;

int N, M;
struct Node { 
    int s, e, idx, isReal; 
    bool operator<(const Node& rhs) const {
        return s ^ rhs.s ? s < rhs.s : e > rhs.e;
    }
};
vector<Node> a, b;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        if (s < e) a.push_back({ s, e, i + 1, 1 });
        else {
            a.push_back({ -1, e, i + 1, 0 });
            a.push_back({ s, N, i + 1, 0 });
            b.push_back({ s, e + N, i + 1, 1 });
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mxe = -1;
    vector<int> ans;
    for (auto& i : a) {
        if (mxe < i.e) {
            mxe = i.e;
            if (i.isReal) ans.push_back(i.idx);
        }
    }
    mxe = -1;
    for (auto& i : b) {
        if (mxe < i.e) {
            mxe = i.e;
            ans.push_back(i.idx);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto& i : ans)
        cout << i << ' ';
}