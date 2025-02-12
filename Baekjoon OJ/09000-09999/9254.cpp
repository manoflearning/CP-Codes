#include <bits/stdc++.h>
using namespace std;

void inverse_matrix(vector<vector<double>> &a){
    int n = a.size();
    int m = n + n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            a[i].push_back(i==j);
    for(int c = 0, r = 0; c < m && r < n; ++c){
        int p = r; // pivot row
        for(int i = r; i < n; ++i)
            if(a[p][c] < a[i][c])
                p = i;
        if(a[p][c] == 0){ puts("no inverse"); return; }; 
        for(int j = 0; j < m; ++j)
            swap(a[p][j], a[r][j]);
        double t = a[r][c];
        for(int j = 0; j < m; ++j)
            a[r][j] /= t;
        for(int i = 0; i < n; ++i) if(i != r){
            double t = a[i][c];
            for(int j = c; j < m; ++j)
                a[i][j] -= a[r][j] * t;
        }
        ++r;
    }
    cout << fixed;
    cout.precision(8);
    for(int i=0;i<n;++i,puts(""))
        for(int j=0;j<n;++j)
            cout << a[i][n + j] << ' ';
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
	freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
	#endif

	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    inverse_matrix(a);

	return 0;
}