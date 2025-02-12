#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 7;
const int MAX = 1e5;

int ansx = -1, ansy = -1;
double ansr = -1;

double query(int sx, int sy, int ex, int ey) {
    cout << "query " << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
    cout << flush;
    double ret; cin >> ret;
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // cin.tie(NULL); cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    for (int x = 199; x <= MAX; x += 199) {
        double res = query(x, 0, x, MAX);

        if (res > 0.5) {
            int l = x - 199, r = MAX;
            while (r - l >= 3) {
                int mid1 = (2 * l + r) / 3;
                int mid2 = (l + 2 * r) / 3;
                double res1 = query(mid1, 0, mid1, MAX);
                double res2 = query(mid2, 0, mid2, MAX);
                if (res1 < res2) l = mid1;
                else r = mid2;
            }
            for (int i = l; i <= r; i++) {
                double tmp = query(i, 0, i, MAX);
                if (ansr < tmp) {
                    ansx = i;
                    ansr = tmp;
                }
            }

            break;
        }
    }

    int zzinr = (int)(ansr + 0.5) / 2;

    int l = 0, r = MAX;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        double res = query(ansx, 0, ansx, mid);
        if (res > zzinr) r = mid - 1;
        else l = mid;
    }
    ansy = l;

    cout << "answer " << ansx << ' ' << ansy << ' ' << zzinr;
    cout << flush;
}