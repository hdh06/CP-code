#include <bits/stdc++.h>

using namespace std;
	
int const N = 1e5 + 5;

vector<int> graph[N];
int color[N];
bool flag;

void DFS(int v){
	for (auto u: graph[v]){
		if (color[u] == 0){
			color[u] = (color[v] == 1?2:1);
			DFS(u);
		}
		else{
			if (color[u] == color[v]){
				flag = true;
				return;
			} 
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++){
		if (color[i] == 0) color[i] = 1;
		DFS(i);
	}

	if (!flag) for (int i = 1; i <= n; i++) cout << color[i] << " ";
	else cout << "IMPOSSIBLE";
	return 0;
}