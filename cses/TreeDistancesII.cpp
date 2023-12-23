#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;

vector<int> gp[N];
ll f[N], g[N], s[N], sg[N];

void DFS(int v, int p){
	for (auto u: gp[v]) if (u != p){
		DFS(u, v);
		f[v] += f[u] + s[u];
		s[v] += s[u];
	}
}

void DFS2(int v, int p){
	for (auto u: gp[v]) if (u != p){
		g[u] += g[v] + (f[v] - f[u] - s[u]) + sg[v] + (s[v] - s[u]);
		sg[u] += sg[v] + s[v] - s[u];
		DFS2(u, v);
	}
}

int main(){
	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int u, v; cin >> u >> v;
		gp[u].push_back(v);
		gp[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) s[i] = 1;
	DFS(1, 0);
	DFS2(1, 0);

	for (int i = 1; i <= n; i++) cout << g[i] + f[i] << " ";

	return 0;
}