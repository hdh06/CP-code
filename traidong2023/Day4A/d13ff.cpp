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

bool const SINGLE_TEST = 1;

int const N = 1e4 + 1;
// ll const INF = 1e16;

int n, m;
int v[N];

ll dp[N][101];

void minimize(ll &x, ll v){
	if (x == -1 || x > v) x = v; 
}

void solve(){	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
		
	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			dp[j][j - i] = v[i] + v[j];
			
	for (int i = m + 1; i <= n; i++)
		for (int p = i - m + 1; p < i; p++)
			for (int k = i - m; k < p; k++)
				minimize(dp[i][i - p], dp[p][p - k] + v[i]);
			
	ll ans = -1;
	for (int p = n - m + 1; p <= n; p++)
		for (int i = p + 1; i <= n; i++)
			minimize(ans, dp[i][i - p]);
			
	cout << ans;
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