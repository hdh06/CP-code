#include <bits/stdc++.h>

using namespace std;

int const N = 2501;

int n, m;
vector<int> g[N];

int tin[N];

int ans = INT_MAX;

int dis[N];

void BFS(int s){
	memset(dis, -1, sizeof dis);
	
	dis[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()){
		int v = que.front();
		que.pop();
		
		for (auto u: g[v]){
			if (dis[u] == -1){
				dis[u] = dis[v] + 1;
				que.push(u);
			}else if (dis[v] == dis[u] || dis[v] == dis[u] - 1)
			 	ans = min(ans, dis[v] + dis[u] + 1);
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
		BFS(i);
	
	cout << (ans == INT_MAX? -1: ans);
	return 0;
}