#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 18;
int const MOD = 998244353;

#define st first
#define nd second

struct line{
	int a, b;
	line(int _a, int _b){a = _a, b = _b;}
	line(){}
	int calc(int x){
		return (1LL * a * x % MOD + b) % MOD;
	}
};

// f(x) = fx(fy(x)) = (ya * x + yb) * xa + xb
//					= ya * xa * x + yb * xa + xb
line merge(line x, line y, bool type = 0){
	if (type) swap(x, y);
	return line(1LL * x.a * y.a % MOD, ((1LL * y.b * x.a) % MOD + x.b) % MOD);
}

struct segT{
	int n;
	line tree[N << 2];
	int trv_id[N];
	int trv[N];
	segT(int _n){
		n = _n;
	}

	void build(line f[], int x, int l, int r){
		if (l == r){
			tree[x] = f[trv_id[l]];
			return;
		}
		int mid = (l + r) >> 1;
		build(f, 2 * x, l, mid);
		build(f, 2 * x + 1, mid + 1, r);
		tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
	}
	void build(line f[]){build(f, 1, 1, n);}

	void upd(int k, int c, int d, int x, int l, int r){
		if (k < l || r < k) return;
		if (l == r){
			tree[x] = line(c, d);
			return;
		}
		int mid = (l + r) >> 1;
		upd(k, c, d, 2 * x, l, mid);
		upd(k, c, d, 2 * x + 1, mid + 1, r);
		tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
	}
	void upd(int k, int c, int d){upd(k, c, d, 1, 1, n);}
	
	line get(int L, int R, int x, int l, int r){
		if (R < l || r < L) return line(1, 0);
		if (L <= l && r <= R) return tree[x];
		int mid = (l + r) >> 1;
		return merge(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	}
	line get(int L, int R){
		if (L > R) swap(L, R);
		return get(L, R, 1, 1, n);
	}
};

int n, q;
vector<int> g[N];

int sz[N], h[N], p[N][L];
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
pair<bool, int> LCA(int a, int b){
	bool flag = h[a] > h[b];
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i < L; i++) if (k & (1 << i))
		b = p[b][i];

	if (a == b) return {0, a};

	for (int i = L - 1; i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	return {1, (flag? a: b)};
}

int hld_h[N], hld_id[N], id = 1, trv[N], id_trv = 0;

void HLD(int v){
	if (!hld_h[id]) hld_h[id] = v;
	hld_id[v] = id;
	trv[v] = ++id_trv;

	int maxU = 0;
	for (auto u: g[v]) if (u != p[v][0])
		if (!maxU || sz[u] > sz[maxU]) maxU = u;
	
	if (maxU)
		HLD(maxU);
	
	for (auto u: g[v]) if (u != p[v][0] && u != maxU){
		id++;
		HLD(u);
	}
}

int MAXX = 0;

line get(int v, int anc, segT &tree, bool type = 0){
	line ans = line(1, 0);
	while (1){
		if (hld_id[v] == hld_id[anc])
			return merge(tree.get(tree.trv[anc], tree.trv[v]), ans, type);
		ans = merge(tree.get(tree.trv[hld_h[hld_id[v]]], tree.trv[v]), ans, type);
		v = p[hld_h[hld_id[v]]][0];
	}
}

line f[N];

int main(){
	// freopen("inp.inp", "r", stdin);
	// freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		f[i] = line(a, b);
	}

	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		a++, b++;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	DFS(1);
	HLD(1);

	segT tree1(n), tree2(n);
	for (int i = 1; i <= n; i++){
		tree1.trv_id[trv[i]] = i;
		tree2.trv_id[n - trv[i] + 1] = i;
		tree1.trv[i] = trv[i];
		tree2.trv[i] = n - trv[i] + 1;
	}
	tree1.build(f);
	tree2.build(f);

	while (q--){
		int t; cin >> t;
		if (!t){
			int p, c, d; cin >> p >> c >> d;
			p++;
			tree1.upd(trv[p], c, d);
			tree2.upd(n - trv[p] + 1, c, d);
		}else{
			int a, b, x; cin >> a >> b >> x;
			a++, b++;
			pair<bool, int> anc = LCA(a, b);
			line ans;
			if (!anc.st){
				if (a == anc.nd)
					ans = get(b, anc.nd, tree2, 1);
				else ans = get(a, anc.nd, tree1);		
			}else{
				ans = merge(get(b, anc.nd, tree2, 1), get(a, p[anc.nd][0], tree1));
			}
			cout << ans.calc(x) << "\n";
		}
	}
	// cerr << (double) clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}

/*
3 3
1 2
3 2
4 1
0 1
0 2
1 0 1 1
1 0 2 2
1 1 2 3
*/