#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int root;
vector<int> g[N];
vector<int> ans[N];

int id = 1;

void DFS(int v, int p = 0, int clr = 1){
	ans[clr].push_back(v);
	bool yet = 0;
	for (auto u: g[v]) if (u != p){
		DFS(u, v, yet? ++id: clr);
		yet = 1;
	}
}

void solve(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x == i) root = i;
		else{
			g[x].push_back(i);
			g[i].push_back(x);
		}
	}

	id = 1;
	for (int i = 1; i <= n; i++) ans[i].clear();
	DFS(root);
	cout << id << "\n";
	for (int i = 1; i <= id; i++){
		cout << ans[i].size() << "\n";
		for (auto x: ans[i]) cout << x << " "; cout << "\n";
	}

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}