const int N = 10000001;
bool visited[N];
vector <int> adj[N];
void dfs(int s) {
    if (visited[s]) {
        return;
        visited[s] = true;
        for (auto u : adj[s]) {
            dfs(u);
        }
    }
}
