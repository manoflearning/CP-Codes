#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXC = 2;
struct trie {
	trie* child[MAXC];
	ll term, sum;
	trie() {
		fill(child, child + MAXC, nullptr);
		term = 0;
	}
	~trie() {
		for (int i = 0; i < MAXC; i++)
			if (child[i]) delete child[i];
	}
	void insert(int x, int key = 30) {
		if (key == -1) term++, sum++;
		else {
			int next = (x & (1 << key) ? 1 : 0);
			if (!child[next]) child[next] = new trie;
			child[next]->insert(x, key - 1);

            sum = 0;
            if (child[0]) sum += child[0]->sum;
            if (child[1]) sum += child[1]->sum;
		}
	}
    /*ll getSum(int key = 30) {
        if (key == -1) return sum = term;
        else {
            if (child[0]) sum += child[0]->getSum(key - 1);
            if (child[1]) sum += child[1]->getSum(key - 1);

            return sum;
        }
    }*/
	ll find(int x, int k, int key = 30) {
		if (key == -1) return 0;
		else {
            int next = (x & (1 << key) ? 1 : 0);

            ll ret = 0;
            if (k & (1 << key)) {
                if (child[next]) ret += child[next]->sum;
                if (child[!next]) ret += child[!next]->find(x, k, key - 1);
            }
            else {
                if (child[next]) ret += child[next]->find(x, k, key - 1);
            }

            return ret;
		}
	}
};

int n, k;
int a[101010], psum[101010];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    trie* root = new trie;

	cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = a[i] ^ psum[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += root->find(psum[i], k);
        //cout << i << ' ' << root->find(psum[i], k) << '\n';
        root->insert(psum[i]);
    }

    cout << ans;

    delete root;

	return 0;
}