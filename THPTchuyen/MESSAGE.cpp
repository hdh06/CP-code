#include <bits/stdc++.h>

using namespace std;

int const N = 801;

vector<int> graph[N];
vector<int> DFSorder;
bool isvisited[N];

void DFS(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS(u);
	}

	DFSorder.push_back(v);
}

void DFS2(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS2(u);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		isvisited[i] = false;
	}


	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++){
		DFS(i);
	}

	for (int i = 1; i <= n; i++){
		isvisited[i] = false;
	}

	reverse(DFSorder.begin(),DFSorder.end());

	int dem = 0;
	for (auto i: DFSorder){
		if (!isvisited[i]) dem++;
		DFS2(i);
	}

	cout << dem;

	return 0;
}