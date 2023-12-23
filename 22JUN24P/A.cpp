#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 1e6 + 1;

vector<ii> g[N];
int id = 0, ids[N], clr[N];

void DFS(int v){
	if (ids[v] != 0) return;
	ids[v] = id;
	for (auto u: g[v]) if (u[1] == 0) 
		DFS(u[0]);
}

bool vis[N];

bool DF2(int v, int k = 1){
	if (vis[v]) return true;
	vis[v] = true;
	clr[ids[v]] = k;
	bool ans = true;
	for (auto u: g[v]){
		if (u[1] == 1){
			if (ids[u[0]] == ids[v]) return false;
			if (clr[ids[u[0]]] == k) return false;
			ans &= DF2(u[0], (k == 1? 2: 1));
		} else ans &= DF2(u[0], k);
	}
	return ans;
}

int main(){
	int n, q; cin >> n >> q;
	while (q--){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	for (int i = 1; i <= n; i++) if (ids[i] == 0){
		id++;
		DFS(i);
	}
	
	for (int i = 1; i <= n; i++){
		if (!DF2(i)){
			cout << -1;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++){
		cout << clr[ids[i]] << " ";
	}
	return 0;
}