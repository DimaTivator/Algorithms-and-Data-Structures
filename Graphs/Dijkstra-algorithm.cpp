// O(n + m * log m)
// Алгоритм Дейкстры работает при неотрицательных ребрах
// Предполагается, что граф представлен в виде списков смежности, так что 
// g[a] содержит пару {b, w}, если существует ребро веса w, соединяющее вершины a и b
// Вводится же в данной реализации граф в виде списка ребер

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
const int INF = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <pair <int, int> > > g(n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		g[a].push_back({ b, w });
		g[b].push_back({ a, w });
	}
	vector <int> d(n, INF);
	vector <bool> visited(n, false);
	priority_queue <pair <int, int> > q;
	int x = 0; // найдем расстояния до всех вершин от вершины X
	d[x] = 0;
	q.push({ 0, x }); // первый элемент пары - расстояние, второй - вершина
	while (!q.empty()) {
		int k = q.top().second;
		q.pop();
		if (visited[k]) continue;
		visited[k] = true;
		for (auto u : g[k]) {
			int b = u.first, w = u.second;
			if (d[k] + w < d[b]) {
				d[b] = d[k] + w;
				q.push({ -d[b], b });
			}
		}
	}
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << ' ';
	}

	return 0;
}
