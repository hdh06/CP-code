#include <bits/stdc++.h>

using namespace std;

int const N = 5e4 + 2;

int n, m, q;

vector<int> g[N], rg[N], path;

bool vis[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v])
		DFS(u);
	path.push_back(v);
}

int ids[N], id = 0;

bitset<N> reach[N];

void KRJ(int v){
	if (ids[v]) return;
	ids[v] = id;
	reach[id].flip(v);
	for (auto u: rg[v])
		KRJ(u);
}

int main(){
	cin >> n >> m >> q;
	
	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		rg[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) DFS(i);
	reverse(path.begin(), path.end());
	
	for (auto x: path) if (!ids[x]){
		id++;
		KRJ(x);
	}
	
	reverse(path.begin(), path.end());
	for (auto x: path)
		for (auto u: g[x]) if (ids[x] != ids[u])
			reach[ids[x]] |= reach[ids[u]];
	
	while (q--){
		int a, b; cin >> a >> b;
		if (ids[a] == ids[b]) cout << "YES\n";
		else cout << (reach[ids[a]][b]? "YES\n": "NO\n");
	}
	return 0;
}