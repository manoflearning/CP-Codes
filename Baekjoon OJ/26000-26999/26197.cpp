#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

vector<int> drawPile(98);
int p = 0;

vector<int> inHand;
vector<vector<int>> rows(4);

int pickInHand() {
    // If one or more cards allow him to do the backward trick
    for (auto& i : inHand) {
        if (i == rows[0].back() - 10) return i;
        if (i == rows[1].back() - 10) return i;
        if (i == rows[2].back() + 10) return i;
        if (i == rows[3].back() + 10) return i;
    }

    // Otherwise, he plays a card in the regular way
    int ret = -1, mn = 1e9 + 7;
    for (auto& i : inHand) {
        if (rows[0].back() < i && i - rows[0].back() < mn) { 
            ret = i, mn = i - rows[0].back(); 
        }
        if (rows[1].back() < i && i - rows[1].back() < mn) { 
            ret = i, mn = i - rows[1].back(); 
        }
        if (i < rows[2].back() && rows[2].back() - i < mn) { 
            ret = i, mn = rows[2].back() - i;
        }
        if (i < rows[3].back() && rows[3].back() - i < mn) { 
            ret = i, mn = rows[3].back() - i;
        }
    }
    return ret;
}
void addToRow(int x) {
    if (x == rows[0].back() - 10) { rows[0].push_back(x); return; }
    if (x == rows[1].back() - 10) { rows[1].push_back(x); return; }
    if (x == rows[2].back() + 10) { rows[2].push_back(x); return; }
    if (x == rows[3].back() + 10) { rows[3].push_back(x); return; }
    
    int idx = -1, mn = 1e9 + 7;
    if (rows[0].back() < x && x - rows[0].back() < mn) { 
        idx = 0, mn = x - rows[0].back(); 
    }
    if (rows[1].back() < x && x - rows[1].back() < mn) { 
        idx = 1, mn = x - rows[1].back(); 
    }
    if (x < rows[2].back() && rows[2].back() - x < mn) { 
        idx = 2, mn = rows[2].back() - x;
    }
    if (x < rows[3].back() && rows[3].back() - x < mn) { 
        idx = 3, mn = rows[3].back() - x;
    }
    rows[idx].push_back(x);
}
void addInHand(int x) { inHand.push_back(x); }
void delInHand(int x) {
    int idx = -1;
    for (int i = 0; i < sz(inHand); i++) {
        if (inHand[i] == x) { idx = i; break; }
    }
    for (int i = idx; i + 1 < sz(inHand); i++) {
        inHand[i] = inHand[i + 1];
    }
    inHand.pop_back();
}
int draw() {
    if (p == sz(drawPile)) return -1;
    return drawPile[p++];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/programming/cp-codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // input
    for (auto& i : drawPile) cin >> i;

    // initial phase
    rows[0].push_back(1);
    rows[1].push_back(1);
    rows[2].push_back(100);
    rows[3].push_back(100);

    addInHand(draw());
    addInHand(draw());
    addInHand(draw());
    addInHand(draw());
    addInHand(draw());
    addInHand(draw());
    addInHand(draw());
    addInHand(draw());

    // while playing game
    while (1) {
        int x = pickInHand();
        if (x == -1) break;
        addToRow(x);
        delInHand(x);

        int y = pickInHand();
        if (y == -1) break;
        addToRow(y);
        delInHand(y);

        int p = draw();
        if (p != -1) addInHand(p);
        int q = draw();
        if (q != -1) addInHand(q);
    }

    // output
    for (int i = 0; i < 4; i++) {
        for (auto& j : rows[i]) cout << j << ' ';
        cout << '\n';
    }
    for (auto& i : inHand) cout << i << ' ';
    cout << '\n';
    for (int i = p; i < sz(drawPile); i++)
        cout << drawPile[i] << ' ';
    cout << '\n';
}