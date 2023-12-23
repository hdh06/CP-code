#include <bits/stdc++.h>

using namespace std;

struct node{
	int u, w;
};

typedef long long ll;

int const N = 1e5 + 5;
ll const INF = LLONG_MAX;

vector<node> graph[N];
bool isvisited[N][2];
ll dis[N][2];

priority_queue<array<ll, 3> > myque;

int main(){
	int n, m;
	cin >> n >> m;

	while (m --){
		int v, u, w;
		cin >> v >> u >> w;

		graph[v].push_back({u,w});
		// graph[u].push_back({v,w});
	}

	for (int i = 1; i <= n; i++){
		dis[i][0] = INF;
		dis[i][1] = INF;
	}

	dis[1][1] = dis[1][0] = 0;

	myque.push({0,1,1});

	while(!myque.empty()){
		ll wv = -myque.top()[0];
		int tick = myque.top()[2];
		int v = myque.top()[1];

		myque.pop();

		if (isvisited[v][tick]) continue;
		isvisited[v][tick] = true;

		if (v == n) continue;

		for (auto e: graph[v]){
			int u = e.u, w = e.w;
			if (tick && dis[u][tick - 1] > dis[v][tick] + w / 2){
				dis[u][tick - 1] = dis[v][tick] + w / 2;
				myque.push({-dis[u][tick - 1],u, tick - 1});
			}

			if (dis[u][tick] > dis[v][tick] + w){
				dis[u][tick] = dis[v][tick] + w;
				myque.push({-dis[u][tick], u, tick});
			}
		}
	}

	// for (int i = 1; i <= n; i++) cout << dis[i][0] << " " << dis[i][1] << endl;

	cout << min(dis[n][0], dis[n][1]);

	return 0;
}