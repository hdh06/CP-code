#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int n, m;

vector<int> g[N];

bool vis[N];
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) DFS(u);
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);	
	}
	
	int cc = 0;
	for (int i = 1; i <= n; i++){
		cc += !vis[i];
		DFS(i);
	}
	
	cout << mpow(2, m - n + cc);
	return 0;
}
/*brief explaination (m for number of edges, n for number of node, cc for number of connected component)
answer for one connected component: 2 ^ (m - (n - 1)) 
why? because we pick a random subgraph which is a tree in the component 
and there are 2 ^ (m - (n - 1)) ways to add the other edges that not in the subgraph.
since tree adding one or more edges, it will have some loop and an Eulerian graph always have loop
in this tree by removing some edges that belong to the tree it will become an unique Eulerian subgraph
because it must have the edges that we add in which is a unique set of edges for each 2 ^ (m - (n - 1)) set.
answer: 2 ^ (m1 - (n1 - 1)) * 2 ^ (m2 - (n2 - 1)) * ... * (mcc - (ncc - cc))
= 2 ^ (m1 + m2 + ... + mcc - (n1 + n2 + ... + ncc - cc))
= 2 ^ (m - (n - cc))
= 2 ^ (m - n + cc)
*/