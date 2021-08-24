// s - текущая вершина, e - предыдущая вершина 
void (int s, int e) {
	for (auto u : g[s]) {
		if (u != e) {
			dfs(u, s);
		}
	}
}
