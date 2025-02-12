#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node { ll w, cost; int idx; };

int n;
ll mxw;
vector<Node> a;
vector<Node> cost1, cost2;
map<ll, pair<int, ll>> mp;
ll mxcost = 0;
vector<int> arr;

void init() {
    a.clear();
    cost1.clear();
    cost2.clear();
    mp.clear();
    mxcost = 0;
    arr.clear();
}

void input() {
    cin >> n >> mxw;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].cost;
        a[i].idx = i + 1;
    }
}

void classify() {
    for (auto& i : a) {
        if (mxw < i.w) continue;
        if (i.w > mxw / 2) cost1.push_back(i);
        else cost2.push_back(i);
    }

    sort(cost2.begin(), cost2.end(), [&](const Node& p1, const Node& p2) {
        return p1.cost * p2.w > p2.cost * p1.w;
    });

    ll sumw = 0, sumcost = 0;
    mp[0] = mp[-1] = { -1, 0 };
    for (int i = 0; i < cost2.size(); i++) {
        sumw += cost2[i].w;
        sumcost += cost2[i].cost;
        mp[sumw] = { i, sumcost };
    }
}

pair<int, ll> f(ll x) {
    auto it = mp.upper_bound(x);
    it--;
    return it->second;
}

void getAnswer() {
    auto res = f(1.5 * mxw);
    mxcost = res.second;
    arr.push_back(res.first);
    for (auto& i : cost1) {
        auto res = f(1.5 * mxw - i.w);
        if (mxcost < i.cost + res.second) {
            mxcost = i.cost + res.second;
            arr.clear();
            arr.push_back(res.first);
            arr.push_back(i.idx);
        }
    }
}

void print() {
    int cnt = arr[0] + 1 + (arr.size() > 1);
    cout << cnt << '\n';
    for (int i = 0; i <= arr[0]; i++)
        cout << cost2[i].idx << ' ';
    if (arr.size() > 1) cout << arr[1] << ' ';
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--) {
        init();

        input();

        classify();

        getAnswer();
        
        print();
    }
}