#include <bits/stdc++.h>

using namespace std;

int const N = 50001;

int m, n;
int match[N], vis[N], t = 0;

vector<int> g[N];

bool DFS(int v){
	if (vis[v] == t) return false;
	vis[v] = t;

	for (auto u: g[v]){
		if (match[u] == 0 || DFS(match[u])){
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> m >> n;
	int k; cin >> k;
	while (k --){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	
	int dem = 0;
	for (int i = 1; i <= m; i++){
		t++;
		dem += DFS(i);
	}

	cout << dem << endl;

	// for (int i = 1; i <= n; i++) if (match[i] != 0) cout << match[i] << " " << i << endl;
	return 0;
}