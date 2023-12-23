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
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "flie"

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

// struct rect{
	// int a, b, c, d, w;
	// rect(){}
	// rect(int a, int b, int c, int d, int w) :a(a), b(b), c(c), d(d), w(w) {}
// };

struct edge{
	int a, b, w;
	edge(){}
	edge(int a, int b, int w) :a(a), b(b), w(w) {}
};

int const N = 2e5 + 1;

int n;
vi g[N], f[N];

// vector<rect> rects;
vector<edge> edges[N];

int in[N], out[N], id = 0;
int h[N];

void DFS(int v, int p = -1){
	in[v] = ++id;
	for (auto u: g[v]) if (u != p){
		h[u] = h[v] + 1;
		DFS(u, v);
	}
	out[v] = id;
}

int tree[N << 2];
int lz[N << 2];

void down(int x){
	tree[2 * x] += lz[x];
	tree[2 * x + 1] += lz[x];
	lz[2 * x] += lz[x];
	lz[2 * x + 1] += lz[x];
	lz[x] = 0; 
}

void upd(int L, int R, int val, int x = 1, int l = 1, int r = n){
	if (R < L) return;
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		tree[x] += val;
		lz[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	down(x);
	// if (mid >= L)
		upd(L, R, val, 2 * x, l, mid);
	// if (mid + 1 <= R)
		upd(L, R, val, 2 * x + 1, mid + 1, r);
	tree[x] = max(tree[2 * x], tree[2 * x + 1]);
}

void push_rect(int a, int b, int c, int d, int w){
	edges[b].pb(edge(a, c, w));
	edges[d].pb(edge(a, c, -w));
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	DFS(1);
	
	for (int i = 1; i <= n; i++)
		for (auto u: g[i]) f[i].pb(in[u]);
	
	
	int q; cin >> q;
	while (q--){
		int a, b, w; cin >> a >> b >> w;
		if (h[a] > h[b]) swap(a, b);
		if (in[a] <= in[b] && in[b] <= out[a]){
			int k = ub(all(f[a]), in[b]) - f[a].begin() - 1;
			// debug(f[a], in[b], k);
			push_rect(1, f[a][k] - 1, in[b], out[b], w);
			push_rect(in[b], out[b], out[b] + 1, n, w);
		}else{
			if (out[a] < in[b])
				push_rect(in[a], out[a], in[b], out[b], w);
			else
				push_rect(in[b], out[b], in[a], out[a], w);
		}
	}
	
	
	// for (auto x: rects){
		// edges[x.b].pb(edge(x.a, x.c, x.w));
		// edges[x.d].pb(edge(x.a, x.c, -x.w));
		// // debug(x.a, x.b, x.c, x.d, x.w);
	// }
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (auto x: edges[i])
			upd(x.a, x.b - 1, x.w);
		
		// debug(tree[1]);
		ans = max(ans, tree[1]);
	}

	cout << ans;	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!