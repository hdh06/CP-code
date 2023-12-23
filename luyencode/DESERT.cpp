#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<ll, 2> ii;

int const N = 101;
ll const INF = LLONG_MAX;

vector<ii> g[N]; 

int n, m; ll c;

ll dis[N]; bool vis[N];

int main(){
	freopen("inp.inp", "r", stdin); 
	freopen("out.out", "w", stdout);
	int t; cin >> t;
	while (t --){
		cin >> n >> m >> c;

		for (int i = 1; i <= n; i++) g[i].clear();

		while(m --){
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}

		for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = false;

		priority_queue<ii> myque;
		dis[n] = 0;
		myque.push({0, n});

		while (!myque.empty()){
			// for (int i = 1; i <= n; i++) cout << (dis[i] == INF?-1:dis[i]) << " \n"[i == n];
			int v = myque.top()[1];

			myque.pop();

			if (vis[v]) continue;
			vis[v] = true;

			for (auto e: g[v]){
				int u = e[0]; ll w = e[1];
				if (c - w < 0) continue;
				ll x = -1, h = -1, d = -1;
				if (dis[v] + w > c){
					if (c - 2*w <= 0) continue;
					d = dis[v] + dis[v] % (c - 2*w);
					h = (d - (c - w))/(c - 2*w);
					x = h*c + (dis[v] - h*(c - 2*w) + w);
				} else x = dis[v] + w;

				cout << "[" << v << " -> " << u << "]: " << h << " " << d << " " << x << endl;
				
				if (dis[u] > x){
					dis[u] = x;
					myque.push({-dis[u],u});
				}
			}
		}

		// for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];

		cout << (dis[1] == INF?-1:dis[1]) << endl;
		cout << "______________" << endl;
	}
	return 0;
}