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
#define file "dddd"

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

int const N = 3e5 + 1;
int const P = 30;

int n, p;
vi gp[N];

int f[N][P], g[N][P];
void DFS(int v, int par = -1){
	f[v][0] = 1;
	for (auto u: gp[v]) if (u != par){
		DFS(u, v);
		for (int i = 0; i < p; i++)
			f[v][(i + 1) % p] += f[u][i];
		
	}
}
void DF2(int v, int par = -1){
	for (auto u: gp[v]) if (u != par){
		for (int i = 0; i < p; i++){
			g[u][(i + 1) % p] += g[v][i] + f[v][i] - f[u][(i - 1 + p) % p];
			// debug(v, u, i,  g[v][i] , f[v][i] , f[u][(i - 1 + p) % p]);
		}
		DF2(u, v);
	}
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> n >> p;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		gp[a].pb(b);
		gp[b].pb(a);
	}
	
	DFS(1);
	DF2(1);
	
	// for (int i = 1; i <= n; i++) debug(i, vi(f[i], f[i] + P));
	// for (int i = 1; i <= n; i++) debug(i, vi(g[i], g[i] + P));
	
	for (int i = 1; i <= n; i++){
		cout << f[i][0] + g[i][0] << " ";
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!