#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll A, B;
    cin >> A >> B;
    
    vector<string> ans;
    while (A != B) {
        while (A % 2 == 0) { ans.push_back("B+=B"); A /= 2; }
        while (B % 2 == 0) { ans.push_back("A+=A"); B /= 2; }
        if (A > B) {
            ans.push_back("A+=B");
            A += B;
            ans.push_back("B+=B");
            A /= 2;
        }
        if (A < B) {
            ans.push_back("B+=A");
            B += A;
            ans.push_back("A+=A");
            B /= 2;
        }
    }

    cout << ans.size() << '\n';
    for (auto& i : ans)
        cout << i << '\n';
}