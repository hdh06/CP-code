#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k1, k2;

int const N = 2e5 + 1;

vector<int> g[N];

int tree[N];
void upd(int x, int k){
	for (int i = x; i < N; i += (i & -i)) tree[i] += k;
}
int get(int x){
	int ans = 0;
	for (int i = x; i > 0; i -= (i & -i)) ans += tree[i];
	return ans;
}

int sz[N]; bool done[N];
int DFS(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p && !done[u])
		sz[v] += DFS(u, v);
	return sz[v];
}

int ctr(int v, int p, int n){
	for (auto u: g[v]) if (u != p && !done[u])
		if (sz[u] > n / 2) return ctr(u, v, n);
	return v;
}

ll ans = 0;
int maxl = 0;

void DF2(int v, int p, int d){
	ans += get(k2 - d) - get(k1 - d - 1);
	// cout << "vertex " << v << " depth " << d << " curr_ans " << ans << " delta " << get(k2 - d)<< " - " << get(k1 - d - 1) << "\n";
	for (auto u: g[v]) if (u != p && !done[u])
		DF2(u, v, d + 1);
}

void DF3(int v, int p, int d){
	upd(d, 1); maxl = max(maxl, d);
	if (k1 <= d && d <= k2) ans += 1;
	for (auto u: g[v]) if (u != p && !done[u])
		 DF3(u, v, d + 1);
}

void build(int v, int p = -1){
	int n = DFS(v);
	int c = ctr(v, p, n);
	done[c] = 1;
	if (p == -1) p = c;

	maxl = 0;
	// cout << c << ":\n";
	for (auto u: g[c]) if (!done[u]){
		// cout << "fre ";for (int i = 1; i <= n; i++) cout << get(i) << " \n"[i == n];
		DF2(u, c, 1);
		DF3(u, c, 1);
	}

	for (int i = 1; i <= maxl; i++) upd(i, - get(i));

	for (auto u: g[c]) if (!done[u])
		build(u, c);
}

int main(){
	cin >> n >> k1 >> k2;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	build(1);

	cout << ans;
	return 0;
}