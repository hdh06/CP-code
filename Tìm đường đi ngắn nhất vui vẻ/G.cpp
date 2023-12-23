#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;
typedef array<ll, 4> iiii;
typedef pair<int, int> ii;
#define st first
#define nd second

int n, m;
vector<ii> g[N];
ll dis[N][2][2];
bool vis[N][2][2];

priority_queue<iiii> que;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m;
	while (m--){
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}	

	for (int i = 1; i <= n; i++)
		dis[i][0][0] = dis[i][0][1] = dis[i][1][0] = dis[i][1][1] = LLONG_MAX;
	dis[1][0][0] = 0;
	que.push({0, 1, 0, 0});

	while (!que.empty()){
		int v = que.top()[1], t1 = que.top()[2], t2 = que.top()[3];
		que.pop();

		if (vis[v][t1][t2]) continue;
		vis[v][t1][t2] = 1;

		for (auto e: g[v]){
			int u = e.st, w = e.nd;
			if (dis[u][t1][t2] > dis[v][t1][t2] + w){
				dis[u][t1][t2] = dis[v][t1][t2] + w;
				que.push({-dis[u][t1][t2], u, t1, t2});
			}
			if (!t1 && dis[u][1][t2] > dis[v][t1][t2] + w - w){
				dis[u][1][t2] = dis[v][t1][t2] + w - w;
				que.push({-dis[u][1][t2], u, 1, t2});
			}
			if (!t2 && dis[u][t1][1] > dis[v][t1][t2] + w + w){
				dis[u][t1][1] = dis[v][t1][t2] + w + w;
				que.push({-dis[u][t1][1], u, t1, 1});
			}
			if (!t1 && !t2 && dis[u][1][1] > dis[v][t1][t2] + w - w + w){
				dis[u][1][1] = dis[v][t1][t2] + w - w + w;
				que.push({-dis[u][1][1], u, 1, 1});
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << dis[i][1][1] << " ";
	return 0;
}