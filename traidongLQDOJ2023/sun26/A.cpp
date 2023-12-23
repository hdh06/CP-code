#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
// #define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "A"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const N = 1e5 + 1;

int n, q;
int arr[N];

vi g[N];

struct query{
	int id = 0;
	char type;
	int v;
	int a, b;
	query(){}
	query(int id, char type, int v): id(id), type(type), v(v) {}
	query(int id, char type, int a, int b): id(id), type(type), a(a), b(b) {}
};

vector<query> queries[N];
int ans[N];

int tin[N], id = 0, hldH[N], hldId[N], hid = 1, sz[N], h[N], p[N];

void DFS(int v){
	for (auto u: g[v]) if (u != p[v]){
		h[u] = h[v] + 1;
		p[u] = v;
		DFS(u);
		sz[v] += sz[u];
	}
	sz[v]++;
}

void HLD(int v){
	hldId[v] = hid;
	if (!hldH[hid]) hldH[hid] = v;
	tin[v] = ++id;
	int maxU = 0;
	for (auto u: g[v]) if (u != p[v] && sz[u] > sz[maxU])
		maxU = u;
	
	if (!maxU) return;
	HLD(maxU);
	for (auto u: g[v]) if (u != p[v] && u != maxU){
		hid++;
		HLD(u);
	}
	
	// tut[v] = id;
}

struct node{
	int minn, mL, mR, sz;
	node(){}
	node(int minn, int mL, int mR, int sz):minn(minn) , mL(mL), mR(mR), sz(sz){}
	
	void rev(){if (mL != -1) mL = sz - mL + 1, mR = sz - mR + 1;}
};

void minimize(int &x, int val){
	if (val == -1) return;
	if (x == -1 || x > val) x = val;
}
node merge(node a, node b){
	if (a.sz == 0) return b;
	if (b.sz == 0) return a;
	node c(-1, -1, -1, 0);
	minimize(c.minn, a.minn); minimize(c.minn, b.minn);
	if (a.mL != -1 && b.mL != -1){
		// debug(a.mR, b.mL);
		minimize(c.minn, b.mL + a.sz - a.mR);
	}
	if (a.mL != -1) c.mL = a.mL;
	else if (b.mL != -1) c.mL = b.mL + a.sz;
	if (b.mR != -1) c.mR = b.mR + a.sz;
	else if (a.mR != -1) c.mR = a.mR;
	c.sz = a.sz + b.sz;
	return c;
}

node tree[N << 2];
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = node(-1, -1, -1, 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}
void upd(int pos, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		if (tree[x].mL == -1)
			tree[x] = node(-1, 1, 1, 1);
		else
			tree[x] = node(-1, -1, -1, 1);
		return;
	}
	
	int mid = (l + r) >> 1;
	upd(pos, 2 * x, l, mid);
	upd(pos, 2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}
node get(int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return node(-1, -1, -1, 0);
	if (L <= l && r <= R) return tree[x];
	int mid = (l + r) >> 1;
	return merge(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
}

// void debugTree(int x = 1, int l = 1, int r = n){
	// debug(x, l, r);
	// debug(tree[x].minn, tree[x].mL, tree[x].mR, tree[x].sz);
	// if (l == r) return;
	// int mid = (l + r) >> 1;
	// debugTree(2 * x, l, mid);
	// debugTree(2 * x, mid + 1, r);
// }
// 
int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];	
	
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	DFS(1);
	HLD(1);
	
	for (int i = 1; i <= n; i++)
		queries[arr[i]].pb(query(0, 'U', i));
	
	for (int i = 1; i <= q; i++){
		ans[i] = -2;
		char type; cin >> type;
		if (type == 'U'){
			int v, c; cin >> v >> c;
			queries[arr[v]].pb(query(i, 'U', v));
			arr[v] = c;
			queries[arr[v]].pb(query(i, 'U', v));
		}
		if (type == 'Q'){
			int a, b, c; cin >> a >> b >> c;
			queries[c].pb(query(i, 'Q', a, b));
		}
	}
	
	build();
// 	
	// debug(vi(hldH + 1, hldH + n + 1));
	// debug(vi(hldId + 1, hldId + n + 1));
	// debug(vi(tin + 1, tin + n + 1));
	
	for (int i = 1; i <= n; i++){
		// debug(i);
		for (auto x: queries[i]){
			// debug(x.id, string(1, x.type), x.v, x.a, x.b);
			if (x.type == 'U'){
				upd(tin[x.v]);
			}
			if (x.type == 'Q'){
				int a = x.a, b = x.b;
				node L(-1, -1, -1, 0), R(-1, -1, -1, 0);
				if (tin[a] > tin[b]) swap(a, b);
				while (hldId[a] != hldId[b]){
					if (h[hldH[hldId[a]]] < h[hldH[hldId[b]]]){
						R = merge(get(tin[hldH[hldId[b]]], tin[b]), R);
						b = p[hldH[hldId[b]]];
					}else{
						L = merge(get(tin[hldH[hldId[a]]], tin[a]), L);
						a = p[hldH[hldId[a]]];
					}	
				}
				// debug(a, b);
				// debugTree();
				
				L.rev();
				// debug(L.minn, L.mL, L.mR, L.sz);
				// debug(R.minn, R.mL, R.mR, R.sz);
				node mid;
				if (h[a] < h[b]){
					mid = get(tin[a], tin[b]);
					L = merge(L, mid);
					L = merge(L, R);
				}else{
					mid = get(tin[b], tin[a]); 
					// debug(mid.minn, mid.mL, mid.mR, mid.sz);
					mid.rev();
					L = merge(L, mid);
					L = merge(L, R);
				}
				// debug(mid.minn, mid.mL, mid.mR, mid.sz);
				// debug(L.minn, L.mL, L.mR, L.sz);
				ans[x.id] = L.minn;
			}
		}
		
		for (auto x: queries[i]) if (x.type == 'U') upd(tin[x.v]);
	}
	
	for (int i = 1; i <= q; i++) if (ans[i] != -2) cout << ans[i] << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!