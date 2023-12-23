#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 19;

int n, m;
vector<int> g[N];

int d[N], p[N][L], w[N];

void DFS(int v){
	for (auto u: g[v]) if (u != p[v][0]){
		d[u] = d[v] + 1;
		p[u][0] = v;
		for (int j = 1; j < L; j++)
			p[u][j] = p[p[u][j - 1]][j - 1]; 
		DFS(u);
	}
}

int LCA(int a, int b){
	if (d[a] > d[b]) swap(a, b);
	int k = d[b] - d[a];
	for (int i = 0; i < L; i++) if (k & (1 << i))
		b = p[b][i];

	if (a == b) return a;
	for (int i = log2(d[a]); i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	return p[a][0];
}

void calc(int v){
	for (auto u: g[v]) if (u != p[v][0]){
		calc(u);
		w[v] += w[u];
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);

	while (m--){
		int a, b; cin >> a >> b;
		int anc = LCA(a, b);

		w[a]++, w[b]++;
		w[anc] --, w[p[anc][0]] --;
	}

	calc(1);

	for (int i = 1; i <= n; i++)
		cout << w[i] << " ";
	return 0;
}