#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 18;

int n, m;
vector<int> g[N];
int sz[N], p[N][L], h[N], w[N], hldH[N], hld_id[N], id = 1, trv[N], trv_id[N], id_trv = 0;

void DFS(int v){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p[v][0]){
		h[u] = h[v] + 1;
		p[u][0] = v;
		for (int i = 1; i < L; i++)
			p[u][i] = p[p[u][i - 1]][i - 1]; 
		DFS(u);
		sz[v] += sz[u];
	}
}

void HLD(int v){
	if (hldH[id] == 0) hldH[id] = v;
	hld_id[v] = id;
	trv[v] = ++id_trv;
	trv_id[id_trv] = v;
	int maxU = -1;
	for (auto u: g[v]) if (u != p[v][0])
		if (maxU == -1 || sz[u] > sz[maxU]) maxU = u;
	
	if (maxU != -1)
		HLD(maxU);
	
	for (auto u: g[v]) if (u != p[v][0] && u != maxU){
		id++;
		HLD(u);
	}
}

int tree[N << 2];
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = w[trv_id[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
void upd(int k, int val, int x = 1, int l = 1, int r = n){
	if (k < l || r < k) return;
	if (l == r){
		tree[x] = val;
		return;
	}
	int mid = (l + r) >> 1;
	upd(k, val, 2 * x, l, mid);
	upd(k, val, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}
int get(int L, int R, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return 0;
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}
int getM(int a, int b){
	int ans = 0;
	while (hld_id[a] != hld_id[b]){
		if (h[hldH[hld_id[a]]] > h[hldH[hld_id[b]]]) swap(a, b);
		ans = max(ans, get(trv[hldH[hld_id[b]]], trv[b]));
		b = p[hldH[hld_id[b]]][0];
	}
	if (h[a] > h[b]) swap(a, b);
	return max(get(trv[a], trv[b]), ans);
}
int main(){
	// freopen("inp.inp", "r", stdin);
	// freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;		
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);
	HLD(1);

	build();

	while (m--){
		int t; cin >> t;
		if (t == 1){
			int v, x; cin >> v >> x;
			upd(trv[v], x);
		}else{
			int a, b; cin >> a >> b;
			cout << getM(a, b) << " ";
		}
	}
	// cerr << (double)clock() / (double)CLOCKS_PER_SEC << "\n";
	return 0;
}