// s - текущая вершина, e - предыдущая вершина 
void dfs(int s, int e) {
	for (auto u : g[s]) {
		if (u != e) {
			dfs(u, s);
		}
	}
}
