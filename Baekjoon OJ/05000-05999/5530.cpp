#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int n, cntI;
string s;

int f(int x) {
    stack<int> stk;
    int now = 0, ub = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'I') {
            now++; 
            stk.push(i);
        }
        if (now == x) {
            ub = i - 1;
            break;
        }
    }

    int cntIJ = 0, cntO = 0;
    for (int i = 0; i < n; i++) {
        while (sz(stk) && stk.top() < i) stk.pop();

        if (s[i] == 'J' || (s[i] == 'I' && i <= ub)) cntIJ++;
        
        if (s[i] == 'O' && cntIJ > 0 && sz(stk)) {
            cntIJ--, cntO++; 
            stk.pop();
        }
    }
    return min(cntO, x);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'I') cntI++;

    int l = 0, r = cntI;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (f(mid) == mid) l = mid;
        else r = mid - 1;
    }

    cout << l;

    return 0;
}