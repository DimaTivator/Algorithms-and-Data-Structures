// считывание графа в виде списка ребер и преобразование его в массив списков смежности 
// Для неориентированного графа
int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
