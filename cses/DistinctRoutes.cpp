#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 501;

int n, m;
int cap[N][N], flow[N][N];
vector<int> g[N];

int lv[N];
bool bfs(){
	memset(lv, 0, sizeof lv);
	lv[1] = 1;
	queue<int> que;
	que.push(1);
	while (!que.empty()){
		int v = que.front(); que.pop();
		for (auto u: g[v]) if (!lv[u] && cap[v][u] - flow[v][u] > 0){
			lv[u] = lv[v] + 1;
			que.push(u);
		}
	}
	
	return !!lv[n];
}

int nxt[N];
int dfs(int v, int minn){
	if (v == n) return minn;
	for (int &i = nxt[v]; i < g[v].size(); i++){
		int u = g[v][i];
		if (lv[u] != lv[v] + 1 || cap[v][u] - flow[v][u] == 0) continue;
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
		
		while (int ans = dfs(1, INT_MAX)) mf += ans;
	}
	return mf;
}

int par[N];
bool trace(int v){
	if (v == n) return 1;
	for (auto u: g[v]) if (flow[v][u] == 1){
		int x = trace(u);
		if (!x) continue;
		par[u] = v;
		return 1;
	}
	return 0;
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b;
		cap[a][b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	cout << max_flow() << "\n";
	
	while (trace(1)){
		par[1] = 1;
		vector<int> ans;
		ans.push_back(n);
		for (int i = n; par[i] != i; i = par[i]){
			flow[par[i]][i]--;
			ans.push_back(par[i]);
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (auto x: ans) cout << x << " "; cout << "\n";
		memset(par, 0, sizeof par);
	}
	
	return 0;
}