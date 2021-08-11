// кратчайший путь коня 
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
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {

	vector <char> letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

	string s, f;
	cin >> s >> f;
	int x1 = s[0] - 'a';
	int y1 = s[1] - '0' - 1;
	int x2 = f[0] - 'a';
	int y2 = f[1] - '0' - 1;
	int n = 1000;
	map <pi, vector <pi> > g;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			g[{ i, j }].push_back({ i - 2, j - 1 });
			g[{ i, j }].push_back({ i - 2, j + 1 });
			g[{ i, j }].push_back({ i - 1, j + 2 });
			g[{ i, j }].push_back({ i - 1, j - 2 });
			g[{ i, j }].push_back({ i + 1, j + 2 });
			g[{ i, j }].push_back({ i + 1, j - 2 });
			g[{ i, j }].push_back({ i + 2, j - 1 });
			g[{ i, j }].push_back({ i + 2, j + 1 });
		}
	}
	map <pi, pi> p;
	queue <pi> q;
	p[{ x1, y1 }] = { x1, y1};
	q.push( {x1, y1 });
	while (!q.empty()) {
		pi x = q.front();
		q.pop();
		for (auto u : g[x]) {
			bool f = false;
			for (auto e : p) {
				if (e.first == u) {
					f = true;
					break;
				}
			
			}
			if (!f) {
				p[u] = x;
				q.push(u);
			}
		}
	}
	vector <pi> ans;
	pi start = { x1, y1 };
	pi finish = { x2, y2 };
	while (finish != start) {
		ans.push_back(finish);
		finish = p[finish];
	}
	ans.push_back(start);
	reverse(ans.begin(), ans.end());
	for (auto x : ans) {
		cout << letters[x.first] << x.second + 1 << endl;
	}
}

int main() {
	solve();
	
	return 0;
}

	
