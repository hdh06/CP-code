#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 501;

int n, m;
ll cap[N][N], flow[N][N];

vector<int> g[N];

bool find(int par[], int s = 1, int t = n){
	fill(1 + par, par + n + 1, 0);
	vector<int> path;
	queue<int> que;
	que.push(s);
	par[s] = s;
	while (!que.empty()){
		int v = que.front(); que.pop();
		if (v == n) return 1;
		for (auto u: g[v]){
			if (cap[v][u] - flow[v][u] == 0) continue;
			if (par[u]) continue;
			par[u] = v;
			que.push(u);
		}
	}
	return 0;
}
// find an augmenting path using Edmonds-Karp
// found: return 1, otherwise: return 0
// int par[]: for backtracking

ll calc(int s = 1, int t = n){ //calc max flow
	ll max_flow = 0;
	int par[N];
	while (find(par)){
		ll minn = LLONG_MAX;
		for (int v = t; v != s; v = par[v])
			minn = min(minn, cap[par[v]][v] - flow[par[v]][v]);
		for (int v = t; v != s; v = par[v]){
			flow[par[v]][v] += minn;
			flow[v][par[v]] -= minn; 
		}
		max_flow += minn;
	}
	return max_flow;
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b, c; cin >> a >> b >> c;
		cap[a][b] += c;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	cout << calc();
	return 0;
}