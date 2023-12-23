#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

vector<int> graph[N];

int f[N], g[N], h[N], n;

void DFS_1(int v, int p){
	for (auto u: graph[v]) if (u != p){
		DFS_1(u, v);
		if (f[u] + 1 > f[v]){
			h[v] = f[v];
			f[v] = f[u] + 1;
		}
		else h[v] = max(h[v], f[u] + 1);
	}
}

void DFS_2(int v, int p){
	for (auto u: graph[v]) if (u != p){
		if (f[u] + 1 == f[v]) 
			 g[u] = max(g[v] + 1, h[v] + 1);
		else g[u] = max(g[v] + 1, f[v] + 1);
		DFS_2(u, v);
	}
}

int main(){
	cin >> n;

	for (int i = 1; i <= n - 1; i++){
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}	

	DFS_1(1, 0);
	DFS_2(1, 0);

	for (int i = 1; i <= n; i++){
		cout << max(g[i], f[i]) << " ";
	}
	return 0;
}