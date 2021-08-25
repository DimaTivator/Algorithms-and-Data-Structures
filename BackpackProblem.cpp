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
#include <queue>
#include <iomanip>
 
#define pi pair<int, int>
#define pl pair<long long, long long>
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LLINF = 1e18;
 
void solve() {
	int n, m;
	cin >> n >> m;
	n++;
	m++;
	vector <int> a(n), c(n);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> c[i];
	}
	vector <vector <int> > dp(n, vector <int>(m, 0));
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (j >= a[i]) { // Если текущий элемент вмещается в рюкзак
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + c[i]); // выбираем класть его или нет
			}
			else {
				dp[i][j] = dp[i - 1][j]; // иначе не кладем
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
 
	return 0;
}
