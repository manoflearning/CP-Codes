#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif
    
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p % 4 == 0) x ^= p - 1;
        else if (p % 4 == 3) x ^= p + 1;
        else x ^= p;
    }

    cout << (x ? "koosaga" : "cubelover");

    return 0;
}