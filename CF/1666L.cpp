#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int n, m, s;
vector<int> g[N];

int vis[N], par[N];

int x = -1, y = -1;

void DFS(int v, int p){
	if (vis[v] == 1) return;
	if (vis[v] == 2){
		x = p;
		y = v;
		return;
	}
	vis[v] = 1;
	par[v] = p;
	for (auto u: g[v])
		DFS(u, v);
}

void mark(int v){
	if (vis[v] == 2) return;
	if (vis[v] == 0) return;
	vis[v] = 2;
	for (auto u: g[v]) mark(u);
}

int main(){
	cin >> n >> m >> s;
	while (m--){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}

	vis[s] = 1;

	for (auto u: g[s]){
		vis[s] = 1;
		DFS(u, s);
		mark(u);
	}

	if (x == -1){
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";

	vector<int> ans1 = {y}, ans2 = {y};
	for (int i = x; i != 0; i = par[i]) ans1.push_back(i);
	for (int i = par[y]; i != 0; i = par[i]) ans2.push_back(i);

	reverse(ans1.begin(), ans1.end());
	reverse(ans2.begin(), ans2.end());

	cout << ans1.size() << '\n';
	for (auto i: ans1) cout << i << " "; cout << "\n";
	cout << ans2.size() << '\n';
	for (auto i: ans2) cout << i << " "; cout << "\n";
	return 0;
}