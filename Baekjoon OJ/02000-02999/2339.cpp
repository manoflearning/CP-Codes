//divide & conquer
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int n, a[25][25];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

int isEnd(int sy, int ey, int sx, int ex) {
    int cnt1 = 0, cnt2 = 0;
    for (int y = sy; y <= ey; y++) {
        for (int x = sx; x <= ex; x++) {
            cnt1 += (a[y][x] == 1);
            cnt2 += (a[y][x] == 2);
        }
    }
    
    return (cnt1 == 0) && (cnt2 == 1);
}

ll f(int sy, int ey, int sx, int ex, int b) {
    if (isEnd(sy, ey, sx, ex)) return 1;
    
    ll ret = 0;
    
    if (b) {
        for (int y = sy + 1; y < ey; y++) {
            int is1 = 0, is2 = 0;
            for (int x = sx; x <= ex; x++) {
                is1 += (a[y][x] == 1);
                is2 += (a[y][x] == 2);
            }
            
            if (is1 && !is2)
                ret += f(sy, y - 1, sx, ex, !b) * f(y + 1, ey, sx, ex, !b);
        }
    }
    else {
        for (int x = sx + 1; x < ex; x++) {
            int is2 = 0;
            for (int y = sy; y <= ey; y++) {
                if (a[y][x] == 2) {
                    is2 = 1;
                    break;
                }
            }
            
            if (is2) continue;
            
            ret += f(sy, ey, sx, x - 1, !b) * f(sy, ey, x + 1, ex, !b);
        }
    }
    
    return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//cout << "AAA";
	input();
	//cout << "XXX";
	ll ans = f(1, n, 1, n, 0) + f(1, n, 1, n, 1);
	//cout << "YYY";
	if (ans == 0) cout << -1;
	else cout << ans;
	
	return 0;
}

//divide & conquer + dp
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int n, a[25][25];
ll dp[25][25][25][25][2];

void init() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1; k <= 20; k++) {
                for (int x = 1; x <= 20; x++) {
                    dp[i][j][k][x][0] = dp[i][j][k][x][1] = -1;
                }
            }
        }
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

int isEnd(int sy, int ey, int sx, int ex) {
    int cnt1 = 0, cnt2 = 0;
    for (int y = sy; y <= ey; y++) {
        for (int x = sx; x <= ex; x++) {
            cnt1 += (a[y][x] == 1);
            cnt2 += (a[y][x] == 2);
        }
    }
    
    return (cnt1 == 0) && (cnt2 == 1);
}

ll f(int sy, int ey, int sx, int ex, int b) {
    ll& ret = dp[sy][ey][sx][ex][b];
    
    if (ret != -1) return ret;
    if (isEnd(sy, ey, sx, ex)) return ret = 1;
    
    ret = 0;
    
    if (b) {
        for (int y = sy + 1; y < ey; y++) {
            int is1 = 0, is2 = 0;
            for (int x = sx; x <= ex; x++) {
                is1 += (a[y][x] == 1);
                is2 += (a[y][x] == 2);
            }
            
            if (is1 && !is2)
                ret += f(sy, y - 1, sx, ex, !b) * f(y + 1, ey, sx, ex, !b);
        }
    }
    else {
        for (int x = sx + 1; x < ex; x++) {
            int is2 = 0;
            for (int y = sy; y <= ey; y++) {
                if (a[y][x] == 2) {
                    is2 = 1;
                    break;
                }
            }
            
            if (is2) continue;
            
            ret += f(sy, ey, sx, x - 1, !b) * f(sy, ey, x + 1, ex, !b);
        }
    }
    
    return ret;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	init();
	//cout << "AAA";
	input();
	//cout << "XXX";
	ll ans = f(1, n, 1, n, 0) + f(1, n, 1, n, 1);
	//cout << "YYY";
	if (ans == 0) cout << -1;
	else cout << ans;
	
	return 0;
}
