#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;

set<int> g[N];
int k;
int sz[N];
ll fre[N] = {1};
int DFS(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p)
		sz[v] += DFS(u, v);
	return sz[v];
}

int ctr(int v, int p, int n){
	for (auto u: g[v]) if (u != p)
		if (sz[u] > n / 2) return ctr(u, v, n);
	return v;
}

ll ans = 0;
int f[N] = {};

void DF2(int v, int p, int n){
	if (0 <= k - f[v] && k - f[v] <= n) ans += fre[k - f[v]];
	for (auto u: g[v]) if (u != p){
		f[u] = f[v] + 1;
		DF2(u, v, n);
	}
}

void DF3(int v, int p, int n){
	if (f[v] <= n) fre[f[v]] += 1;
	for (auto u: g[v]) if (u != p)
		DF3(u, v, n);
}

void build(int v, int p = -1){
	int n = DFS(v);
	int c = ctr(v, p, n);
	if (p == -1) p = c;

	vector<int> tmp(g[c].begin(), g[c].end());
	for (int i = 1; i <= n; i++) fre[i] = 0;
	for (auto u: tmp){
		f[u] = 1;
		DF2(u, c, n);
		DF3(u, c, n);
	}

	for (auto u: tmp){
		g[c].erase(u); g[u].erase(c);
		build(u, c);
	}
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}	

	build(1);

	cout << ans;
	return 0;
}