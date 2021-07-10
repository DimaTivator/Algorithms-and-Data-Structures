// Поиск пути из одной вершины в другую на графе 
// BFS

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

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; // уменьшаем на 1, чтобы работать в 0-индексации
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector <int> p(n, -1); // вектор предков
	int s, f;
	cin >> s >> f;
	s--; 
	f--;
	p[s] = s;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto u : g[x]) {
			if (p[u] == -1) {
				p[u] = x;
				q.push(u);
			}
		}
	}

	// По вектору предков ищем путь из вершины s в вершину f
	vector <int> res;
	if (p[f] != -1) {
		while (f != s) {
			res.push_back(f);
			f = p[f];
		}
		res.push_back(s);
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << ' ';
		}
	}
	else {
		cout << "Пути из вершины " << s << " в вершину " << f << " не существует" << endl;
	}

	return 0;
}
