#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;
int const INF = 0;
vector<int> graph[N], topo_order;
bool isvisited[N];

int dis[N], par[N];

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

	for (int i = 1; i <= n; i++) dis[i] = -1;

	dis[1] = 1; par[1] = 0;
	for (auto i: topo_order){
		if (dis[i] == -1) continue;
		for (auto u: graph[i]){
			if ((dis[u] == -1?INF:dis[u]) < dis[i] + 1){
				dis[u] = dis[i] + 1;
				par[u] = i;
			}
		}
	}

	if (dis[n] != -1){
		cout << dis[n] << endl;

		vector<int> ans;

		for (int i = n; par[i] != i; i = par[i]) ans.push_back(i);

		reverse(ans.begin(), ans.end());

		for (auto v: ans) cout << v << " ";
	}
	else cout << "IMPOSSIBLE";
	return 0;
}