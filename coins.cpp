// задача о размене монет 
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
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pld pair<long double, long double>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin() (x).rend()
#define endl "\n"

using namespace std;
using ll = long long;
using ld = long double;

//const ll MOD = 1e9 + 7;
const int INF = 1e9;
//const ll LLINF = 1e18;
const int N = 1e5 + 13;
//const ld eps = 0.00000001;

int n, k;
bool used[N];
int val[N];
int coins[N];
int first[N];


// рекурсивная реализация
int solve1(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (used[x]) return val[x];
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve1(x - c));
    }
    used[x] = true;
    val[x] = best;
    return best;
}

// итеративная реализация
void solve2() {
    val[0] = 0;
    for (int i = 0; i < n; i++) {
        val[i] = INF;
        for (auto c : coins) {
            if (i - c >= 0) {
                val[i] = min(val[i], val[i - c] + 1);
            }
        }
    }
}

// итеративная реализация с возвращением ответа
void solve3() {
    val[0] = 0;
    for (int i = 0; i < n; i++) {
        val[i] = INF;
        for (auto c : coins) {
            if (i - c >= 0 && val[i] > val[i - c] + 1) {
                val[i] = val[i - c] + 1;
                first[i] = c;
            }
        }
    }
    while (n > 0) {
        cout << first[n] << endl;
        n -= first[n];
    }
}


void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coins[i];
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

