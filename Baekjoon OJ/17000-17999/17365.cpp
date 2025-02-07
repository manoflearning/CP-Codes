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

#define EXPAND( x ) x // Use this if MS Visual Studio doesn't expand __VA_ARGS__ correctly
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) EXPAND( GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1) )
#define FOR(...) EXPAND( F_ORC(__VA_ARGS__ )(__VA_ARGS__) )
#define EACH(x, a) for (auto& x : a)

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const char st = 'a';
const int MAXC = 'z' - 'a' + 1;

ll dp[202020];

struct trie {
	trie* child[MAXC];
	int term;

	trie() {
		fill(child, child + MAXC, nullptr);
		term = 0;
	}
	~trie() {
		for (int i = 0; i < MAXC; i++)
			if (child[i]) delete child[i];
	}

	void insert(const string& s, int key = 0) {
        term++;
		if (s.size() == key) return;
		else {
			int next = s[key] - st;
			if (!child[next]) child[next] = new trie;
			child[next]->insert(s, key + 1);
		}
	}

	int find(const string& s, int key) {
        ll ret = (term * dp[key]) % MOD;
		if (s.size() == key) return ret;
		
        int next = s[key] - st;
		if (!child[next]) return ret;
		else return (ret + child[next]->find(s, key + 1)) % MOD;
	}
};

int n;
string s;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    trie* root = new trie;

	cin >> n;
    FOR(n) {
        string x; cin >> x;
        root->insert(x);
    }

    cin >> s;

    dp[sz(s)] = 1;
    for (int i = sz(s) - 1; i >= 0; i--) {
        dp[i] = root->find(s, i) % MOD;

        /*string sub;
        for (int len = 1; len <= 300 && i + len - 1 < sz(s); len++) {
            sub.push_back(s[i + len - 1]);
            
            int res = root->find(sub);
            if (!res) break;
            dp[i] = (dp[i] + res * dp[i + len]) % MOD;
        }*/

        //cout << i << ' ' << dp[i] << '\n';
    }

    cout << dp[0];

    delete root;

	return 0;
}