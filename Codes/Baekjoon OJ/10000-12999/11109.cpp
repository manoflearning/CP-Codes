#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T; cin >> T;

	while (T--) {
		int d, n, s, p;
		cin >> d >> n >> s >> p;

		int paral = d + n * p, series = n * s;

		if (paral == series) cout << "does not matter\n";
		else if (paral < series) cout << "parallelize\n";
		else cout << "do not parallelize\n";
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
문제 해법		: 구현
결정적 깨달음		: 
시간복잡도		: 
오답 원인		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////