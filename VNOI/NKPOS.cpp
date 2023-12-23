#include <bits/stdc++.h>

using namespace std;

int const N = 201;

vector<int> graph[N], path;
int w[N];
int n, m;

void DFS(int v){
	while (graph[v].size() != 0){
		int u = graph[v][0];
		graph[v].erase(graph[v].begin());
		graph[u].erase(find(graph[u].begin(), graph[u].end(), v));
		DFS(u);
		if (graph[v].size() == 0) break;
	}

	path.push_back(v);
}

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n ; i++){
		cin >> w[i];
	}

	for (int t = m; t--;){
		int u, v;
		cin >> u >> v; 
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end(), [](int a, int b){return w[a] > w[b];});
	}

	DFS(1);

	cout << path.size() - 1 << endl;
	for (auto x: path) cout << x << " ";

	return 0;
}