#include <bits/stdc++.h>

using namespace std;

int const N = 2501;
long long const INF = N*1e9 + N;
typedef long long ll;
typedef array<int, 3> iii;

vector<iii> edges;
ll dis[N], p[N];

int main(){
	int n, m;

	cin >> n >> m;

	while(m --){
		int u, v, w; 
		cin >> u >> v >> w; 

		edges.push_back({u,v,w});
	} 

	for (int i = 1; i <= n; i++) dis[i] = INF;

	dis[1] = 0;

	int x;

	for (int i = 1; i <= n; i++){
		x = -1;
		for (auto e: edges){
			int u = e[0], v = e[1], w = e[2];
			if (dis[u] + w < dis[v]){
				dis[v] = dis[u] + w; 
				p[v] = u;
				x = v;
			}
		}
	}

	// for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;

	if (x == -1) cout << "NO";
	else{
		for (int i = 1; i <= n; i++){
			x = p[x];
		}
		cout << "YES" << endl;
		vector<int> ans = {x};
		for (int t = p[x]; t != x; t = p[t]){
			ans.push_back(t);
		}
		ans.push_back(x);

		reverse(ans.begin(), ans.end());

		for (auto i: ans) cout << i << " ";
	}
	return 0;
}