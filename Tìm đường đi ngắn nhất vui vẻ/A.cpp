#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;
typedef pair<ll, ll> ii;

#define st first
#define nd second

int n, m;
int p[N];
ll dis[N];
bool vis[N];

vector<ii> g[N];

int main(){
	cin >> n >> m;
	while (m--){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	fill(dis + 1, dis + n + 1, LLONG_MAX);
	dis[1] = 0; p[1] = 0;
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
				p[u] = v;
				que.push({-dis[u], u});
			}
		}
	}

	if (dis[n] == LLONG_MAX){
		cout << -1;
		return 0;
	}

	vector<int> path;
	for (int j = n; j > 0; j = p[j])
		path.push_back(j);
	
	reverse(path.begin(), path.end());
	for (auto v: path) cout << v << " ";
	return 0;
}