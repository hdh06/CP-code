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
#define file "fiel"

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

bool const SINGLE_TEST = 0;

int const N = 1e5 + 1;

int n, m;
int a, b, c;
vi g[N];

namespace sub1{
	int ssz[N];
	void DFS(int v, int p = -1){
		for (auto u: g[v]) if (u != p){
			DFS(u, v);
			ssz[v] += ssz[u];
		}
		ssz[v]++;
	}
	
	int clr[N];
	
	void tomau(int v, int c, int p = -1){
		clr[v] = c;
		for (auto u: g[v]) if (u != p) tomau(u, c, v);
	}
	
	void mark(int v, int need, int c, int p = -1){
		if (need){
			need--;
			clr[v] = c;
		}
		for (auto u: g[v]) if (u != p){
			if (ssz[u] > need){
				mark(u, need, c, v);
				return;
			}	
			tomau(u, c);
			need -= ssz[u];
		}
	}
	
	void solve(){
		mark(1, a, 1);
		int maxU = 0;
		for (int i = 1; i <= n; i++) if (!clr[i])
			if (ssz[maxU] < ssz[i]) maxU = i;
		
		mark(maxU, b, 2);
		
		for (int i = 1; i <= n; i++) if (!clr[i]) clr[i] = 3;
		
		int cnt_a = 0, cnt_b = 0, cnt_c = 0;
		for (int i = 1; i <= n; i++){
			if (clr[i] == 1) cnt_a++;
			if (clr[i] == 2) cnt_b++;
			if (clr[i] == 3) cnt_c++;
		}
		if (cnt_a == a && cnt_b == b && cnt_c == c){
			for (int i = 1; i <= n; i++)
				cout << clr[i] << " ";
		}else for (int i = 1; i <= n; i++)
			cout << 0 << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin >> n >> m;
	cin >> a >> b >> c;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		a++, b++;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	if (m == n - 1)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!