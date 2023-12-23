//http://www.usaco.org/index.php?page=viewproblem2&cpid=944

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
#define file "fenceplan"

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

int const N = 1e5 + 1;

int n, m;
int Cx[N], Cy[N];

vi g[N];

int ccid[N], id = 0;

int maxCx[N], minCx[N], maxCy[N], minCy[N];

void DFS(int v){
	if (ccid[v]) return;
	ccid[v] = id;
	for (auto u: g[v]) DFS(u);
}
void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> Cx[i] >> Cy[i];
	
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for (int i = 1; i <= n; i++) if (!ccid[i]){
		id++;
		DFS(i);
	}
	
	fill(minCx, minCx + N, INT_MAX);
	fill(minCy, minCy + N, INT_MAX);
	
	for (int i = 1; i <= n; i++){
		maxCx[ccid[i]] = max(maxCx[ccid[i]], Cx[i]);
		minCx[ccid[i]] = min(minCx[ccid[i]], Cx[i]);
		maxCy[ccid[i]] = max(maxCy[ccid[i]], Cy[i]);
		minCy[ccid[i]] = min(minCy[ccid[i]], Cy[i]);
	}
	
	int ans = INT_MAX;
	for (int i = 1; i <= id; i++)
		ans = min(ans, 2 * (maxCx[i] - minCx[i] + maxCy[i] - minCy[i]));
	
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!