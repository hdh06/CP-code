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
#define file "twopaths"

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

int const N = 1e6 + 1;
int n;
int w[N];
vi g[N];

struct node{
	ll m1 = 0, m2 = 0, m3 = 0;
	node(){}
	node(ll m1, ll m2, ll m3) :m1(m1), m2(m2), m3(m3) {}
};

node f[N];
ll d[N];

void DFS(int v, int p = -1){
	f[v] = node(w[v], w[v], w[v]);
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		if (f[v].m1 < f[u].m1 + w[v]){
			f[v].m3 = f[v].m2;
			f[v].m2 = f[v].m1;
			f[v].m1 = f[u].m1 + w[v];
		}else if (f[v].m2 < f[u].m1 + w[v]){
			f[v].m3 = f[v].m2;
			f[v].m2 = f[u].m1 + w[v];
		}else if (f[v].m3 < f[u].m1 + w[v])
			f[v].m3 = f[u].m1 + w[v];
	}
}
ll out[N], in[N];

void DF2(int v, int p = -1){
	for (auto u: g[v]) if (u != p){
		d[u] = max(d[v] + w[v], (f[v].m1 == f[u].m1 + w[v]? f[v].m2: f[v].m1));
		DF2(u, v);
		in[v] = max(in[v], in[u]);
	}
	in[v] = max(in[v], f[v].m1 + f[v].m2 - w[v]);
}

void DF3(int v, int p = -1){
	ll m1 = 0, m2 = 0;
	for (auto u: g[v]) if (u != p){
		if (m1 < in[u]) m2 = m1, m1 = in[u];
		else if (m2 < in[u]) m2 = in[u];
	}
	for (auto u: g[v]) if (u != p){
		if (f[v].m1 == f[u].m1 + w[v]) out[u] = max(out[u], f[v].m2 + f[v].m3 - w[v]);
		else if (f[v].m2 == f[u].m1 + w[v]) out[u] = max(out[u], f[v].m1 + f[v].m3 - w[v]);
		else out[u] = max(out[u], f[v].m1 + f[v].m2 - w[v]);
			
		out[u] = max(out[u], (f[v].m1 == f[u].m1 + w[v]? f[v].m2: f[v].m1) + d[v]);
		
		out[u] = max(out[u], out[v]);
		out[u] = max(out[u], in[u] == m1? m2: m1);
	
		DF3(u, v);
		// in[v] = max(in[v], in[u]);
	}
	// in[v] = max(in[v], f[v].m1 + f[v].m2 - w[v]);
	
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	DFS(1);
	DF2(1);
	DF3(1);
	// debug(vi(in + 1, in + n + 1));
	// debug(vi(out + 1, out + n + 1));
	// for (int i = 1; i <= n; i++) debug(i, in[i]);
	// for (int i = 1; i <= n; i++) debug(i, out[i]);
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, out[i] + in[i]);
	
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!

/*
10
109249332 625467178 53752508 748127291 696096139 758769618 543086516 906479257 31345973 541141964 
1 2
2 3
1 4
3 5
2 6
4 7
4 8
6 9
4 10
*/