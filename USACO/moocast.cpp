//http://www.usaco.org/index.php?page=viewproblem2&cpid=668

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

int const N = 201;

struct cow{
	int x, y, p;
	cow(){}
	cow(int x, int y, int p) :x(x), y(y), p(p) {}
};

ll dis2(cow A, cow B){
	return 1LL * (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);
}

int n;
vi g[N];
vector<cow> cowl;

bool vis[N];

void DFS(int v){
	if (vis[v]) return;
	vis[v] = 1;
	for (auto u: g[v])
		DFS(u);
}

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, y, p; cin >> x >> y >> p;
		cowl.pb(cow(x, y, p));
	}	
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			if (cowl[i].p * cowl[i].p >= dis2(cowl[i], cowl[j]))
				g[i].pb(j);
			if (cowl[j].p * cowl[j].p >= dis2(cowl[i], cowl[j]))
				g[j].pb(i);	
		}
		
	int ans = 0;
	for (int i = 0; i < n; i++){
		memset(vis, 0, sizeof vis);
		DFS(i);
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += vis[i];
		ans = max(ans, cnt);
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