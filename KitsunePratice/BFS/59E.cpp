#include <bits/stdc++.h>

using namespace std;

int const N = 3001;

typedef array<int, 2> ii;
typedef array<int, 3> iii;

vector<int> g[N];
map<iii, bool> ban;

int main(){
	int n, m, k; cin >> n >> m >> k;	

	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	while (k--){
		int a, b, c; cin >> a >> b >> c;
		ban[{a, b, c}] = 1;
	}

	int dis[N][N], track[N][N] = {};
	memset(dis, -1, sizeof dis);

	queue<ii> que;
	que.push({0, 1});
	dis[0][1] = 0;
	while (!que.empty()){
		int p = que.front()[0], v = que.front()[1];
		que.pop();
		for (auto u: g[v])
			if (dis[v][u] == -1 && !ban[{p, v, u}]){
				dis[v][u] = dis[p][v] + 1;
				track[v][u] = p;
				que.push({v, u});
			}
	}
	int ans = INT_MAX, a = -1, b = n;
	for (int i = 1; i <= n; i++) if (dis[i][n] != -1){
		if (ans > dis[i][n]){
			ans = dis[i][n];
			a = i;
		}
	}

	if (a == -1){
		cout << -1;
		return 0;
	}

	cout << ans << "\n";
	vector<int> path;
	path.push_back(n);
	while (a != 0){
		path.push_back(a);
		int c = a;
		a = track[a][b];
		b = c;
	}

	reverse(path.begin(), path.end());

	for (auto x: path) cout << x << " ";
	return 0;
}