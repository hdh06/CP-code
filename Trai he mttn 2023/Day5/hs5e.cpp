#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, m, a, b;
vector<pair<int, int> > g[N];
#define st first
#define nd second

bool minimize(int &x, int v){
	if (x == -1 || x > v){
		x = v;
		return true;
	}
	return false;
}

int main(){
	cin >> n >> m >> a >> b;
	while (m--){
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	
	int dis[N] = {};
	for (int i = 0; i < N; i++) dis[i] = -1;
	priority_queue<pair<int, int> > que; 
	
	que.push({0, a});
	dis[a] = 0;
	while (!que.empty()){
		int v = que.top().nd; que.pop();
		for (auto u: g[v])
			if (minimize(dis[u.st], dis[v] | u.nd))
				que.push({-dis[u.st], u.st});
	}
	
	cout << dis[b];
	return 0;
}