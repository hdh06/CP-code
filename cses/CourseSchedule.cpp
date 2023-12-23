#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
vector<int> graph[N], rg[N], topo_order;
bool isvisited[N]; int ids[N];
int id = 0, n, m;

void topo(int v){
	if (isvisited[v]) return ;
	isvisited[v] = true;

	for (auto u: graph[v]){
		topo(u);
	}

	topo_order.push_back(v);
}

void DFS(int v){
	if (ids[v] != 0) return;
	ids[v] = id;

	for (auto u: rg[v]) DFS(u);
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		rg[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) topo(i);

	reverse(topo_order.begin(), topo_order.end());

	for (auto i: topo_order){
		if (ids[i] == 0) id++;
		DFS(i);
	}
	if (id != n) cout << "IMPOSSIBLE";
	else {
		for (auto i: topo_order) cout << i << " ";
	}
	return 0;
}