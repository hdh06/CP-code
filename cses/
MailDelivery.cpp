#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m;

vector<int> graph[N], euler;

void DFS(int v){
	// for (int i = 1; i <= n; i++){
	// 	cout << "[" << i << "]: ";
	// 	for (int u: graph[i]){
	// 		cout << u << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "----------" << endl;
	for (auto u: graph[v]){
		graph[v].erase(find(graph[v].begin(), graph[v].end(), u));
		graph[u].erase(find(graph[u].begin(), graph[u].end(), v));
		DFS(u);
		if (graph[v].size() == 0) break;
	}
	euler.push_back(v);
}

int main(){
	cin >> n >> m;

	int t = m;
	while(t--){
		int u, v; 
		cin >> u >> v; 

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++){
		if (graph[i].size() % 2 != 0){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}	

	DFS(1);

	if (euler.size() == m + 1) for (auto i: euler) cout << i << " ";
	else cout << "IMPOSSIBLE";
	return 0;
}