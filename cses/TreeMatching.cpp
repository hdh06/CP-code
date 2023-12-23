#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int n;
vector<int> g[N];

bool vis[N];

int ans = 0;

void DFS(int v, int p){
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		if (vis[u] == 0 && vis[v] == 0){
			vis[v] = vis[u] = 1;
			ans++;
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1, 0);
	cout << ans;
	return 0;
}