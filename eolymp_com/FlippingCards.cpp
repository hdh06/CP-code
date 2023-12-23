#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;
vector<int> graph[N], rg[N];
vector<bool> isvisited;
vector<int> topo_sort, ids, answers;
int id = 0, n, m;

void init(int n){
	isvisited.assign(2*n,0);
	ids.assign(2*n,0);
	answers.assign(n,0);
	for (int i = 1; i <= n; i++){
		graph[i].clear();
	}
	topo_sort.clear();
}

void add_edge(int v, int u){
	graph[v + m].push_back(u);
	graph[u + m].push_back(v);
	graph[v].push_back(u + m);
	graph[u].push_back(v + m); 
}

void topo(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		topo(u);
	}

	topo_sort.push_back(v);
}

void DFS(int v){
	if (ids[v] != 0) return;
	ids[v] = id;

	for (auto u: graph[v]){
		DFS(u);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		m = 2*n;
		init(m);

		for (int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
			add_edge(u,v);
		}

		for (int i = 1; i <= m; i++){
			topo(i);
		}

		reverse(topo_sort.begin(), topo_sort.end());

		for (auto u: topo_sort){
			if (ids[u] == 0) id++;
			DFS(u);
		}

		bool kt = false;
		for (int i = 1; i <= m; i++){
			if (ids[i] == ids[i + m]){
				cout << "impossible" << endl;
				i = m + 1;
				kt = true;
			}
		}

		for (int i = 1; i <= 2*m; ++i)
		{
			cout << i << "id" << ids[i] << " ";
		}
		cout << endl;

		if (kt == false) cout << "possible" << endl;

	}
	return 0;
}
/*
3
3
1 2
1 3
2 3
3
1 2
1 2
1 2
1
1 1
*/