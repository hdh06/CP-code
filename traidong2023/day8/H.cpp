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
#define file "tree-distance"

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

int const N = 3e5 + 1;

int sub;
int n, k;
vi g[N];

int ins[N], out[N], id = 0, nid[N];
int h[N];

int cnt[N];
ll ans = 0;
void DFS(int v, int p = -1){
	ins[v] = ++id;
	for (auto u: g[v]) if (u != p){
		h[u] = h[v] + 1;
		DFS(u, v);
	}
	out[v] = id;
}

void calc(int v, int p = -1){
	int maxU = 0;
	for (auto u: g[v]) if (u != p && out[u] - ins[u] >= out[maxU] - ins[maxU])
		maxU = u;

	int s = 2 * h[v] + k;
	if (maxU == 0){
		cnt[h[v]]++;
		ans += cnt[s - h[v]];
		return;
	}
	
	for (auto u: g[v]) if (u != p && u != maxU){
		calc(u, v);
		for (int i = ins[u]; i <= out[u]; i++)
			cnt[h[nid[i]]]--;
	}
	calc(maxU, v);
	
	for (auto u: g[v]) if (u != p && u != maxU){
		for (int i = ins[u]; i <= out[u]; i++) if (s >= h[nid[i]]) ans += cnt[s - h[nid[i]]];
		for (int i = ins[u]; i <= out[u]; i++) cnt[h[nid[i]]]++;
	}
	cnt[h[v]]++;
	ans += cnt[s - h[v]];
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> sub >> n >> k;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}	
	
	DFS(1);
	for (int i = 1; i <= n; i++)
		nid[ins[i]] = i;
		
	debug(vi(ins + 1, ins + n + 1));
	
	calc(1);
	if (sub == 2) cout << n - k;
	else	
		cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!