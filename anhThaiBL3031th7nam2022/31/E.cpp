#include <bits/stdc++.h>

using namespace std;

int const N = 2001;

int main(){
	int n, k; cin >> n >> k;
	int a[N];
	for (int i = 1; i <= n; i++) cin >> a[i];

	int dis[N] = {};
	memset(dis, 0x3f , sizeof dis);
	bool vis[N] = {};

	priority_queue<array<int, 2> > que;
	dis[0] = 0;
	que.push({0, 0});
	while (!que.empty()){
		int v = que.top()[1];
		que.pop();

		if (vis[v]) continue;
		vis[v] = true;

		for (int i = 1; i <= n; i++){
			int u = (v + a[i]) % a[1];
			if (dis[u] > dis[v] + a[i]){
				dis[u] = dis[v] + a[i];
				que.push({-dis[u], u});
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < a[1]; i++){
		if (dis[i] == INT_MAX) continue;
		if (k <= dis[i]) ans = min(ans, dis[i]);
		else ans = min(ans, dis[i] + ((k - dis[i]) / a[1] + ((k - dis[i]) % a[1] != 0)) * a[1]);
	}
	cout << ans;
	return 0;
}