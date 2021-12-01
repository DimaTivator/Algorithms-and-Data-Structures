// Дерево отрезков для поиска миниимума на отрезке и изменения элементов

#include <bits/stdc++.h>

#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const int N = 2 * 1e5 + 13;
const ld eps = 0.00000001;

int t[2 * N];
int a[2 * N];

void build(int v, int l, int r) {
    if (l == r - 1) {
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int L, int R, int l, int r) {
    if  (l >= R || r <= L) {
        return INF;
    }
    if (l <= L && r >= R) {
        return t[v];
    }
    int m = (L + R) / 2;
    return min(get(v * 2 + 1, L, m, l, r), get(v * 2 + 2, m, R, l, r));
}

void change(int v, int L, int R, int pos, int x) {
    if (L == R - 1) {
        t[v] = x;
        return;
    }
    int m = (L + R) / 2;
    if (m > pos) {
        change(v * 2 + 1, L, m, pos, x);
    }
    else {
        change(v * 2 + 2, m, R, pos, x);
    }
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << get(0, 0, n, l - 1, r) << endl;
        }
        else {
            int pos, x;
            cin >> pos >> x;
            a[pos - 1] = x;
            change(0, 0, n, pos - 1, x);
        }
        // for (int j = 0; j < n; j++) {
        //     cout << a[j] << ' ';
        // }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

