#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

struct Land {
    ll l, w; int idx;
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<Land> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].w;
        a[i].idx = i;
        a[i].l <<= 1;
        a[i].w <<= 1;
    }

    for (int i = 0; i < n; i++) {
        a.push_back({ a[i].w, a[i].l, i });
    }

    sort(a.begin(), a.end(), [&](const Land& p1, const Land& p2) {
        return p1.l > p2.l;
    });

    ll ans = 0;
    for (auto& i : a) {
        ans = max(ans, i.l * i.w / 2);
    }

    priority_queue<pll> pq;
    for (auto& i : a) {
        pq.push({ i.w, i.idx });

        if (pq.size() <= 1) continue;

        vector<pll> arr;
        while (!pq.empty()) {
            auto [w, idx] = pq.top();
            pq.pop();

            arr.push_back({ w, idx });

            if (arr.size() >= 2) {
                if (arr[0].second != arr.back().second) break;
                else continue;
            }
        }

        for (int j = 0; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                if (arr[j].second == arr[k].second) continue;
                ans = max(ans, i.l * arr[k].first);
            }
        }

        for (auto& i : arr) pq.push(i);
    }

    ans /= 2;
    cout << ans / 2 << (ans & 1 ? ".5" : ".0");
}