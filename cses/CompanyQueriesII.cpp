#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

vector<int> g[N];

int up[N][L] = {}, h[N] = {}, n , q;

int log2(int k){
	int ans = 0, dem = 0;
	while (k > 0){
		if (k & 1) ans = dem;
		k >>= 1;
		dem++;
	}
	return dem - 1;
}

void DFS(int v, int p){
	for (auto u: g[v]) if (u != p){
		h[u] = h[v] + 1;

		up[u][0] = v;
		for (int j = 1; j < L; j++)
			up[u][j] = up[up[u][j - 1]][j - 1];

		DFS(u, v);
	}
}

int LCA(int a, int b){
	if (h[a] != h[b]){
		if (h[a] > h[b]) swap(a, b);

		int k = h[b] - h[a];

		for (int j = 0; (1 << j) <= k; j++){
			if (k >> j & 1) b = up[b][j];
		}
	}

	if (a == b) return a;

	// cout << a << " " << b << " " << h[a] << " " << h[b] << endl;
	int k = log2(h[a]);
	// cout << k << endl;

	for (int j = k; j >= 0; j--){
		if (up[a][j] != up[b][j])
			a = up[a][j], b = up[b][j];
		// cout << a << " " << b << endl;
	}
	
	return up[a][0];
}


int main(){
	cin >> n >> q;
	
	for (int i = 2; i <= n; i++){
		int v; cin >> v;
		g[v].push_back(i);
	}

	DFS(1, 0);

	while (q--){
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b) << endl;
	}

	return 0;
}