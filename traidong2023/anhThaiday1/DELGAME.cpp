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

int n, m, k;
vi g[N];


namespace sub3{
	int vis[N], cnt = 0;
	void DFS(int v){
		vis[v] = cnt;
		for (auto u: g[v]) if (!vis[u])
			DFS(u);
	}
	
	int ans[N], sz[N];
	
	void solve(){	
		memset(vis, 0, sizeof vis);
		cnt = 0;
		for (int i = 1; i <= n; i++) if (!vis[i]){
			cnt++;
			DFS(i);	
		}
		
		
		for (int i = 1; i <= n; i++){
			ans[vis[i]] += g[i].size();	
			sz[vis[i]]++;
		}
		int sxor = 0;
		for (int i = 1; i <= cnt; i++){
			sxor ^= ans[i] / 2 - sz[i] + 1;
		}
		
		cout << !!sxor << "\n";
	}
}

namespace sub2{
	int vis[N], cnt = 0;
	void DFS(int v){
		vis[v] = cnt;
		for (auto u: g[v]) if (!vis[u])
			DFS(u);
	}
	
	int ans[N], sz[N];
	
	void solve(){	
		memset(vis, 0, sizeof vis);
		memset(ans, 0, sizeof ans);
		memset(sz, 0, sizeof vis);
		cnt = 0;
		for (int i = 1; i <= n; i++) if (!vis[i]){
			cnt++;
			DFS(i);	
		}
		
		
		for (int i = 1; i <= n; i++){
			ans[vis[i]] += g[i].size();	
			sz[vis[i]]++;
		}
		int sxor = 0;
		for (int i = 1; i <= cnt; i++){
			// debug(ans[i], sz[i]);
			sxor ^= (ans[i] / 2 - sz[i] + 1) % (k + 1);
		}
		
		cout << !!sxor << "\n";
		// debug(".");
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	int t = 4;
	while (t--){
		cin >> n >> m >> k;
		// if (n == 4 && m == 6 && k == 2){
			// cout << "0\n1\n0\n0";
			// return 0;
		// }
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= m; i++){
			int a, b; cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		
		sub2::solve();
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!