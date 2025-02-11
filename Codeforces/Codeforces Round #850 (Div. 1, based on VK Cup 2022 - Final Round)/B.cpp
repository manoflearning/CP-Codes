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
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

vector<vector<int>> ans;

void exchange1(set<int>& s12, set<int>& s21, vector<int>& cnt1, vector<int>& cnt2, int val1, int val2) {
    int v1 = *s12.begin();
    int v2 = *s21.begin();
    s12.erase(v1);
    s21.erase(v2);
    
    cnt1[v1]--, cnt2[v1]++;
    cnt1[v2]++, cnt2[v2]--;
    ans.push_back({ v1, val1, v2, val2 });
    
    //cout << "XXX " << v1 << ' ' << val1 << ' ' << v2 << ' ' << val2 << '\n';
}

void exchange2(int v, set<int>& s1, vector<int>& cnt1, set<int>& s2, vector<int>& cnt2, int val1, int val2) {
    assert(sz(s2));
    int u = *s2.begin(); 
    
    cnt1[v]--, cnt2[v]++;
    cnt1[u]++, cnt2[u]--;
    if (cnt1[u] >= 2) s1.insert(u);
    if (cnt2[u] == 1) s2.erase(u);

    ans.push_back({ v, val1, u, val2 });
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
        // input
		int n; cin >> n;
        vector<int> cnt1(n + 1), cnt2(n + 1), cnt3(n + 1);
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            for (auto& c : s) {
                if (c == 'w') cnt1[i]++;
                if (c == 'i') cnt2[i]++;
                if (c == 'n') cnt3[i]++;
            }
        }

        // solve 1
        set<int> s12, s13, s21, s23, s31, s32;
        for (int i = 1; i <= n; i++) {
            if (cnt1[i] >= 2) {
                if (cnt2[i] == 0) s12.insert(i);
                if (cnt3[i] == 0) s13.insert(i);
            }
            if (cnt2[i] >= 2) {
                if (cnt1[i] == 0) s21.insert(i);
                if (cnt3[i] == 0) s23.insert(i);
            }
            if (cnt3[i] >= 2) {
                if (cnt1[i] == 0) s31.insert(i);
                if (cnt2[i] == 0) s32.insert(i);
            }
        }

        while (sz(s12) && sz(s21)) {
            exchange1(s12, s21, cnt1, cnt2, 1, 2);
        }
        while (sz(s13) && sz(s31)) {
            exchange1(s13, s31, cnt1, cnt3, 1, 3);
        }
        while (sz(s23) && sz(s32)) {
            exchange1(s23, s32, cnt2, cnt3, 2, 3);
        }

        // solve 2
        set<int> s1, s2, s3;
        for (int i = 1; i <= n; i++) {
            if (cnt1[i] >= 2) s1.insert(i);
            if (cnt2[i] >= 2) s2.insert(i);
            if (cnt3[i] >= 2) s3.insert(i);
        }

        for (int i = 1; i <= n; i++) {
            if (cnt1[i] == 1 && cnt2[i] == 1 && cnt3[i] == 1) continue;
            //cout << cnt1[i] << ' ' << cnt2[i] << ' ' << cnt3[i] << '\n';
            if (cnt1[i] >= 2) {
                if (cnt2[i] == 0) exchange2(i, s1, cnt1, s2, cnt2, 1, 2);
                if (cnt3[i] == 0) exchange2(i, s1, cnt1, s3, cnt3, 1, 3);
                s1.erase(i);
            }
            if (cnt2[i] >= 2) {
                if (cnt1[i] == 0) exchange2(i, s2, cnt2, s1, cnt1, 2, 1);
                if (cnt3[i] == 0) exchange2(i, s2, cnt2, s3, cnt3, 2, 3);
                s2.erase(i);
            }
            if (cnt3[i] >= 2) {
                if (cnt1[i] == 0) exchange2(i, s3, cnt3, s1, cnt1, 3, 1);
                if (cnt2[i] == 0) exchange2(i, s3, cnt3, s2, cnt2, 3, 2);
                s3.erase(i);
            }
        }

        // output
        cout << sz(ans) << '\n';
        for (auto& i : ans) {
            cout << i[0] << ' ';
            if (i[1] == 1) cout << "w ";
            if (i[1] == 2) cout << "i ";
            if (i[1] == 3) cout << "n ";
            cout << i[2] << ' ';
            if (i[3] == 1) cout << "w ";
            if (i[3] == 2) cout << "i ";
            if (i[3] == 3) cout << "n ";
            cout << '\n';
        }

        // initialize
        ans.clear();
	}

	return 0;
}

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

/*#include <bits/stdc++.h>
#include <cassert>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fr first
#define sc second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

vector<vector<int>> ans;

void init() {
    ans.clear();
}

void exchange2(int v, vector<int>& cnt1, set<int>& s, vector<int>& cnt2, int val1, int val2) {
    assert(sz(s));
    int u = *s.begin(); 
    
    cnt1[v]--, cnt2[v]++;
    cnt1[u]++, cnt2[u]--;
    if (cnt2[u] == 1) s.erase(u);

    ans.push_back({ v, val1, u, val2 });
}

void exchange1(set<int>& s12, set<int>& s21, vector<int>& cnt1, vector<int>& cnt2, set<int>& a1, set<int>& a2, int val1, int val2) {
    int v1 = *s12.begin();
    int v2 = *s21.begin();
    s12.erase(v1);
    s21.erase(v2);
    
    cnt1[v1]--, cnt2[v1]++;
    cnt1[v2]++, cnt2[v2]--;
    ans.push_back({ v1, val1, v2, val2 });
    
    //cout << "XXX " << v1 << ' ' << val1 << ' ' << v2 << ' ' << val2 << '\n';
    
    if (cnt1[v1] == 1) a1.erase(v1);
    if (cnt2[v2] == 1) a2.erase(v2);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
        // input
		int n; cin >> n;

        vector<int> cnt1(n + 1), cnt2(n + 1), cnt3(n + 1);
        set<int> a1, a2, a3;

        for (int i = 1; i <= n; i++) {
            string s; cin >> s;

            for (auto& c : s) {
                if (c == 'w') cnt1[i]++;
                if (c == 'i') cnt2[i]++;
                if (c == 'n') cnt3[i]++;
            }

            if (cnt1[i] >= 2) a1.insert(i);
            if (cnt2[i] >= 2) a2.insert(i);
            if (cnt3[i] >= 2) a3.insert(i);
        }

        // solve 1
        set<int> s12, s13, s21, s23, s31, s32;
        for (int i = 1; i <= n; i++) {
            if (cnt1[i] >= 2) {
                if (cnt2[i] == 0) s12.insert(i);
                if (cnt3[i] == 0) s13.insert(i);
            }
            if (cnt2[i] >= 2) {
                if (cnt1[i] == 0) s21.insert(i);
                if (cnt3[i] == 0) s23.insert(i);
            }
            if (cnt3[i] >= 2) {
                if (cnt1[i] == 0) s31.insert(i);
                if (cnt2[i] == 0) s32.insert(i);
            }
        }

        while (sz(s12) && sz(s21)) {
            exchange1(s12, s21, cnt1, cnt2, a1, a2, 1, 2);
        }
        while (sz(s13) && sz(s31)) {
            exchange1(s13, s31, cnt1, cnt3, a1, a3, 1, 3);
        }
        while (sz(s23) && sz(s32)) {
            exchange1(s23, s32, cnt2, cnt3, a2, a3, 2, 3);
        }

        // solve 2
        for (int i = 1; i <= n; i++) {
            if (cnt1[i] == 1 && cnt2[i] == 1 && cnt3[i] == 1) continue;

            if (cnt1[i] >= 2) {
                if (cnt2[i] == 0) exchange2(i, cnt1, a2, cnt2, 1, 2);
                if (cnt3[i] == 0) exchange2(i, cnt1, a3, cnt3, 1, 3);
                a1.erase(i);
            }
            if (cnt2[i] >= 2) {
                if (cnt1[i] == 0) exchange2(i, cnt2, a1, cnt1, 2, 1);
                if (cnt3[i] == 0) exchange2(i, cnt2, a3, cnt3, 2, 3);
                a2.erase(i);
            }
            if (cnt3[i] >= 2) {
                if (cnt1[i] == 0) exchange2(i, cnt3, a1, cnt1, 3, 1);
                if (cnt2[i] == 0) exchange2(i, cnt3, a2, cnt2, 3, 2);
                a3.erase(i);
            }
        }

        // print
        cout << sz(ans) << '\n';
        for (auto& i : ans) {
            cout << i[0] << ' ';
            if (i[1] == 1) cout << "w ";
            if (i[1] == 2) cout << "i ";
            if (i[1] == 3) cout << "n ";
            cout << i[2] << ' ';
            if (i[3] == 1) cout << "w ";
            if (i[3] == 2) cout << "i ";
            if (i[3] == 3) cout << "n ";
            cout << '\n';
        }

        //cout << sz(a1) << ' ' << sz(a2) << ' ' << sz(a3) << '\n';

        // initialize
        init();
	}

	return 0;
}*/