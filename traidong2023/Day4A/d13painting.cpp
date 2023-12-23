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

int const N = 51;

int k, n, s;

namespace sub1{
	int const N = 105;
	vi g[N];
	int cap[N][N], flow[N][N];
	int level[N], par[N], nxt[N];
	
	bool bfs(int s, int t){
		memset(level, 0, sizeof level);
		queue<int> que;
		que.push(s);
		while (!que.empty()){
			int v = que.front();
			que.pop();
			for (auto u: g[v]) if (cap[v][u] - flow[v][u] > 0 && !level[u] && u != s)
				que.push(u), level[u] = level[v] + 1;
		}
		return !!level[t];
	}
	
	int dfs(int v, int minn, int t){
		if (v == t) return minn;
		
		for (int &i = nxt[v]; i < g[v].size(); i++){
			int u = g[v][i];
			if (level[u] != level[v] + 1 || cap[v][u] - flow[v][u] == 0)
				continue;
				
			int ans = dfs(u, min(minn, cap[v][u] - flow[v][u]), t);
			if (!ans) continue;
			flow[v][u] += ans;
			flow[u][v] -= ans;
			return ans;
		}
		return 0;
	}
	
	int calc(int s, int t){
		int max_flow = 0;
		while (bfs(s, t)){
			memset(nxt, 0, sizeof nxt);
			while (int ans = dfs(s, INT_MAX, t)) max_flow += ans;
		}
		return max_flow;
	}
	
	void solve(){
		for (int i = 1; i <= s; i++){
			int x, y; cin >> x >> y;
			cap[x][y + n] ++;
			g[x].pb(y + n);
			g[y + n].pb(x);
		}
		
		for (int i = 1; i <= n; i++){
			cap[0][i]++;
			g[0].pb(i);
			g[i].pb(0);
			
			cap[i + n][2 * n + 1]++;
			g[i + n].pb(2 * n + 1);
			g[2 * n + 1].pb(i + n);
		}
		
		cout << calc(0, 2 * n + 1) << "\n";
	}
}

namespace sub2{
	int const N = 51;
	int dp[N][N][N][N];
	int psum[N][N];
	bool a[N][N];
	
	int query(int a, int b, int c, int d){
		return psum[c][d] - psum[a - 1][d] - psum[c][b - 1] + psum[a - 1][b - 1];
	}
	
	int calc(int x, int y, int u, int v){
		if (x == u && y == v) return a[x][y];
		if (u < x || v < y) return 0;
		int &ans = dp[x][y][u][v];
		if (ans != -1) return ans;
		
		ans = max(u - x + 1, v - y + 1);
		for (int k = y; k <= v; k++)
			if (query(x, k, u, k) == 0)
				ans = min(ans, calc(x, k + 1, u, v) + calc(x, y, u, k - 1));
		for (int k = x; k <= u; k++)
			if (query(k, y, k, v) == 0)
				ans = min(ans, calc(x, y, k - 1, v) + calc(k + 1, y, u, v));
		return ans;
	}
	
	void solve(){
		int minX = INT_MAX, minY = INT_MAX;
		int maxX = 0, maxY = 0;
		for (int i = 1; i <= s; i++){
			int x, y; cin >> x >> y;
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
			a[x][y] = 1;
		}
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)	
				psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
		
		memset(dp, -1, sizeof dp);
		
		cout << calc(minX, minY, maxX, maxY);
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> k >> n >> s;

	if (k == 1) 
		sub1::solve();
	else 
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!