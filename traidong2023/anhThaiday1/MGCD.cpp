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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

ll f[N];

ll mpow(ll x, ll n, ll mod){
	if (n == 0) return 1 % mod;
	ll ans = mpow(x, n / 2, mod);
	if (n & 1) return ans * ans % mod * (x % MOD) % mod;
	return ans * ans % mod;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	int n;
	int arr[N];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n; i++)
		f[arr[i]]++;
	
	
	for (int i = 1; i < N; i++)
		for (int j = i + i; j < N; j += i)
			f[i] += f[j];
			
	// debug(vl(f + 1, f + 6 + 1));
	
	for (int i = 1; i < N; i++)
		f[i] = (mpow(2, f[i], MOD - 1) - 1 + (MOD - 1)) % (MOD - 1);
		
	for (int i = N - 1; i >= 1; i--)
		for (int j = i + i; j < N; j += i)
			f[i] = (f[i] - f[j] + MOD - 1) % (MOD - 1);
	
	ll ans = 1;
	for (int i = 1; i < N; i++)
		ans = ans * mpow(i, f[i], MOD) % MOD;
	
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!