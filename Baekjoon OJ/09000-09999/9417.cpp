#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tc; cin >> tc;
    
    string du;
    getline(cin, du);

    while (tc--) {
        string s;
        getline(cin, s);

        vector<int> a;

        int prv = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string num;
                for (int j = prv; j < i; j++)
                    num.push_back(s[j]);

                prv = i + 1;
                a.push_back(stoi(num));
                assert(stoi(num) > 0);
            }
        }

        string num;
        for (int j = prv; j < s.size(); j++) {
            num.push_back(s[j]);
        }
        a.push_back(stoi(num));
        assert(stoi(num) > 0);

        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                ans = max(ans, gcd(a[i], a[j]));
            }
        }

        cout << ans << '\n';
    }
}