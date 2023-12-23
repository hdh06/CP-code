#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const K = 500;

int n, k;

vector<int> g[N];

int f[N][K] = {};

void DFS(int v, int p){
	for (auto u: g[v]) if (u != p){
		for (int i = 0; i < k; i++)
			f[u][(i + 1) % k] = f[v][i] + (i == k - 1);
		DFS(u, v);
	}
}

int g[N][k] = {};

void DF2(int v, int p){
	for (auto u: g[v]) if (u )
}


int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		int p; cin >> p;
		if (p == 0) continue;
		g[p].push_back(i);
		g[i].push_back(p);
	}

	DFS(1, 0);

	for (int i = 1; i <= n; i++){

	}
	return 0;
}