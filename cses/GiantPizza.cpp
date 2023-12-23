#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;
vector<int> graph[N], rg[N];
bool isvisited[N];
vector<int> topo_sort; int ids[N]; bool answers[N];
int id = 0;
int m, n;

void add_edge(int da, int a, int db, int b){
	graph[da == '+'?a + m : a].push_back(db == '+'?b : b + m);
	graph[db == '+'?b + m : b].push_back(da == '+'?a : a + m);
	rg[db == '+'?b : b + m].push_back(da == '+'?a + m : a);
	rg[da == '+'?a : a + m].push_back(db == '+'?b + m : b);
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

	for (auto u: rg[v]){
		DFS(u);
	}
}

int main(){

	cin >> n >> m;
	for (int i = 0; i < n; i++){
		char da, db; int a, b;
		cin >> da >> a >> db >> b;
		add_edge(da,a,db,b);
	}

	for (int i = 1; i <= 2*m; i++){
		topo(i);
	}

    reverse(topo_sort.begin(), topo_sort.end());

	for (auto v: topo_sort){
		if (ids[v] == 0) id++;
		DFS(v);
	}

	for (int i = 1; i <= m; i++){
		if (ids[i] == ids[i + m]){
			cout << "IMPOSSIBLE";
			return 0;
		}
		if (ids[i] > ids[i + m]) answers[i] = true;
		else answers[i] = false;
	}

	for (int i = 1; i <= m; ++i)
	{
		cout << (answers[i]? '+':'-') << " ";
	}
	return 0;
}