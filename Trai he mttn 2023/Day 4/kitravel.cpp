#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, k, x;

vector<pair<int, int> > g[N];
#define st first
#define nd second

int maxx[N], h[v];

void DFS(int v, int p = -1){
	for (auto u: g[v]) if (p != u.st){
		h[u] = h[v] + u.nd;
		DFS(u.st, v);
		
		
	}
}

int main(){
	cin >> n >> k >> x;
	for (int i = 1; i <= n - 1; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	
	return 0;
}