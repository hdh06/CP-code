#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int w[N];

vector<int> g[N];

map<int, int> f[N][2];

vector<int> g(int n){
	vector<int> ans;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0) ans.push_back(i);
		while (n % i == 0) n /= i;
	}
	if (n > 0) ans.push_back(n);
	return ans;
}

int ans = 0;

void DFS(int v, int p){
	for (auto u: g[v]) if (u != p){
		DFS(v);
		for (auto i: g(w[v])){
			int &a = f[v][0][i];
			int &b = f[v][1][i];
			int c = f[u][0][i] + 1;
			int d = f[u][1][i] + 1;
			if (c > a) a = c, b = max(d, a);
			else b = max(b, c);
			ans = max(ans, a + b);
		}
	}
}

int main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1, 0);
	cout << ans;
	return 0;
}