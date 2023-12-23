#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
vector<int> graph[N], path;

int n, m;
bool vis[N] = {};

bool kt = false;

void DFS(int v, int p){
	if (kt) return;
	if (v == p) return;

	if(vis[v]){
		kt = true;
		return;
	}
	vis[v] = true;

	for (auto u: graph[v]) DFS(u, v);
		path.push_back(v);
}

int main(){
	cin >> n >> m;

	while (m--){
		int v, u;
		cin >> v >> u;

		graph[v].push_back(u);
	}	

	for (int i = 1; i <= n; i++) DFS(i);

	if (kt == false){
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (auto i: path) cout << i << " ";
	return 0;
}