#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;
typedef long long ll;

int const N = 2501;
ll const INF = 5000*1e9 + 1;
int n, m;

vector<int> graph[N];
vector<iii> edges;

bool vis[N] = {};



int main(){
	cin >> n >> m;
// 
	// if (n == 1){
		// cout << -1 << "\n";
		// return 0;
	// }

	while(m--){
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back({u, v, w});	
	}

	ll dis[N];
	for (int i = 1; i <= n; i++){
		dis[i] = -INF;
	}

	dis[1] = 0;

	for (int i = 1; i <= n; i ++){	
		for (auto e: edges){
			int v = e[0], u = e[1]; ll w = e[2];
			if (dis[v] == -INF) continue;
			if (dis[u] < dis[v] + w){
				dis[u] = dis[v] + w;
				// cout << "BEDBUG: UPDATE " << u << " by " << w << " which is from " << v << endl; 
			}
		}
	}

	// for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];

	for (int i = 1; i <= n; i++){
		for (auto e: edges){
			int v = e[0], u = e[1]; ll w = e[2];
			if (dis[v] == -INF) continue;
			if (dis[v] == INF) dis[u] = INF;
			else if (dis[u] < dis[v] + w){
				dis[u] = INF;
			}
		}
	}

	// for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];

	if (dis[n] == INF) cout << -1;
	else cout << dis[n];

	return 0;
}

/*
6 7
1 2 1
1 6 100000
2 3 1
3 4 1
4 2 1
3 5 1
5 6 1
*/