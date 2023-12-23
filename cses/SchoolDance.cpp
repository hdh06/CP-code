#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 1005;

int n, m, k;

vector<int> g[N];

int cap[N][N], flow[N][N];

int lv[N];
bool bfs(){
	memset(lv, 0, sizeof lv);
	queue<int> que;
	que.push(0);
	while (!que.empty()){
		int v = que.front(); que.pop();
		for (auto u: g[v]) if (!lv[u] && u != 0 && cap[v][u] - flow[v][u] > 0){
			lv[u] = lv[v] + 1;
			que.push(u);
		}
	}
	return !!lv[2 * n + 1];
}

int nxt[N];

int dfs(int v, int minn){
	if (v == 2 * n + 1) return minn;
	for (int &i = nxt[v]; i < g[v].size(); i++){
		int u = g[v][i];
		if (cap[v][u] - flow[v][u] == 0 || lv[u] != lv[v] + 1) continue;
		int ans = dfs(u, min(minn, cap[v][u] - flow[v][u]));
		if (!ans) continue;
		flow[v][u] += ans;
		flow[u][v] -= ans;
		return ans;
	}
	return 0;
}

int max_flow(){
	int mf = 0;
	while (bfs()){
		memset(nxt, 0, sizeof nxt);
		while (int ans = dfs(0, INT_MAX)) mf += ans;
	}
	return mf;
}

int main(){
	cin >> n >> m >> k;
	n = max(n, m);
	while (k--){
		int a, b; cin >> a >> b;
		cap[a][b + n] ++;
		g[a].push_back(b + n);
		g[b + n].push_back(a);
	}
	
	for (int i = 1; i <= n; i++){
		cap[0][i]++, cap[i + n][2 * n + 1]++;
		g[0].push_back(i);
		g[i].push_back(0);
		g[i + n].push_back(2 * n + 1);
		g[2 * n + 1].push_back(i + n);
	}

	cout << max_flow() << "\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) if (flow[i][j + n] == 1){
			debug(cap[i][j + n], flow[i][j + n]);
			cout << i << " " << j << "\n";
		}
	}
	return 0;
}