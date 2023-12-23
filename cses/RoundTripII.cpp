#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, m;
vector<int> g[N];

int vis[N];

vector<int> path;
stack<int> st;

void DFS(int v){
	if (vis[v] == 2) return;
	if (vis[v] == 1){
		if (path.size() != 0) return;
		path.push_back(v);
		while (st.top() != v){
			path.push_back(st.top());
			st.pop();
		}
		return;
	}
	vis[v] = 1;
	st.push(v);
	for (auto u: g[v])
 		DFS(u);
 	if (path.size() != 0) return;
	st.pop();
	vis[v] = 2;
}

int main(){
	cin >> n >> m;
	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		DFS(i);

	if (path.size() == 0){
		cout << "IMPOSSIBLE";
		return 0;
	}

	reverse(path.begin(), path.end());

	cout << path.size() + 1 << "\n" << path.back() << " ";
	for (auto x: path) cout << x << " ";

	return 0;
}