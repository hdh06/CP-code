#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

vector<int> g[N];

int n;
int sz[N];
void DFS(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		sz[v] += sz[u];
	}
}

int centroid(int v, int p = -1){
	for (auto u: g[v]) if (u != p){
		if (sz[u] > n / 2) return centroid(u, v);
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);
	cout << centroid(1);
	return 0;
}