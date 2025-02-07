#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 303030;

struct Frac {
    ll n, d;
    Frac operator-(const Frac& rhs) const {
        // TODO
    }
    Frac operator/(const Frac& rhs) const {
        // TODO
    }
    double getDouble() { return (double)n / d; }
    bool operator<(const Frac& rhs) const {
        // TODO
    };
};

struct lf { // f(x) = px + q
    Frac p, q;
    double s;
    lf(): lf({ 1, 1 }, { 0, 1 }) {}
    lf(Frac sp, Frac sq): p(sp), q(sq), s(0) {}
};
double cross(const lf& u, const lf& v) {
    return ((v.q - u.q) / (u.p - v.p)).getDouble();
}

int N, M, k;
ll A[MAXN], B[MAXN];
ll dp[MAXN];
vector<lf> ch;

void input() {
    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++) 
        cin >> A[i] >> B[i];
}

void buildConvexHull() {
    for (int i = 1; i <= N; i++) {
        ch.push_back(lf({ k, A[i] + B[i] }, { A[i], A[i] + B[i] }));
    }
    sort(ch.begin(), ch.end(), [&](const lf& lhs, const lf& rhs) {
        return rhs.p < lhs.p;
    });
}

void convexHullTrick() {
    int top = 1;
    for (int i = 2; i <= N; i++) {
        
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/input.txt", "r", stdin);
    freopen("/Users/jeongwoo-kyung/Programming/CP-Codes/output.txt", "w", stdout);
    #endif

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
}