//http://www.usaco.org/index.php?page=viewproblem2&cpid=669

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
#define file "moocast"

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

int const N = 1001;

int n, m;

ii pos[N];
vi g[N];

int dis2(ii A, ii B){
	return (A.st - B.st) * (A.st - B.st) + (A.nd - B.nd) * (A.nd - B.nd);
}

bool vis[N];
void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v]) DFS(u);
}

bool f(int k){
	for (int i = 1; i <= n; i++)
		g[i].clear();
		
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (dis2(pos[i], pos[j]) <= k)
				g[i].pb(j), g[j].pb(i);
		}
	}
	
	memset(vis, 0, sizeof vis);
	DFS(1);
	for (int i = 1; i <= n; i++) if (!vis[i])
		return false;
	
	return true;
}


void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> pos[i].st >> pos[i].nd;
		
	int ans = -1;
	for (int l = 0, r = 2e9; l <= r;){
		int mid = l + (r - l) / 2;
		
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	
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