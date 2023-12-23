//https://codeforces.com/problemset/problem/427/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int n, m;
int w[N] = {};

vector<int> g[N], rg[N], order;

bool vis[N] = {};
int ids[N] = {}, id = 0, min_id[N] = {}, count_id[N] = {};

void DFS1(int v){
	if (vis[v]) return;
	vis[v] = true;

	for (auto u: g[v]) DFS1(u);
	order.push_back(v);
}

void DFS2(int v){
	if (ids[v] != 0) return;
	ids[v] = id;

	if (min_id[id] > w[v]){
		min_id[id] = w[v];
		count_id[id] = 0;
	}
	if (w[v] == min_id[id]) count_id[id]++;

	for (auto u: rg[v]) DFS2(u);
}

int main(){
	// freopen("inp.inp", "r", stdin);
	// freopen("out.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> w[i];

	cin >> m;
	while (m--){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		rg[v].push_back(u);
	}	

	for (int i = 1; i <= n; i++) DFS1(i);

	reverse(order.begin(), order.end());

	for (auto i: order){
		if (ids[i] == 0){
			id++;
			min_id[id] = INT_MAX;
			DFS2(i);
		}
	}

	ll tong = 0, ways = 1;
	for (int i = 1; i <= id; i++){
		tong += min_id[i];
		ways *= count_id[i]%MOD;
		ways %= MOD;
	}

	cout << tong << " " << ways;
	return 0;
	
}