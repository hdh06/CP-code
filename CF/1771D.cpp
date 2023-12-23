#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int const N = 2e3 + 1;

int n;
string s;
vi g[N];

int p[N][N];
void DFS(int v, int par, int root){
	for (auto u: g[v]) if (par != u){
		p[u][root] = v; 
		DFS(u, v, root);
	}
}

int dp[N][N];
int calc(int a, int b){
	if (a == b) return 1;
	if (s[a] == s[b] && p[a][b] == b && p[b][a] == a) return 2;
	int &ans = dp[a][b];
	if (ans != -1) return dp[a][b];
	ans = 0;
	if (s[a] == s[b])
		ans = max(ans, calc(p[a][b], p[b][a]) + 2);
	ans = max({ans, calc(p[a][b], b), calc(a, p[b][a])});
	return ans;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for (int i = 1; i <= n; i++)
		DFS(i, 0, i);
	
	int ans = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			ans = max(ans, calc(i, j));
		}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!