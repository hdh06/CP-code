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

int const N = 205;

int n;
int arr[N][N];

bool row[N];
bool col[N];

int crow[N];
int ccol[N];


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

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	vii z;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (arr[i][j] == 1){
			cap[i][j + n]++;
			g[i].pb(j + n);
			g[j + n].pb(i);
		}
		
	for (int i = 1; i <= n; i++){
		cap[0][i]++, cap[i + n][2 * n + 1]++;
		g[0].pb(i);
		g[i].pb(0);
		g[i + n].pb(2 * n + 1);
		g[2 * n + 1].pb(i + n);
	}
	
	calc(0, 2 * n + 1);
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) if (flow[i][j + n] == 1){
			z.pb({i, j});
		}
		
	for (int i = 1; i <= n; i++)
		crow[i] = ccol[i] = i;
		
	// debug(z);
		
	if (z.size() < n){
		cout << -1;
	}else{
		sort(all(z));
		vector<iii> ans;
		for (int i = 1; i <= n; i++){
			ans.pb({1, crow[z[i - 1].st], i});
			for (int k = 1; k <= n; k++) if (crow[k] == i){
				swap(crow[z[i - 1].st], crow[k]);
				break;
			}
			ans.pb({2, ccol[z[i - 1].nd], i});
			for (int k = 1; k <= n; k++) if (ccol[k] == i){
				swap(ccol[z[i - 1].nd], ccol[k]);
				break;
			}
		}
		
		cout << ans.size() << "\n";
		for (auto x: ans) cout << x[0] << ' ' << x[1] << " " << x[2] << "\n";
	}
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!