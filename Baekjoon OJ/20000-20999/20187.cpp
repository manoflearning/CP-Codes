//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int k, h;
string s;
string res;

void f(int v, int y, int x, int ycnt, int xcnt) {
    if (v == sz(s)) return;

    int bo = -1;
    if (s[v] == 'L' || s[v] == 'R') bo = (1 << (k - xcnt - 1));
    if (s[v] == 'U' || s[v] == 'D') bo = (1 << (k - ycnt - 1));

    if (s[v] == 'L') {
        if (bo <= x) {
            res.push_back('L');
            f(v + 1, y, 2 * bo - x - 1, ycnt, xcnt + 1);
        }
        else f(v + 1, y, x, ycnt, xcnt + 1);
    }
    if (s[v] == 'R') {
        if (x < bo) {
            res.push_back('R');
            f(v + 1, y, bo - x - 1, ycnt, xcnt + 1);
        }
        else f(v + 1, y, x - bo, ycnt, xcnt + 1);
    }
    if (s[v] == 'U') {
        if (bo <= y) {
            res.push_back('U');
            f(v + 1, 2 * bo - y - 1, x, ycnt + 1, xcnt);
        }
        else f(v + 1, y, x, ycnt + 1, xcnt);
    }
    if (s[v] == 'D') {
        if (y < bo) {
            res.push_back('D');
            f(v + 1, bo - y - 1, x, ycnt + 1, xcnt);
        }
        else f(v + 1, y - bo, x, ycnt + 1, xcnt);
    }
}

int cal() {
    int ret = h;
    for (int i = sz(res) - 1; i >= 0; i--) {
        if (res[i] == 'L' || res[i] == 'R') {
            if (ret & 1) ret--;
            else ret++;
        }
        else {
            if (ret < 2) ret += 2;
            else ret -= 2;
        }
    }
    return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> k;
    for (int i = 0; i < 2 * k; i++) {
        char c; cin >> c;
        s.push_back(c);
    }
    cin >> h;

    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            res.clear();
            f(0, i, j, 0, 0);
            cout << cal() << ' ';
        }
        cout << '\n';
    }

	return 0;
}