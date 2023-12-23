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
#define file "lightson"

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

bool const SINGLE_TEST = 1;

int const N = 101;

int const dx[] = {0, 0, -1, 1};
int const dy[] = {1, -1, 0, 0};

int n, m;

vii g[N][N], rg[N][N];

bool vis[N][N], isOn[N][N];

void DFS(int x, int y){
	if (vis[x][y]) return;
	vis[x][y] = 1;
	for (auto p: g[x][y]){
		isOn[p.st][p.nd] = 1;
		bool fl = 0;
		for (int d = 0; d < 4; d++){
			int g = p.st + dx[d], h = p.nd + dy[d];
			if (g < 1 || h < 1 || g > n || h > n) continue;
			if (vis[g][h]) fl = 1;
		}
		if (fl)
			DFS(p.st, p.nd);
	}
	for (int d = 0; d < 4; d++){
		int g = x + dx[d], h = y + dy[d];
		if (g < 1 || h < 1 || g > n || h > n || !isOn[g][h]) continue;
		DFS(g, h);
	}
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, a, b; cin >> x >> y >> a >> b;
		g[x][y].pb({a, b});

	}
	
	isOn[1][1] = 1;
	DFS(1, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += isOn[i][j];
	
	// for (int i = 1; i <= n; i++)
		// for (int j = 1; j <= n; j++)
			// cerr << isOn[i][j] << " \n"[j == n];
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef LOCAL
		cerr << "funnyline\n";
	#else
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!