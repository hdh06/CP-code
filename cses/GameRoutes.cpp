#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;
vector<int> graph[N], topo_order;
bool isvisited[N];
int dp[N];

void DFS(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFS(u);
	}
	topo_order.push_back(v);
}

int main(){
	int n, m;
	cin >> n >> m;

	while (m --){
		int u, v;
		cin >> u >> v; 
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) DFS(i);

	reverse(topo_order.begin(), topo_order.end());

	dp[1] = 1 % MOD;

	for (auto i: topo_order){
		for (auto u: graph[i]){
			dp[u] += dp[i]; dp[u] %= MOD;
		}
	}

	cout << dp[n];
	return 0;
}