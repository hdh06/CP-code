#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

vector<int> g[N];

int up[N][L], h[N], n, q;

void DFS(int v){
	for (auto u: g[v]) if (up[v][0] != u){
		h[u] = h[v] + 1;

		up[u][0] = v;
		for (int j = 1; j < L; j++)
			up[u][j] = up[up[u][j - 1]][j - 1];
		
		DFS(u);
	}
}

int log2(int k){
	int dem = 0;
	while (k){
		dem++;
		k >>= 1;
	}
	return dem - 1;
}

int anc(int a, int b){
	if (h[a] != h[b]){
		if (h[a] > h[b]) swap(a, b);

		int k = h[b] - h[a];
		for (int j = 0; (1 << j) <= k; j++)
			if (k >> j & 1) b = up[b][j];
	}

	if (a == b) return a;

	int k = log2(h[a]);
	for (int j = k; j >= 0; j--){
		if (up[a][j] != up[b][j]){
			a = up[a][j], b = up[b][j];
		}
	}

	return up[a][0];
}

int main(){
	cin >> n >> q;
	
	for (int i = 2; i <= n; i++){
		int u, v; 
		cin >> u >> v;

		g[u].push_back(v);		
		g[v].push_back(u);
	}		

	DFS(1);

	while (q--){
		int a, b;
		cin >> a >> b;
		int ances = anc(a, b);
		cout << h[a] + h[b] - 2*h[ances] << endl;
	}
	return 0;
}