// Проверка связанности графа с использованием DFS 

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

using namespace std;
using ll = long long;

const int N = 10000001;
bool visited[N];
vector <vector <int> > adj;

int dfs(int s) {
	int k = 1;
    visited[s] = true;
    for (int u : adj[s]) {
    	if (!visited[u]) {
        	k += dfs(u);
        }
    }
    return k;
}

int main() {

	int n;
	cin >> n;
    adj.push_back({0});
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector <int> v(m);
		for (int &x : v) {
			cin >> x;
		}
		adj.push_back(v);
	}
	int k = dfs(1);
	cout << k << endl;
	if (k == n) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
