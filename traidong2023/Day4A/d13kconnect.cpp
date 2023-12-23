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

int n, m, k;
ii arr[N];

bool isSpc[N];

int lk[N];

vii g[N];

int find(int v){return lk[v] = lk[v] == v? v: find(lk[v]);}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	lk[a] = b;
	return true;
}

bool ans[N];

int f[N];

void DFS(int v, int p = -1){
	f[v] = isSpc[v];
	for (auto u: g[v]) if (u.st != p){
		DFS(u.st, v);
		if (0 < f[u.st] && f[u.st] < k)
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
	k *= 2;
	for (int i = 1; i <= m; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	for (int i = 1; i <= k; i++){
		int x; cin >> x;
		isSpc[x] = 1;
	}	
	
	iota(lk + 1, lk + n + 1, 1);
	
	for (int i = 1; i <= m; i++){
		if (unite(arr[i].st, arr[i].nd)){
			g[arr[i].st].pb({arr[i].nd, i});
			g[arr[i].nd].pb({arr[i].st, i});
		}
	}
	
	DFS(1);
	// debug(vi(f + 1, f + n + 1));

	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
		
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!
