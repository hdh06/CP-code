#include <bits/stdc++.h>

using namespace std;

vector<int> graph[N], topo_order;
bool isvisited[N];
int ids[N], rep[N];
int n, m, id = 0;

void topo(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		topo(u);
	}

	topo_order.push_back(v);
}

void DFS(int v){
	if (ids[v] != 0) return;
	ids[v] = id;

	for (auto u: graph[v]){
		DFS(u);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) topo(i);

	reverse(topo_order.begin(),topo_order.end());

	for (auto i : topo_order){
		if (ids[i] == 0) id++;
		DFS(i);
		rep[id] = i;
	}

	cout << id - 1 << endl;

	for 



	return 0; 
}