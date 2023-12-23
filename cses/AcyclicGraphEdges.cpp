#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, m;
vector<int> g[N];

int vis[N];
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) if (vis[u] == 0 || vis[u] == 2){
			cout << v << " " << u << "\n";
			DFS(u);
	}
	vis[v] = 2;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) if (!vis[i]) DFS(i);
	return 0;
}