#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
vector<int> graph[N];
bool isvisited[N];
int n, m;


void DFS(int v){
	if (isvisited[v]) return;

	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS(u);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	while (m--){
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	int ans = 0;
	vector<int> truyvet;
	for (int i = 1; i <= n; i++) if (!isvisited[i]){
		DFS(i);
		ans++;
		if (i != 1) truyvet.push_back(i);
	}

	cout << ans - 1 << endl;

	for (auto i: truyvet){
		cout << 1 << " " << i << endl;
	}

	return 0;
}