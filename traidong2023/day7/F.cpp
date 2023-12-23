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
#define file "colors"

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
int const MOD = 998244353;

int t; 

int n, c;
vi g[N];

int dp[N];
int DFS(int v, int p = -1){
	if (v != 1)
		dp[v] = (c - 1) % MOD;
	else dp[v] = c % MOD;
	for (auto u: g[v]) if (u != p){
		DFS(u, v);
		dp[v] = 1LL * dp[v] * dp[u] % MOD;
	} 
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> t;
	cin >> n >> c;
	for (int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		g[x].pb(y);	
		g[y].pb(x);
	}
	
	DFS(1);
	
	cout << dp[1];
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!