#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int n, q;
vector<int> g[N];
int trv[N], id = 0, sz[N], h[N], w[N];

void DFS(int v, int p = 0){
	trv[v] = ++id, sz[v] = 1;
	for (auto u: g[v]) if (u != p){
		h[u] = h[v] + 1; 
		DFS(u, v);
		sz[v] += sz[u];
	}
}

int tree[2][N];
void upd(bool z, int k, int val){
	for (int i = k; i < N; i += (i & -i)) tree[z][i] += val;
}
int get(bool z, int k){
	int ans = 0;
	for (int i = k; i > 0; i -= (i & -i)) ans += tree[z][i];
	return ans;
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);
	// for (int i = 1; i <= n; i++)
	// 	cout << trv[i] << " \n"[i == n];
	// for (int i = 1; i <= n; i++)
	// 	cout << sz[i] << " \n"[i == n];
	// for (int i = 1; i <= n; i++)
	// 	cout << h[i] << " \n"[i == n];

	for (int i = 1; i <= n; i++){
		upd(h[i] & 1, trv[i], w[i]);
		upd(h[i] & 1, trv[i] + 1, -w[i]);
	}

	while (q--){
		int t; cin >> t;
		if (t == 1){
			int v, val; cin >> v >> val;
			upd(h[v] & 1, trv[v], val);
			upd(h[v] & 1, trv[v] + sz[v], -val);
			upd(!(h[v] & 1), trv[v], -val);
			upd(!(h[v] & 1), trv[v] + sz[v], val);
		}else{
			int v; cin >> v;
			cout << get(h[v] & 1, trv[v]) << "\n";
		}
	}
	return 0;
}