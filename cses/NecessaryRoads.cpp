#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

vector<int> g[N];
int tin[N], low[N], id = 0;
bool vis[N];

vector<array<int, 2> > ans;

void DFS(int v, int p = -1){
	vis[v] = true;
	tin[v] = low[v] = id++;
	for (auto u: g[v]) if (u != p){
		if (vis[u]) low[v] = min(low[v], tin[u]);
		else{
			DFS(u, v);
			low[v] = min(low[v], low[u]);
			if (low[u] > tin[v]) ans.push_back({v, u});
		}
	}
}

int main(){
	int n, m; cin >> n >> m;
	while (m --){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) DFS(i);

	cout << ans.size() << "\n";
	for (auto x: ans) cout << x[0] << " " << x[1] << "\n"; 
	return 0;
}