#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define all(x) (x).begin(), (x).end()

const int MAXN = 202020;

int n;
struct Planet {
    int r, d, t;
};
vector<Planet> a;
vector<Planet> arr[MAXN];

void input() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) 
        cin >> i.r >> i.d >> i.t;
}

void cc() {
    vector<int> c(1, -1);
    for (auto& i : a)
        c.push_back(i.t);
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    for (auto& i : a) {
        i.t = lower_bound(all(c), i.t) - c.begin();
        arr[i.t].push_back({ i.r, i.d, -1 });
    }
}

long double ans = 1e18;

void solve1() {
    sort(all(a), [&](const Planet& p1, const Planet& p2) {
        return p1.r < p2.r;
    });

    for (int i = 0; i + 1 < sz(a); i++) {
        if (a[i].t != a[i + 1].t) 
            ans = min<long double>(ans, a[i + 1].r - a[i].r);
    }
}

struct Point {
    long double x, y;
    bool operator<(const Point& rhs) const {
        return y != rhs.y ? y < rhs.y : x < rhs.x;
    }
    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

long double dist(const Point& a, const Point& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void solve2() {
    vector<int> ord;
    for (int t = 1; t < MAXN; t++)
        if (sz(arr[t]) >= 2) ord.push_back(t);

    for (auto& t : ord) {
        vector<Point> p;
        for (auto& i : arr[t]) {
            p.push_back({ 
                i.r * cos((double)i.d / 180000 * M_PI),
                i.r * sin((double)i.d / 180000 * M_PI) 
            });
        }

        sort(all(p), [&](const Point& p1, const Point& p2) {
            return p1.x < p2.x;
        });
        
        set<Point> s;
        for (int i = sz(p) - 1; i >= 0; i--) {
            vector<Point> lazyErase;
            auto it = s.upper_bound({ p[i].x, p[i].y - ans });
            auto ub = s.lower_bound({ p[i].x, p[i].y + ans });
            while (it != ub) {
                ans = min(ans, dist(p[i], *it));
                if (p[i].x + ans <= it->x)
                    lazyErase.push_back(*it);
                it++;
            }
            for (auto& j : lazyErase) s.erase(j);
            s.insert(p[i]);
        }
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

    cc();

    solve1();

    solve2();

    cout << fixed;
    cout.precision(8);

    cout << ans;
}