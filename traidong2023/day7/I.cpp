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
#define file "dfs"

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

int const N = 4e5 + 1;

int n, k;
int w[N];
vi g[N];

namespace sub4{
	int f[N], sz[N];

	void DFS(int m, int v, int p = -1){
		sz[v] = 1;
		int maxx = 0, sum = 0;
		for (auto u: g[v]) if (u != p){
			DFS(m, u, v);
			sz[v] += sz[u];
			if (sz[u] == f[u]) sum += f[u];
			else maxx = max(maxx, f[u]);
		}
		f[v] = w[v] < m? 0: 1 + sum + maxx;
	}
	
	bool ok(int mid){
		// debug(mid);
		for (int i = 1; i <= n; i++) if (w[i] >= mid){
			DFS(mid, i);
			// debug(i, vi(f + 1, f + n + 1));
			if (f[i] >= k) return true;
		}
		return false;
	}
	
	void solve(){
		int ans = -1;
		for (int l = 1, r = 1e6; l <= r;){
			int mid = (l + r) >> 1;
			if (ok(mid)){
				ans = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		cout << ans << "\n";
	}
}

namespace sub5{
	int f[N], sz[N];

	void DFS(int m, int v, int p = -1){
		sz[v] = 1;
		int maxx = 0, sum = 0;
		for (auto u: g[v]) if (u != p){
			DFS(m, u, v);
			sz[v] += sz[u];
			if (sz[u] == f[u]) sum += f[u];
			else maxx = max(maxx, f[u]);
		}
		f[v] = w[v] < m? 0: 1 + sum + maxx;
	}
	
	int d[N];
	void upd(int &m1, int &m2, int x){
		if (m1 < x){
			int k = m1;
			m2 = k;
			m1 = x;
		}else if (m2 < x) m2 = x;
	}
	
	bool found;
	
	void DF2(int m, int v, int p = -1){
		if (found) return;
		int sum = 0, m1 = 0, m2 = 0;
		if (d[v] == n - sz[v]) sum = d[v]; else m1 = d[v];
		for (auto u: g[v]) if (p != u){
			if (f[u] == sz[u]) sum += f[u];
			else upd(m1, m2, f[u]);
		}
		// if (v == 5) debug(sum, m1, m2, d[v], f[v], sz[v]);
		
		if (w[v] >= m && 1 + sum + m1 >= k){
			found = 1;
			return;
		}
		
		for (auto u: g[v]) if (u != p){
			int newSum = f[u] == sz[u]? sum - f[u]: sum;
			int newMax = f[u] < sz[u] && m1 == f[u]? m2: m1;
			// if (u == 5) debug(newSum, newMax); 
			d[u] = w[v] < m? 0: 1 + newSum + newMax;
			DF2(m, u, v);
		}
		
	}
	
	bool ok(int mid){
		DFS(mid, 1);
		if (f[1] >= k) return true;
		// debug(vi(f + 1, f + n + 1));
		// debug(vi(d + 1, d + n + 1));
		// memset(d, 0, sizeof d);
		found = 0;
		DF2(mid, 1);
		return found;
	}
	
	void solve(){
		// debug(ok(10)); 
		int ans = 0;
		for (int l = 1, r = 1e6; l <= r;){
			int mid = (l + r) >> 1;
			if (ok(mid)){
				ans = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> w[i];
		
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}	
	// if (n <= 3000)
		// sub4::solve();
	// else
		sub5::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!