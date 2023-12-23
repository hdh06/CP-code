#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

typedef long long ll;
typedef pair<ll, ll> ii;

#define st first
#define nd second

int n, m;
vector<ii> g[N];

ll dis[N], ways[N], minn[N], maxx[N], cnt[N];
bool vis[N];

int main(){
	int n, m; cin >> n >> m;
	while (m--){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}

	fill(dis + 1, dis + n + 1, LLONG_MAX);

	dis[1] = 0;
	ways[1] = 1;
	minn[1] = maxx[1] = 0;

	priority_queue<ii> que;
	que.push({0, 1});

	while (!que.empty()){
		int v = que.top().nd;
		que.pop();

		if (vis[v]) continue;
		vis[v] = 1;

		for (auto e: g[v]){
			int u = e.st, w = e.nd;
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				ways[u] = ways[v];
				minn[u] = minn[v] + 1;
				maxx[u] = maxx[v] + 1;
				que.push({-dis[u], u});
			}else if (dis[u] == dis[v] + w){
				(ways[u] += ways[v]) %= MOD;
				minn[u] = min(minn[u], minn[v] + 1);
				maxx[u] = max(maxx[u], maxx[v] + 1);
			}
		}
	}

	cout << dis[n] << " " << ways[n] << " " << minn[n] << " " << maxx[n] << "\n";
	return 0;
}