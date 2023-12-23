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

int const N = 1005;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {-1, 1, 0, 0};

int n, m;
char arr[N][N];

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

int key[N][N];

bool vis[2 * N];

int DFS(int v, bool z, int k){
	if (vis[v]) return 0;
	vis[v] = 1;
	int ans = 0;
	if (k < v && v <= 2 * k) ans++;
	for (auto u: g[v])
		if ( !(z ^ max(flow[v][u], flow[u][v]))
			ans += DFS(v, z ^ 1, k);
			
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
			
	int id1 = 0, id2 = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) if (arr[i][j] != '#'){
			if ((i + j) % 2 == 0) key[i][j] = ++id1;
			else key[i][j] = ++id2;
		}
		
	}

	int k = id1;
	
	ll ans = 1LL * k * (k - 1);
	if (ans >= 1000000){
		cout << ans;
		return 0;
	}
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			for (int d = 0; d < 4; d++){
				int gg = i + dx[d], h = j + dy[d];
				if (gg < 1 || gg > n || h < 1 || h > m) continue;
				// cap[key[i][j]][key[gg][h] + k] ++;
				g[key[i][j]].pb(key[gg][h] + k);
				g[key[gg][h] + k].pb(key[i][j]);
			}
		}
		
	
		
	// for (int i = 1; i <= k; i++){
		// cap[0][i]++;	
		// g[i].pb(0);
		// g[0].pb(i);
// 		
		// cap[i + k][2 * k + 1]++;
		// g[i + k].pb(2 * k + 1);
		// g[2 * k + 1].pb(i + k);
	// }
// 
	
	// calc(0, 2 * k + 1);
	
	// debug(k);
	
	// for (int i = 1; i <= k; i++){
		// memset(vis, 0, sizeof vis);
		// ans += DFS(i, 1, k);
	// }
// 	
	// cout << min(ans, 1000000LL);
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!