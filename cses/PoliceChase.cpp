#include <bits/stdc++.h>

using namespace std;

int const N = 501;

int n, m; 
vector<int> g[N];
int cap[N][N], flow[N][N];

int lv[N];

bool bfs(int s, int t){
	memset(lv, 0, sizeof lv);
	queue<int> que;
	que.push(s);
	
	while (!que.empty()){
		int v = que.front();
		que.pop();
		for (auto u: g[v]) if (!lv[u] && u != s && cap[v][u] - flow[v][u] > 0)
			que.push(u), lv[u] = lv[v] + 1;
	}
	return !!lv[t];
}

int nxt[N];

int dfs(int v, int minn){
	// cerr << v << " " << minn << "\n";
	if (v == n) return minn;
	
	for (int &i = nxt[v]; i < g[v].size(); i++){
		int u = g[v][i];
		if (lv[u] != lv[v] + 1 || cap[v][u] - flow[v][u] == 0)
			continue;
		int ans = dfs(u, min(minn, cap[v][u] - flow[v][u]));
		if (!ans) continue;
		flow[v][u] += ans;
		flow[u][v] -= ans;
		return ans;
	}
	return 0;
}

int max_flow(){
	int ans = 0;
	while (bfs(1, n)){
		memset(nxt, 0, sizeof nxt);
		
		while (int z = dfs(1, INT_MAX))
			ans += z;
	}
	return ans;
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b;
		cap[a][b] ++;
		cap[b][a] ++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = max_flow();
	cout << ans << "\n";

	queue<int> que;
	que.push(1);
	bool is[N] = {};
	while (!que.empty()){
		int v = que.front(); que.pop();
		if (is[v]) continue;
		is[v] = 1;
		for (auto u: g[v]) if (cap[v][u] - flow[v][u] > 0)
			que.push(u);
	}
	
	for (int i = 1; i <= n; i++)
		for (auto u: g[i])
			if (is[i] && !is[u])
				cout << i << " " << u << "\n";
	
	return 0;
}