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
#define file "topo"

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

int const N = 4001;
int const MOD = 998244353;

int sub;
int n;
vi g[N];

namespace sub1{
	int p[N];
	void solve(){
		iota(p + 1, p + n + 1, 1);
		int ans = 0;
		do{
			bool check = 1;
			vb vis(n + 1, 0);
			for (int i = 1; i <= n; i++){
				for (auto u: g[p[i]]) if (vis[u])
					check = 0;
				vis[p[i]] = 1;
			}
			ans += check;
		}while (next_permutation(p + 1, p + n + 1));
		cout << ans << "\n";
	}
}

// namespace sub2{
	// int const N = 20;
	// int dp[N][1 << N];
	// int calc(int v, int mask){
		// if (mask == (1 << n) - 1) return 1;
		// int &ans = dp[v][mask];
		// if (ans != -1) return ans;
		// ans = 0;
// 		
		// for (int i = 1; i <= n; i++) if (~mask & (1 << (i - 1))){
			// bool check = true;
			// for (auto u: g[v]) if (mask & (1 << (u - 1))) check = 0;
			// if (check)
				// (ans += calc(v + 1, mask | 1 << (i - 1))) %= MOD;	
		// } 
		// return ans;
	// }
// 
	// void solve(){
		// cout << calc(1, 0);
	// }
// }


namespace sub3{
	int fact[N];
	void init(){
		fact[0] = 1;
		for (int i = 1; i < N; i++)
			fact[i] = 1LL * fact[i - 1] * i % MOD;
	}
	int cnt[N];
	
	void solve(){
		init();		
		for (int i = 1; i <= n; i++) for (auto u: g[i]) cnt[u]++;
		int ans = 1;
		for (int i = 1; i <= n; i++) ans = 1LL * ans * fact[cnt[i]] % MOD;
		cout << ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	cin >> sub;
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
	}
	
	if (sub == 1)
		// sub1::solve();
	// else if (sub == 2)
		// sub2::solve();
	// else if (sub == 3)
		sub3::solve();
		
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!