#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

vector<int> graph[N];
bool isvisited[N];
int ans = 0;

void DFS(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS(u);
	}
}

int main(){
	int n, m; 
	cin >> n >> m;

	for(int t = m; t > 0 ;t --){
		int u, v; 
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	} 

	for (int i = 1; i <= n; i++){
		if (!isvisited[i]){
			DFS(i);
			ans ++;
		}
	}

	cout << m - n + ans;
	return 0;
}