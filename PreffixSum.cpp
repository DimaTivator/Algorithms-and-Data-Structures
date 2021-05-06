// prefix sum

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int a[10000001], pref[10000001];

int main() {
	int n;
	cin >> n;
	pref[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		cout << pref[right] - pref[left - 1] << endl;
	}
}
