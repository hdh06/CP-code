#include <bits/stdc++.h>

using namespace std;

int const N = 5e4 + 2;

vector<int> g[N], topo;

bool vis[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v])
		DFS(u);
	topo.push_back(v);
}

int main(){
	int n, m; cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) DFS(i);

	bitset<N> dp[N];

	for (auto v: topo){
		dp[v].flip(v);
		for (auto u: g[v])
			dp[v] |= dp[u];
	}
	
	for (int i = 1; i <= n; i++)
		cout << dp[i].count() << " ";
	
	return 0;
}