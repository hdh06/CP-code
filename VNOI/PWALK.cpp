#include <bits/stdc++.h>

using namespace std;

typedef array<int,2> ii;

int const N = 1001;

vector<ii> graph[N];

int dis[N], n, Q;

void DFS(int v, int pre){
	for (auto u: graph[v]) if (u[0] != pre){
		dis[u[0]] = dis[v] + u[1];
		DFS(u[0], v);
	}
}

int main(){
	cin >> n >> Q; 
	for (int i = 1; i <= n - 1; i++){
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}

	while(Q--){
		int a, b; 
		cin >> a >> b; 
		dis[a] = 0; 
		DFS(a, 0);

		cout << dis[b] << endl;
	}

	return 0;
}