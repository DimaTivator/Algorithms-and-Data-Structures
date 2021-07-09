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

// Алгоритм Беллмана-Форда - алгоритм поиска кратчайшего пути на взвешенном графе
// Предполагается, что граф представлен списком ребер, содержащим кортежи вида (a, b, w); 
// Каждый кортеж означает, что существует ребро веса w, соединяющее вершины a и b
// В данном случае выводятся расстояния от первой вершины до всех остальных 

int main() {
	int n;
	cin >> n;
	vector <tuple <int, int, int> > edges;
	vector <int> distance(n, INF);
 
	for (int i = 1; i <= n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back(make_tuple(a, b, w));
	}
	for (auto e : edges) {
		int a, b, w;
		tie(a, b, w) = e;
		cout << a << ' ' << b << ' ' << w << endl;
	}

	distance[1] = 0;
	for (int i = 1; i < n; i++) {
		for (tuple e : edges) {
			int a, b, w;
			tie(a, b ,w) = e;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}
	for (int i = 1; i < distance.size(); i++) {
		cout << distance[i] << ' ';
	}

	return 0;
}
