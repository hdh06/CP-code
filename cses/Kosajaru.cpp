#include <bits/stdc++.h>

using namespace std;

int const N = 1e6;
vector<int> graph[N], rg[N];
bool isvisited[N];
int id = 0;
int ids[N];
vector<int> topo;

void REtopo(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for(auto u: graph[v]){
		REtopo(u);
	}

	topo.push_back(v);
}

void DFS(int v){
	if (ids[v] != 0) return;
	ids[v] = id;
	for (auto u: rg[v]){
		DFS(u);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		rg[u].push_back(v);
	}

	for (int i = 1; i <= n; i++){
		REtopo(i);
	}

	reverse(topo.begin(), topo.end());

	for (auto v: topo){
		if (ids[v] == 0) id++;
		DFS(v);
		// cout << v << " ";
	}
	cout << id << endl;
	
	for (int i = 1; i <= n; i++){
		cout << ids[i] << " ";
	}
	return 0;
}