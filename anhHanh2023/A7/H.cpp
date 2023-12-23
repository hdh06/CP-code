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
#define file "photos"

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

template<typename T> T mod(T x, T m){
	if (abs(x) < m) return x < 0? x + m: x;
	x %= m;
	return x < 0? x + m: x;
}

int const N = 1e5 + 1;
int const MOD = 998244353;

int n; ll m;
int c[N];

namespace sub1{
	void solve(){
		vi z;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				z.pb(c[i] ^ c[j]);
		sort(all(z), greater<int>());
		int ans = 0;
		for (int i = 0; i < m; i++){
			z[i] %= MOD;
			(ans += z[i]) %= MOD;
		}
		cout << ans << "\n";
	}
}

namespace sub2{
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
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
		
	if (n <= 1000)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!