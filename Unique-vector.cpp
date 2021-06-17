

#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto x : a) {
        cout << x << ' ';
    }
    return 0;
}
