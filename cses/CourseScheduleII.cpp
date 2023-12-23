#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, m;
vector<int> g[N];

vector<int> ord;
bool vis[N];
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) 
		DFS(u);
	ord.push_back(v);
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end(), greater<int>());
	
	for (int i = n; i >= 1; i--)
		DFS(i);

	reverse(ord.begin(), ord.end());
	
	for (auto x: ord) cout << x << " ";
	return 0;
}