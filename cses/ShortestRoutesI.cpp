#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long,int>
#define ll long long

ll const INF = LLONG_MAX;
int const N = 1e5 + 5;
vector<pii> graph[N];
bool isvisited[N];
ll dis[N];
int n, m, s = 1;

void BFS(){
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	priority_queue<pii> myque;
	myque.push({0,s});

	while (!myque.empty()){
		int v = myque.top().second; ll wv = myque.top().first;
		myque.pop();
		
		if (isvisited[v]) continue;
		isvisited[v] = true;

		for (auto pu : graph[v]){
			int u = pu.first; ll w = pu.second;
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				myque.push({-dis[u], u});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		graph[v].push_back({u,w});
	}
	//cout << "BFS";
	BFS();

	for (int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	return 0;
}