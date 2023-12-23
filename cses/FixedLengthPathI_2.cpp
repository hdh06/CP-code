#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;

int n, k;
vector<int> g[N];

int sz[N];
bool rmv[N];

int cnt[N];

ll ans = 0;

int szCal(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p && !rmv[u])
		sz[v] += szCal(u, v);
	return sz[v];
}

int ctr(int v, int p, int n){
	for (auto u: g[v]) if (u != p && !rmv[u])
		if (sz[u] > n / 2) return ctr(u, v, n);
	return v;
}

void countKpath(int v, int p, int h, int n){
	if (k > h && k - h <= n) ans += cnt[k - h];
	if (k == h) ans++;
	for (auto u: g[v]) if (u != p && !rmv[u])
		countKpath(u, v, h + 1, n);
}

void calcDepth(int v, int p, int h){	
	cnt[h]++;
	for (auto u: g[v]) if (u != p && !rmv[u])
		calcDepth(u, v, h + 1);
	
}

void build(int v, int p = -1){
	int n = szCal(v, p);
	int c = ctr(v, p, n);
	
	rmv[c] = 1;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (auto u: g[c]) if (u != p && !rmv[u]){
		countKpath(u, c, 1, n);
		calcDepth(u, c, 1);
	}
	
	for (auto u: g[c]) if (u != p && !rmv[u])
		build(u, c);
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	
	
	build(1);
	
	cout << ans;
	
	return 0;
}