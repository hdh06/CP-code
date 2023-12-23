#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

vector<int> graph[N], path;
int n, m;

int out[N] = {}, in[N] = {};

void DFS(int v){
	while(out[v] > 0){
		int u = graph[v][--out[v]];
		DFS(u);
	}

	path.push_back(v);
}

int main(){
	cin >> n >> m;

	for(int t = m; t--;){
		int u, v; 
		cin >> u >> v;
		graph[u].push_back(v);
		out[u] ++;
		in[v] ++;
	}

	if (in[n] - out[n] > 1 || out[1] - in[1] > 1 || in[n] == out[n] || in[1] == out[1]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 2; i <= n - 1; i++){
		if (in[i] != out[i]){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}

	DFS(1);

	if (path.size() != m + 1){
		cout << "IMPOSSIBLE";
	}
	else{
		reverse(path.begin(), path.end());
		for (auto x: path) cout << x << " ";
	}
	return 0;
}