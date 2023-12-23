#include <bits/stdc++.h>

using namespace std;

int const N = (2 << 15) + 1;

vector<array<int, 2> > graph[N];

vector<int> path;

int n, rn;

int out[N];

void build(){
	for (int i = 0; i < rn; i++){
		int new_node = (i << 1)&(~rn);
		graph[i].push_back({new_node, 0});
		graph[i].push_back({new_node + 1, 1});
		out[i] = 2;
	}
}

void DFS(int v){
	while(out[v] > 0){
		array<int,2> new_node = graph[v][--out[v]];
		DFS(new_node[0]);
		path.push_back(new_node[1]);
	}
}

int main(){
	int n;
	cin >> n; 

	rn = pow(2, n - 1);

	build();

	// for (int i = 0; i < rn; i++){
	// 	cout << "[" << i << "]:";
	// 	for (auto x: graph[i]) cout << " {" << x[0] << "," << x[1] << "}";
	// 	cout << endl;
	// }

	DFS(0);

	for (auto i: path) cout << i;
	for (int i = 1; i <= n - 1; i++) cout << '0';
	return 0;
}