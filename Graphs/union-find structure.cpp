// union-find structure СНМ
// алгоритм Краскала (минимальное остовное дерево)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <iterator>
#include <queue>
#include <numeric>
#include <deque>
#include <stack>

#define int long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pld pair<long double, long double>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin() (x).rend()
#define endl "\n"

using namespace std;

//const ll MOD = 1e9 + 7;
//const int INF = 1e9;
//const ll LLINF = 1e18;
const int N = 1e5 + 13;
//const ld eps = 0.00000001;

int link[N];
int sz[N];
vector <tuple <int, int, int> > a;

// find возвращает представителя элемента x
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

// find через сжатие путей
int find1(int x) {
    if (x == link[x]) return x;
    return link[x] = find1(link[x]);
}

// проверка принадлежат ли вершины одной компоненте
bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    link[b] = a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(m);
    // граф вводится списком ребер
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        a[i] = { w, x, y };
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) link[i] = i;
    for (int i = 0; i < n; i++) sz[i] = 1;
    
    for (int i = 0; i < m; i++) {
        int x, y, w;
        tie(w, x, y) = a[i];
        if (!same(x, y)) unite(x, y);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

