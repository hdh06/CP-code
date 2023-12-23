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

int const N = 3e5 + 5;
int const L = 20;

int n, m, k;

vii g[N];

int lk[N];
int find(int v){return lk[v] = (lk[v] == v? v: find(lk[v]));}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	lk[a] = b;
	return true;
}

int h[N], p[N][L], f[N];

void DFS(int v){
	for (auto u: g[v]) if (u.st != p[v][0]){
		h[u.st] = h[v] + 1;
		p[u.st][0] = v;
		for (int i = 1; i < L; i++)
			p[u.st][i] = p[p[u.st][i - 1]][i - 1];
		DFS(u.st);
	}
}

int LCA(int a, int b){
	if (h[a] > h[b]) swap(a, b);
	int k = h[b] - h[a];
	for (int i = 0; i <= (int)log2(k); i++) if (k & (1 << i))	
		b = p[b][i];
	if (a == b) return a;
	for (int i = log2(h[a]); i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	return p[a][0];
}

bool ans[N];

void calc(int v){
	for (auto u: g[v]) if (u.st != p[v][0]){
		calc(u.st);
		if (f[u.st] > 0)
			ans[u.nd] = 1;
		f[v] += f[u.st];
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n >> m >> k;
	
	iota(lk + 1, lk + n + 1, 1);
	
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		if (unite(x, y)){
			g[x].pb({y, i});
			g[y].pb({x, i});	
		}
	}
	
	DFS(1);
	
	while (k--){
		int x, y; cin >> x >> y;
		int anc = LCA(x, y);
		f[x] ++;
		f[y] ++;
		f[anc] -= 2;
	}
	
	calc(1);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!