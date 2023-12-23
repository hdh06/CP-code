#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

vector<int> graph[N];

int dem[N] = {};

void DFS(int v, int p){
	for (auto u: graph[v]) if (u != v) {
		DFS(u, v);
		dem[v] += dem[u];
	}

}

int main(){
	int n;
	cin >> n;	

	for (int i = 2; i <= n; i++){
		int v; cin >> v;
		graph[v].push_back(i);
	}

	for (int i = 1; i <= n; i++) dem[i] = 1;

	DFS(1, 0);

	for (int i = 1; i <= n; i++) cout << dem[i] - 1 << " ";
	return 0;
}