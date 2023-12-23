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
#define file "bridgepol"

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
int n;
ll h[N];
int w[N];

namespace sub1{
	int const N = 1001;
	bool vis[N][N];
	ll dp[N][N];
	
	ll calc(int i, int j){
		if (i == n) return (h[i] - h[j]) * (h[i] - h[j]);
		
		if (vis[i][j]) return dp[i][j];
		vis[i][j] = 1;
		return dp[i][j] = min(calc(i + 1, j) + w[i], calc(i + 1, i) + (h[i] - h[j]) * (h[i] - h[j]));
	}
	
	void solve(){
		cout << calc(2, 1) << "\n";	
	}
}

namespace sub2{
	bool check(){
		for (int i = 1; i <= n; i++) if (abs(w[i]) > 20) return false;
		return true;
	}
	
	int const V = 20;
	bool vis[N][41];
	ll dp[N][41];
	ll calc(int i, ll v){
		if (i == n) return (h[i] - v) * (h[i] - v);
		
		if (vis[i][v + V]) return dp[i][v + V];
		vis[i][v + V] = 1;
		return dp[i][v + V] = min(calc(i + 1, v) + w[i], calc(i + 1, h[i]) + (h[i] - v) * (h[i] - v));
	}
	
	void solve(){
		cout << calc(2, h[1]);
	}
}

namespace sub3{
	void solve(){
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> w[i];
		
	// if (n <= 1000)
		sub1::solve();
	// else if (sub2::check())
		// sub2::solve();
	// else
		// sub3::solve();
	

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!