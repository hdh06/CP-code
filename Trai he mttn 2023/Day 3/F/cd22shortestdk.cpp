#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int const K = 19;

int n, m, k;
vector<pair<int, int> > g[N];
#define st first
#define nd second

ll dis[N][K];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m >> k;
	while (m--){
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}

	priority_queue<array<ll, 3> > que;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) dis[i][j] = LLONG_MAX;

	que.push({0, 1, k});
	dis[1][k] = 0;
	while (!que.empty()){
		int v = que.top()[1], curr = que.top()[2];
		que.pop();

		for (auto u: g[v]){
			if (dis[u.st][curr] > dis[v][curr] + u.nd){
				dis[u.st][curr] = dis[v][curr] + u.nd;
				que.push({-dis[u.st][curr], u.st, curr});
			}
			if (curr && dis[u.st][curr - 1] > dis[v][curr]){
				dis[u.st][curr - 1] = dis[v][curr];
				que.push({-dis[u.st][curr - 1], u.st, curr - 1});
			}
		}
	}

	for (int i = 1; i <= n; i++){
		ll minn = LLONG_MAX;
		for (int j = 0; j <= k; j++) 
			minn = min(minn, dis[i][j]);
		cout << minn << " ";
	}
	return 0;
}
