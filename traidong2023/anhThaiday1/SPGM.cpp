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


int const N = 201;

int n, x, y;

vii g[2][N][N];

bool vis[2][N][N];

int DFS(int i, int j, int t){
	if (vis[t][i][j]) return 0;
	vis[t][i][j] = 1;
	if (g[t][i][j].size() == 1) return 1;
	int ans = 0;
	for (auto x: g[t][i][j])
		ans += DFS(x.st, x.nd, t ^ 1) + 1;
	return ans;
}

void solve(){
	cin >> n >> x >> y;
	for (int t = 1; t <= 1; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[t][i][j].clear();
				
	memset(vis, 0, sizeof vis);
	for (int x = 1; x <= n; x++)
		for (int y = x; y <= n; y++)
			for (int i = 1; i + i <= x + y && x + y - i <= n; i++)
				g[0][x][y].pb(mp(i, x + y - i));
	
	for (int x = 1; x <= n; x++)
		for (int y = x; y <= n; y++)
			for (int i = 1; i * i <= x * y && x * y <= n * i; i++) if (x * y % i == 0)
				g[1][x][y].pb(mp(i, x * y / i));
			
	cout << DFS(x, y, 0) << "\n";
}		

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	int t; cin >> t;
	while (t--) solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!