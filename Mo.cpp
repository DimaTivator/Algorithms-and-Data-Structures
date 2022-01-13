// Алгоритм Мо для поиска количества таких чисел x на отрезке [l;r], что число х на этом отрезке встречается ровно х раз
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 13;
const int B = 400;

struct Query {
    int lf, rg, ind;

    Query() {};
};

Query b[N];
int a[N];
int res[N];
int ans = 0;
unordered_map <int, int> m;

bool comp(const Query& a, const Query& b) {
    int ba = a.lf / B;
    int bb = b.lf / B;
    if (ba != bb) return (ba < bb);
    else return (a.rg < b.rg);
}

void add(int x) {
    if (m[x] == x) ans--;
    m[x]++;
    if (m[x] == x) ans++;
}

void del(int x) {
    if (m[x] == x) ans--;
    m[x]--;
    if (m[x] == x) ans++;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> b[i].lf >> b[i].rg;
        b[i].lf--;
        b[i].ind = i;
    }

    sort(b, b + q, comp);

    int lf = 0, rg = 0;
    for (int i = 0; i < q; i++) {
        int ql = b[i].lf, qr = b[i].rg, qi = b[i].ind;

        while (rg < qr) {
            add(a[rg]);
            rg++;
        }

        while (lf > ql) {
            lf--;
            add(a[lf]);
        }

        while (rg > qr) {
            rg--;
            del(a[rg]);
        }

        while (lf < ql) {
            del(a[lf]);
            lf++;
        }

        res[qi] = ans;
    }
    for (int i = 0; i < q; i++) cout << res[i] << "\n";
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

