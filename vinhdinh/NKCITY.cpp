#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;
typedef long long ll;

int const N = 1e5 + 1;

vector<ii> graph[N];

int main(){
	int n, m;
	cin >> n >> m;	

	while(m--){
		int v, u, w; cin >> v >> u >> w;
		graph[v].push_back({u, w});
		graph[u].push_back({v, w});
	}

	ll dis[N] = {}, tong = 0;
	bool vis[N] = {};

	for (int i = 1; i <= n; i++) dis[i] = LL_MAX;

	priority_queue<ii> myque;
	dis[1] = 0;
	myque.push({0, 1});

	while(!myque.empty()){
		int v = myque.top()[1]; myque.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for (auto e: graph[v]){
			int u = e[0]; ll w = e[1];
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				tong += w;
				myque.push({-dis[u], u});
			}
		}
	}

	cout << tong;
	return 0;
}