#include <iostream>
#include <map>
using namespace std;

map<string, int> arr1, arr2;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    while (n--) {
        string s; cin >> s;
        arr1.insert({ s, 1 });
    }

    int cnt = 0;

    while (m--) {
        string s; cin >> s;
        map<string, int>::iterator it = arr1.find(s);
        if (it != arr1.end()) {
            arr2.insert({ s, 1 });
            cnt++;
        }
    }

    cout << cnt << '\n';

    map<string, int>::iterator it = arr2.begin();
    while (it != arr2.end()) {
        cout << it->first << '\n';
        it++;
    }

    return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: map�� ���� O(lgn)�ð��� ����, Ž��
������ ������		: 
�ð����⵵		: O(nlgn + mlgn)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////