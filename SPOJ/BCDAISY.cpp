#include <bits/stdc++.h>

using namespace std;

int const N = 251;

vector<int> graph[N];

bool isvisited[N];
vector<int> ans;

void DFS(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for(auto u: graph[v]) DFS(u);
}

int main(){
	int n, m;
	cin >> n >> m;

	while( m--){
		int u, v; 
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);

	for (int i = 1; i <= n; i++){
		if (!isvisited[i]) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());

	if (ans.size() == 0){
		cout << 0;
		return 0;
	}

	for (auto x: ans) cout << x << " ";
	return 0;
}