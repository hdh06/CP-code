#include <bits/stdc++.h>

using namespace std;


int const N = 1e4 + 1;
int const INF = INT_MAX;

typedef array<int, 2> ii;
typedef vector<ii> graph;

graph g1[N], g2[N], g3[N];

int dis1[N], dis2[N], dis3[N];
int n, m, k;

void dikit(graph g[], int dis[], int s){
	priority_queue<ii> myque;
	bool vis[N] = {};
	for (int i = 1; i <= n; i++) dis[i] = INF;

	dis[s] = 0;
	myque.push({0, s});

	while (!myque.empty()){
		int v = myque.top()[1], wv = -myque.top()[0];

		myque.pop();

		if (vis[v]) continue;
		vis[v] = true;

		if (wv > dis[v]) continue; 

		for (auto pu: g[v]){
			int u = pu[0], w = pu[1];
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				myque.push({-dis[u], u});
			}
		}
	}
}

bool check(int i){
	return dis1[i] != INF && dis2[i] != INF && dis3[i] != INF;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> m >> k;

	while (m--){
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		g1[u].push_back({v, b});
		g2[v].push_back({u, a});
		g3[v].push_back({u, b});
	}

	dikit(g1, dis1, 1);
	dikit(g2, dis2, k);
	dikit(g3, dis3, n);

	int ans = INF;
	for (int i = 1; i <= n; i++) if (check(i) && dis1[i] + dis2[i] < 60){
		ans = min(ans, dis1[i] + dis3[i]);
	}

	cout << ans;
}