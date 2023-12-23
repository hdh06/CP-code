#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int t[N], len[N];
queue<int> path;
bool vis[N];

int dfs(int v){
	path.push(v);
	if (vis[v]) return len[v];
	vis[v] = 1;
	return dfs(t[v]) + 1;
}

int main(){
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> t[i];
		
	for (int i = 1; i <= n; i++){
		int pathLen = dfs(i);
		int del = 1;
		while (!path.empty()){
			if (path.front() == path.back()) del = 0;
			len[path.front()] = pathLen;
			pathLen -= del;
			path.pop();
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << len[i] << " ";
	return 0;
}