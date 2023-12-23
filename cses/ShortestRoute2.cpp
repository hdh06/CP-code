#include <bits/stdc++.h>

using namespace std;

int const N = 501;
long long const INF = 1e16;
typedef long long ll;

int main(){
	int n, m, q;
	cin >> n >> m >> q;

	ll dis[N][N];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}

	while (m --){
		int a, b; ll c;
		cin >> a >> b >> c;
		dis[a][b] = min(dis[a][b], c);
		dis[b][a] = min(dis[b][a], c);
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}

	while (q--){
		int u , v;
		cin >> u >> v;
		cout << (dis[u][v] == INF? -1: dis[u][v]) << endl;
	}

	return 0;
}