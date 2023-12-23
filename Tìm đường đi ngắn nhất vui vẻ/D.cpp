#include <bits/stdc++.h>

using namespace std;

int const N = 51;
int const V = 5001;

typedef long long ll;
typedef array<ll, 3> iii;

int n, m, s;
vector<iii> g[N];
ll cpg[N], mpt[N];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m >> s;
	while (m --){
		int u, v, a, b; cin >> u >> v >> a >> b;
		g[u].push_back({v, a, b});
		g[v].push_back({u, a, b});
	}

	for (int i = 1; i <= n; i++)
		cin >> cpg[i] >> mpt[i];
	
	ll dis[N][V];
	for (int i = 0; i < N; i++)
		fill(dis[i], dis[i] + V, LLONG_MAX);
	s = min(V - 1, s);
	dis[1][s] = 0;
	priority_queue<iii> que;
	que.push({0, 1, s});

	bool vis[N][V] = {};
	while (!que.empty()){
		ll v = que.top()[1], curr = que.top()[2];
		que.pop();

		if (vis[v][curr]) continue;
		vis[v][curr] = 1;

		for (auto e: g[v]){
			ll u = e[0], a = e[1], b = e[2];
			if (curr >= a && dis[u][curr - a] > dis[v][curr] + b){
				dis[u][curr - a] = dis[v][curr] + b;
				que.push({-dis[u][curr - a], u, curr - a});
			}
			ll new_curr = min(V - 1LL, curr + cpg[v]);
			if (dis[v][new_curr] > dis[v][curr] + mpt[v]){
				dis[v][new_curr] = dis[v][curr] + mpt[v];
				que.push({-dis[v][new_curr], v, new_curr});
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << *min_element(dis[i], dis[i] + V) << "\n";
	return 0;
}