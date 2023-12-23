#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
vector<int> graph[N];
bool isvisited[N];

void DFS(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS(u);
	}
}

int main(){	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		while (m--){
			int u;
			cin >> u;
			graph[i].push_back(u);
		}
	}

	DFS(k);

	int dem = 0;
	for (int i = 1; i <= n; i++){
		if (isvisited[i]) dem++;
	}
	cout << dem << endl;
	for (int i = 1; i <= n; i++){
		if (isvisited[i]) cout << i << " ";
	}

	return 0;
}