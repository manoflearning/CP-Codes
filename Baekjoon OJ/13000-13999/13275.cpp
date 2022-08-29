// Manacher's Algorithm
// Find all palindromes in string in O(N)

// BOJ 14444 AC Code
// https://www.acmicpc.net/problem/14444
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (x).size()

const int MAXS = 101010 * 2;

string s;
int n, p[MAXS];
// n: length of string
// p[i]: the radius of the palindrome at the current position i
int r = -1, c = -1;
// r: end of palindrome
// c: center of palindrome

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = sz(s);

    // Preprocessing for determining even-length pelindromes
    s.resize(MAXS);

    for (int i = n - 1; i >= 0; i--) {
        s[i << 1 | 1] = s[i];
        s[i << 1] = '#';
    }
    n <<= 1;
    s[n++] = '#';

    // Processing
    for (int i = 0; i < n; i++) {
        if (r >= i) p[i] = min(r - i, p[c * 2 - i]);
        else p[i] = 0;

        while (1) {
            if (i - p[i] - 1 < 0) break;
            if (i + p[i] + 1 >= n) break;
            if (s[i + p[i] + 1] != s[i - p[i] - 1]) break;
            p[i]++;
        }

        if (i + p[i] > r) {
            r = i + p[i], c = i;
        }
    }

    // get answer
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, p[i]);
    }

    cout << ans;

    return 0;
}