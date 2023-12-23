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

vii g[N], rg[N];

namespace sub12{	
	bool check(){
		for (int i = 1; i <= n; i++){
			sort(all(g[i]));
			g[i].erase(unique(all(g[i])), g[i].end());
			if (g[i].size() & 1) return false;
			for (int j = 0; j < n; j += 2){
				if (g[i][j].st != g[i][j + 1].st || g[i][j].nd == g[i][j].nd)
					return false;
			}
		}
		return true;
	}
	vi ord;
	bool vis[N];
	void DFS(int v){
		if (vis[v]) return ;
		vis[v] = 1;
		for (auto u: g[v])
			DFS(u.st);
		ord.pb(v);
	}
	
	int ccid[N], id = 0;
	void KRJ(int v){
		if (ccid[v]) return;
		ccid[v] = id;
		for (auto u: rg[v])
			KRJ(u.st);
	}

	void solve(){
		for (int i = 1; i <= n; i++)
			DFS(i);
			
		reverse(all(ord));
		
		for (auto x: ord) if (!ccid[x]){
			id++;
			KRJ(x);
		
		}
		
		int cnt[N] = {};
		for (int i = 1; i <= n; i++)
			cnt[ccid[i]] ++;
			
		// debug(vi(ccid + 1, ccid + n + 1));
		// debug(vi(cnt + 1, cnt + id + 1));
		
		int ans[N] = {};
		
		reverse(all(ord));
		// debug(ord);
		
		for (auto x: ord){
			if (cnt[ccid[x]] > 1) ans[x] = -1;
			else{
				for (auto u: g[x]){
					if (ans[u.st] == -1) ans[x] = -1;
					if (ans[x] != -1 && ans[u.st] != -1)
						ans[x] = max(ans[x], ans[u.st] + 1);
					// debug(x, u.st, ans[x]);
				}
			}
		}
		
		for (int i = 1; i <= n; i++)
			cout << ans[i] << "\n";	
	}	
}

namespace sub4{
	int f[N][3];
	int vis[N][3];
	
	int check(int u, int c){
		if (f[u][c] > -1) return f[u][c];
		
		if (vis[u][c] == 1) return f[u][c] = 1;
		vis[u][c] = 1;
		for (auto v: g[u]) if (v.nd != c){
			if (check(v.st, v.nd) == 1)
				return f[u][c] = 1;
		}
		vis[u][c] = 2;
		return f[u][c] = 0;
	}
	
	int dp[N][3];

	int DFS(int v, int c){
		int &ans = dp[v][c];
		if (ans != -1) return ans;
		ans = 0;
		for (auto u: g[v]) if (u.nd != c)
			ans = max(ans, DFS(u.st, u.nd) + 1);
		
		return ans;
	}
	
	void solve(){
		memset(dp, -1, sizeof dp);
		memset(f, -1, sizeof f);
		
		for (int i = 1; i <= n; i++){
			if (check(i, 1) == 1 || check(i, 2) == 1){
				cout << -1 << "\n";
			}else cout << max(DFS(i, 1), DFS(i, 2)) << "\n";
		}
	}
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
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb({b, c});
		rg[b].pb({a, c});
	}
	
	// if (sub12::check())
		// sub12::solve();
	// else
		sub4::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!