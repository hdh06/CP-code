#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

vector<int> graph[N], rg[N], DFS_or;
vector<int> DAG[N];
bool isvisited[N];
int ids[N], coin[N]; long long tong[N], dp[N];
priority_queue<pair<long long,int> > myque;
int n, m, id = 0;
long long ans = 0;


void DFSor(int v){
	if (isvisited[v]) return;
	isvisited[v] = true;

	for (auto u: graph[v]){
		DFSor(u);
	}

	DFS_or.push_back(v);
}

void DFS(int v){
	if (ids[v] != 0){
		if(ids[v] != id) DAG[ids[v]].push_back(id);
		return;
	} 
	ids[v] = id;

	for (auto u: rg[v]){
		DFS(u);
	}
}

void BFS(){
	while (!myque.empty()){
		int v = myque.top().second; long long wv = myque.top().first;	
		ans = max(ans, wv);
		myque.pop();

		if (wv < dp[v]) continue;

		for (auto u: DAG[v]){
			if (dp[u] < dp[v] + tong[u]){
				dp[u] = dp[v] + tong[u];
				myque.push({dp[u], u});
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> coin[i];
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		rg[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) DFSor(i);

	reverse(DFS_or.begin(),DFS_or.end());

	for (auto i : DFS_or){
		if (ids[i] == 0){
			id++;
		} 
		DFS(i);
		tong[ids[i]] += coin[i];
	}

	for (int i = 1; i <= n; i++) isvisited[i] = false;

	for (auto x : DFS_or){
		myque.push({tong[x], x});
		dp[x] = tong[x];
	}	

	BFS();
	cout << ans;
	return 0; 
}