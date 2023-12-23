#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

vector<int> graph[N];
bool isvisited[N] = {};

bool flag = false; vector<int> truyvet;

void DFS(int v, int p){
	if (isvisited[v]){
		flag = true;
		return;
	}
	isvisited[v] = true;

	for (auto u: graph[v]){
		if (u != p){
			DFS(u, v);
			if (flag){
				truyvet.push_back(u);
				return;
			}
		}

	}
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m --){
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n && flag == false; i++){
		if (!isvisited[i]) DFS(i, 0);
		if (flag) truyvet.push_back(i);
	} 

	if (truyvet.size()){
		while(truyvet[truyvet.size() - 1] != truyvet[0]) truyvet.erase(truyvet.end() - 1);
		cout << truyvet.size() << endl;
		for (auto u: truyvet) cout << u << " "; 
	}
	else cout << "IMPOSSIBLE";

	return 0;
}