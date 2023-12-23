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

int const N = 1e5 + 1;

int n, m;
vi g[N];

int c[N];

int f[N];

void DFS(int v){
	if (f[v] != -1) return;
	f[v] = 0;
	if (c[v] % 2 == 0)
		return;
	
	if (g[v].size() == 0) return;
	vi z;
	for (auto u: g[v]){
		DFS(u);
		z.pb(f[u]);
	}
	
	sort(all(z));
	for (auto x: g[v]) if (x == f[v]) f[v]++;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
		cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
	}
	
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	memset(f, -1, sizeof f);
	
	for (int i = 1; i <= n; i++)
		DFS(i);
	
	int sxor = 0;
	for (int i = 1; i <= n; i++) sxor ^= f[i];
	if (sxor) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!