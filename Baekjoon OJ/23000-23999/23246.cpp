#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define fr first
#define sc second

int n;
vector<pair<pii, int>> a;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].sc;
        int x, y, z;
        cin >> x >> y >> z;
        a[i].fr.fr = x * y * z;
        a[i].fr.sc = x + y + z;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < 3; i++) 
        cout << a[i].sc << '\n';

    return 0;
}