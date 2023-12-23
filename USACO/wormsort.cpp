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
#define file "wormsort"

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
int pos[N];
vii g[N];

int ccid[N], id = 0;

void DFS(int v, int k){
	if (ccid[v]) return;
	ccid[v] = id;
	for (ii u: g[v]) if (u.nd >= k)
		DFS(u.st, k);
}

bool f(int k){
	memset(ccid, 0, sizeof ccid);
	id = 0;
	for (int i = 1; i <= n; i++) if (!ccid[i]){
		++id;
		DFS(i, k);
	}
	
	
	for (int i = 1; i <= n; i++)
		if (ccid[i] != ccid[pos[i]]) return false;
	return true;
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		pos[x] = i;
	}
	for (int i = 1; i <= m; i++){
		int a, b, w; cin >> a >> b >> w;
		g[a].pb({b, w});
		g[b].pb({a, w});	
	}
	
	int ans = -1;
	for (int l = 1, r = 1e9 + 1; l <= r;){
		int mid = l + (r - l) / 2;
		if (f(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << (ans == 1e9 + 1? -1: ans);
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