#include <bits/stdc++.h>

using namespace std;

int const N = 201;

typedef array<int, 2> ii;

vector<ii> graph[N];
vector<ii> path;
int n, m;

void DFS(int v, int w){
	// for (int i = 1; i <= n; i++){
	// 	cout << "[" << i << "]: ";
	// 	for (auto u: graph[i]){
	// 		cout << "{" <<  u[0] << "," << u[1] << "} ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "----------" << endl;
	while (graph[v].size() > 0){
		ii u = graph[v][graph[v].size() - 1];

		graph[v].erase(graph[v].end() - 1);
		auto pos = graph[u[0]].begin();
		for (auto x = graph[u[0]].begin(); x != graph[u[0]].end(); x++){
			ii u = *x;
			if (u[0] == v){
				pos = x;
			}
		}
		graph[u[0]].erase(pos);
		DFS(u[0], u[1]);
	}
	path.push_back({v, w});
}

int main(){
	cin >> n >> m;

	for(int t = m; t--;){
		int u, v, w;
		cin >> u >> v >> w; 

		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int s, max_s = 0;
	for (int i = 1; i <= n; i++){
		if (graph[i].size() % 2 != 0){
			cout <<  -1;
			return 0;
		}
		for (auto x: graph[i]){
			if (x[1] > max_s){
				max_s = x[1];
				s = i;
			}
		}
		sort(graph[i].begin(), graph[i].end(), [](ii a, ii b){return a[1] < b[1];});
	}

	// cout << "BEDBUG:" << s << endl;
	DFS(s, 0);

	reverse(path.begin(), path.end());

	int tong = 0;
	for (auto x: path){
		tong += x[1];
		if (tong < 0){
			cout << -1;
			return 0;
		}
	}

	if (path.size() != (m + 1) || path[0][0] != path[m][0]){
		cout << -1;
		// cout << path.size() << " " << path[0] << " " << path[m] << endl;
		return 0;
	}

	for (auto x: path) cout << x[0] << " ";
	return 0;
}