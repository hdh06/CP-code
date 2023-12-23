//http://www.usaco.org/index.php?page=viewproblem2&cpid=644

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
#define file "closing"

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

int const N = 3001;

int n, m;
vi g[N];

bool isOpen[N];
bool vis[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) if (isOpen[u])
		DFS(u);
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(isOpen, 1, sizeof isOpen);
	
	for (int k = 1; k <= n; k++){
		int x; cin >> x;
		
		memset(vis, 0, sizeof vis);
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (isOpen[i] && !vis[i]){
			DFS(i);
			cnt++;
		}
		cout << (cnt == 1? "YES\n": "NO\n");
		isOpen[x] = 0;
	}
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