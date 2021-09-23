#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const int N = 1e5 + 13;

int a[N];

int t[4 * N];

void build(int v, int l, int r) {
    if(r - l == 1) {
        t[v] = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    //t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int get(int v, int l, int r, int ql, int qr) {
    if(r <= ql || l >= qr)
        return -INF; // 0

    if(ql <= l && r <= qr) {
        return t[v];
    }

    int m = (l + r) / 2;

    return max(get(v * 2 + 1, l, m, ql, qr),
               get(v * 2 + 2, m, r, ql, qr)); //get(...) + get(..)


}

void update(int v, int l, int r, int qi, int x) {
    if(r - l == 1) {
        a[l] = x;
        t[v] = x;
        return;
    }

    int m = (l + r) / 2;

    if(qi < m)
        update(v * 2 + 1, l, m, qi, x);
    else
        update(v * 2 + 2, m, r, qi, x);

    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);  // t[v] = t[v * 2 + 1] + t[v * 2 + 2]
}


void solve() {
    
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << get(0, 0, n, l, r) << endl;
    }
 
    return 0;
}
