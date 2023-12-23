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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

bool const SINGLE_TEST = 1;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;
int n;
int c[N];

int dp[N];

void solve(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
		
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		int g = 0;
		for (int j = i; j >= 1; j--){
			g = gcd(g, c[j]);
			if (g > 1) (dp[i] += dp[j - 1]) %= MOD;
		}
	}
	cout << dp[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!