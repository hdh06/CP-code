#include <bits/stdc++.h>

using namespace std;

int const N = 301;

vector<int> g[N];

int od[N];

void DFS(int v, int p){
	if (v != 1 && g[v].size() == 1) return;
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		od[v] = min(od[v], od[u]);
	}
}

vector<int> path;

void DF2(int v, int p){
	path.push_back(v);
	for (auto u: g[v]) if (u != p){
		DF2(u, v);
		path.push_back(v);
	}
}

int main(){
	int n; cin >> n;	
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) cnt += (g[i].size() == 1);

	memset(od, 0x3f, sizeof od);

	for (int i = 1; i <= cnt; i++){
		int x; cin >> x;
		od[x] = i;
	}

	DFS(1, 0);

	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end(), [](int a, int b){
			return od[a] < od[b];
		});

	// path.push_back(1);
	DF2(1, 0);

	int last = 0;
	for (auto x: path) if (x != 1 && g[x].size() == 1 && od[x] > last){
		last++;
	}

	if (last != cnt) cout << -1;
	else for (auto x: path) cout << x << " ";
	return 0;
}