// O(n + m) n - число вершин, m - число ребер 

vector <int> adj[N];
queue <int> q;
int distance[N];
bool visited[N];
// поиск начинается в некоторой вершине x
int x = 0;
visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
	int s = q.front();
	q.pop();
	// обработать вершину s
	for (auto u : adj[s]) {
		if (visited[u]) {
			continue;
		}
		visited[u] = true;
		distance[u] = distance[s] + 1;
		q.push(u);
	}
}
