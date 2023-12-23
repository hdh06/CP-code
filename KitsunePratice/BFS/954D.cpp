#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

vector<int> g[N];

void BFS(int st, vector<int> &dis){
	dis[st] = 0;

	queue<int> que;
	que.push(st);

	while (!que.empty()){
		int v = que.front(); que.pop();

		for (auto u: g[v]) if (dis[u] == -1){
			dis[u] = dis[v] + 1;
			que.push(u);
		}
	}
}

int main(){	
	int n, m, s, t; cin >> n >> m >> s >> t;
	bool is[N][N] = {};

	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		is[a][b] = 1;
		is[b][a] = 1;
	}

	vector<int> d1(n + 1, -1), d2(n + 1, -1);

	BFS(s, d1);
	BFS(t, d2);

	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++) {
			if (d1[i] == -1 || d2[j] == -1 || d1[j] == -1 || d2[i] == -1) continue;
			if (is[i][j]) continue;
			if (d1[i] + 1 + d2[j] >= d1[t] && d1[j] + 1 + d2[i] >= d1[t]) 
				ans++;
		}
	}

	cout << ans;
	return 0;
}