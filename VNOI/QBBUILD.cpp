#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 101;
int const INF = INT_MAX;

vector<ii> graph[N];

int dis[N] = {}, p[N] = {};
bool vis[N] = {};

vector<int> need;

// bool check(){
// 	for (auto x: need){
// 		if (vis[x] == false) return false;
// 	}
// 	return true;
// }

int main(){
	freopen("QB.inp", "r", stdin); freopen("QB.out", "w", stdout);
	int n;
	cin >> n;	

	for (int i = 1; i <= n; i++) dis[i] = INF, p[i] = i;

	priority_queue<ii> myque;
	for (int i = 1; i <= 4; i++){
		int temp;
		cin >> temp;
	 	// myque.push({0, temp});
	 	// dis[temp] = 0;
	 	need.push_back(temp);
	}

	myque.push({0,need[0]});
	dis[need[0]] = 0;
	p[need[0]] = need[0];

	int u, v, w;
	while(cin >> u >> v >> w){
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int tong = 0;

	while (!myque.empty()){
		int v = myque.top()[1], wv = -myque.top()[0]; myque.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for (auto e: graph[v]){
			int u = e[0], w = e[1];
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w; 
				p[u] = v;
				myque.push({-dis[u], u});
			} 
		}
	}

	for (auto x: need){ 
		tong += dis[x];
		for (int c = p[x]; p[c] != c; c = p[c]){
			for (auto d: need) if (d == c) tong -= dis[d];
		}
	}
	
	cout << tong;
	return 0;
}

// 5
// 2 3 4 1
// 1 2 10
// 1 5 1
// 5 2 1
// 1 4 1
// 4 3 3
// 3 2 2