#include <bits/stdc++.h>

using namespace std;

int const N = 2e6 + 1;
int INF = INT_MAX;

vector<int> g[N];
int arr[1001][1001]; 

int main(){
	int n, m;
	cin >> n >> m;
	int x, y, z, t; cin >> x >> y >> z >> t;

	set<int> p;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			p.insert(arr[i][j]);
		}
	}

	vector<int> b(p.begin(), p.end());
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr[i][j] == 0) continue;
			if (i < n && arr[i + 1][j] != 0){
				g[(i - 1)*1000 + j - 1].push_back(i*1000 + j - 1);
				g[i*1000 + j - 1].push_back((i - 1)*1000 + j - 1);
			}
			if (j < m && arr[i][j + 1] != 0){
				g[(i - 1)*1000 + j - 1].push_back((i - 1)*1000 + j);
				g[(i - 1)*1000 + j].push_back((i - 1)*1000 + j - 1);
			}
			int k = lower_bound(b.begin(), b.end(), arr[i][j]) - b.begin();
			g[(i - 1)*1000 + j - 1].push_back(1000000 + k);
			g[1000000 + k].push_back((i - 1)*1000 + j - 1);
		}
	}

	priority_queue<array<int, 2> > myque;
	bool vis[N] = {};
	int dis[N] = {};
	for (int i = 0; i < N; i++) dis[i] = INF;
	dis[(x - 1)*1000 + y - 1] = 0;
	myque.push({0, (x - 1)*1000 + y - 1});

	while (!myque.empty()){
		int v = myque.top()[1];
		myque.pop();

		if (vis[v]) continue;
		vis[v] = true;

		if (v == (z - 1)*1000 + t - 1) continue;

		for (auto u: g[v]){
			if (dis[u] > dis[v] + (v < 1000000)){
				dis[u] = dis[v] + (v < 1000000);
				myque.push({-dis[u], u});
			}
		}
	}

	cout << dis[(z - 1)*1000 + t - 1];
	return 0;
}