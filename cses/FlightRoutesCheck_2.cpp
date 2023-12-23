#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, m;
vector<int> g[N], rg[N];


bool vis[N], rvis[N];
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (int u: g[v]) DFS(u);
}
void rDFS(int v){
	if (rvis[v]) return;
	rvis[v] = 1;
	for (int u: rg[v]) rDFS(u);
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}
	
	DFS(1);
	rDFS(1);
	
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			cout << "NO\n";
			
			cout << 1 << " " << i << "\n";
			return 0;
		}
		if (!rvis[i]){
			cout << "NO\n";
			
			cout << i << " " << 1 << "\n";
			return 0;			
		}
	}
	cout << "YES\n";
	return 0;
}