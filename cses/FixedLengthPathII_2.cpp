#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;

int n, k1, k2;
vector<int> g[N];

int sz[N];
bool rmv[N];

ll ans = 0;

int szCal(int v, int p = -1){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p && !rmv[u])
		sz[v] += szCal(u, v);
	return sz[v];
}

int ctr(int v, int p, int n){
	for (auto u: g[v]) if (u != p && !rmv[u])
		if (sz[u] * 2 > n) return ctr(u, v, n);
	return v;
}

struct BIT{
	int n;
	int tree[N];
	BIT(){}
	BIT(int n) :n(n){}
	void reset(int _n){
		n = _n;
		fill(tree + 1, tree + n + 1, 0);
	}
	
	void upd(int x){for (;x <= n; x += x & -x) tree[x] ++;}
	int get(int x){if (x >= n) x = n;int ans = 0; for(;x > 0; x -= x & -x) ans += tree[x]; return ans;}
} t;

void countKpath(int v, int p, int h){
	if (h > k2) return;
	ans += t.get(k2 - h) - t.get(k1 - h - 1);
	if (k1 <= h && h <= k2) ans++;
	for (auto u: g[v]) if (u != p && !rmv[u])
		countKpath(u, v, h + 1);
}

void calcDepth(int v, int p, int h){	
	if (h > k2) return;
	t.upd(h);
	for (auto u: g[v]) if (u != p && !rmv[u])
		calcDepth(u, v, h + 1);
}

void build(int v, int p = -1){
	int n = szCal(v, p);
	
	int c = ctr(v, p, n);
	
	rmv[c] = 1;
	
	if (n < k1) return;
	
	t.reset(min(k2, n));
	for (auto u: g[c]) if (!rmv[u]){
		countKpath(u, c, 1);
		calcDepth(u, c, 1);
		// debug(t.tree);
	}
	
	for (auto u: g[c]) if (!rmv[u])
		build(u, c);
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
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