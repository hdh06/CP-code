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

int const N = 1e5 + 1;

int n, m;
vii g[N];

int ccid[N], id = 0;
int cntId[N];
int ans[N];

void mark_red(int v){
	if (ccid[v]) return;
	ccid[v] = id;
	for (auto u: g[v]) if (u.nd == 1)
		mark_red(u.st);
}


int Link[N];

int find(int v){return Link[v] = Link[v] == v? v: find(Link[v]);}

bool unite(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return false;
	Link[a] = b;
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> m;
	
	for (int i = 1; i <= m; i++){
		int x, y, c; cin >> x >> y >> c;
		g[x].pb({y, c});
		g[y].pb({x, c});
	}	
	
	for (int i = 1; i <= n; i++) if (!ccid[i]){
		id++;
		mark_red(i);
	}
	
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (auto u: g[i]) if (u.nd == 1)
			cnt++;
		if (cnt & 1) ans[ccid[i]] ++;
		cntId[ccid[i]]++;
	
	}

	iota(Link + 1, Link + n + 1, 1);
	
	for (int v = 1; v <= n; v++)
		for (auto u: g[v]) if (u.nd == 1)
			unite(ccid[u.st], ccid[v]);
	
	int sum[N] = {};
	
	for (int i = 1; i <= id; i++){
		int z = find(i);
		sum[z] += ans[i] / 2;
	}
	
	int res = 0;	
	for (int i = 1; i <= id; i++){
		int z = find(i);
		if (cntId[z] > 1 && sum[z] == 0) sum[z] = 1;
		res += sum[z];
	}
	
	cout << res;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!