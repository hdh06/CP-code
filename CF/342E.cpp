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
#define file "fiel"

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

bool const SINGLE_TEST = 1;

int const N = 1e5 + 1;
int const L = 17;

int n, m;
vi g[N];

int h[N], p[L][N], sz[N];

void DFS(int v){
	for (auto u: g[v]) if (u != p[0][v]){
	 	p[0][u] = v;
	 	for (int i = 1; i < L; i++)
	 		p[i][u] = p[i - 1][p[i - 1][u]];
	 		
	 	h[u] = h[v] + 1;
	 	DFS(u);
	}
}

int LCA(int a, int b){
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i < L; i++) if (k & (1 << i)) b = p[i][b];
	
	if (a == b) return a;
	
	for (int i = log2(h[a]); i >= 0; i--)
		if (p[i][a] != p[i][b]) 
			a = p[i][a], b = p[i][b];
	return p[0][a];
}
int dis(int a, int b){
	return h[a] + h[b] - 2 * h[LCA(a, b)];
}

bool rmv[N]; 

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

int par[N];

void build(int v, int p = -1){
	int n = szCal(v, p);
	int c = ctr(v, p, n);
	// debug(v, c, n);
	
	par[c] = p;
	rmv[c] = 1;
	for (auto u: g[c]) if (!rmv[u])
		build(u, c);
}

int ans[N];

bool isRed[N];
void upd(int v){
	int u = v;
	while (u != -1){
		ans[u] = min(ans[u], dis(v, u));
		u = par[u];
	}
}

int get(int v){
	int u = v;
	int res = n;
	while (u != -1){
		res = min(res, ans[u] + dis(v, u));
		// debug(u, ans[u], dis(v, u));
		// debug(h[u], h[v], LCA(u, v), h[LCA(u, v)]);
		u = par[u];
	}
	return res;
}

void solve(){	
	cin >> n >> m;
	for (int i = 2; i <= n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	DFS(1);
	build(1);
	
	fill(ans + 1, ans + n + 1, n);
	
	upd(1);
	// debug(vi(ans + 1, ans + n + 1));
	while (m--){
		int t, v; cin >> t >> v;
		if (t == 1)
			upd(v);
		if (t == 2)
			cout << get(v) << "\n";	
	}	
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!