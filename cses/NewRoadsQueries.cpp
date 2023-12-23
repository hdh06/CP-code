#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

int n, m, q;

int lk[N];
int find(int v){return lk[v] = lk[v] == v? v: find(lk[v]);}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	lk[a] = b;
	return true;
}

#define st first
#define nd second

vector<pair<int, int> > g[N];

int p[N][L], h[N], maxx[N][L];

void DFS(int v){
	for (auto e: g[v]) if (e.st != p[v][0]){
		int u = e.st, w = e.nd;
		h[u] = h[v] + 1;
		p[u][0] = v;
		maxx[u][0] = w;
		for (int i = 1; i < L; i++){
			p[u][i] = p[p[u][i - 1]][i - 1];
			maxx[u][i] = max(maxx[u][i - 1], maxx[p[u][i - 1]][i - 1]);
		}
		DFS(u); 
	}
}

int get(int a, int b){
	int ans = 0;
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i < L; i++) if (k & (1 << i)) ans = max(ans, maxx[b][i]), b = p[b][i];
	
	if (a == b) return ans;
	for (int i = log2(h[a]); i >= 0; i--) 
		if (p[a][i] != p[b][i]){
			ans = max(ans, max(maxx[a][i], maxx[b][i]));
			a = p[a][i], b = p[b][i];
		}
	return max(ans, max(maxx[a][0], maxx[b][0]));
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m >> q;
	iota(lk + 1, lk + n + 1, 1);
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		if (unite(a, b)){
			g[a].push_back({b, i});
			g[b].push_back({a, i});
		}
	}
	
	for (int i = 1; i <= n; i++) if (h[i] == 0) DFS(i);
	
	while (q--){
		int a, b; cin >> a >> b;
		if (find(a) != find(b)) cout << -1;
		else cout << get(a, b);
		cout << "\n";
	}
	return 0;
} 