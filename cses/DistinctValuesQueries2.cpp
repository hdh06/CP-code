#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

int n;
vector<int> g[N];

int h[N], p[N][L];

void DFS(int v){
	for (auto u: g[v]) if (u != p[v][0]){
		h[u] = h[v] + 1;

		p[u][0] = v;
		for (int j = 1; j < L; j++)
			p[u][j] = p[p[u][j - 1]][j - 1];
 
		DFS(u);
	}
}

int LCA(int a, int b){
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int j = 0; j < L; j++) if (k & (1 << j))
		b = p[b][j];

	if (a == b) return a;
	for (int j = L - 1; j >= 0; j--)
		if (p[a][j] != p[b][j])
			a = p[a][j], b = p[b][j];
	return p[a][0];
}

int main(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);
	return 0;
	
}